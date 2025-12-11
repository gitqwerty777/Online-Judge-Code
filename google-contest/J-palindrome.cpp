#include <stdio.h>
#include <string.h>
char s[100004];
int l;

bool check_palindrome(int st, int ed){
  if(st == ed){
    return true;
  } else {
    int len = (ed-st)/2;//half
    for(int i = 0;i <= len; i++){
      if(s[st+i] != s[ed-i]){
	return false;
      }
    }
    return true;
  }
}
bool check_ans(int &s){
  return check_palindrome(0, s) && check_palindrome(s+1, l);
}
int alpha[26] = {0};
int skiplen = 1;
bool check_false(){
  memset(alpha, 0, sizeof(alpha));
  for(int i = 0; i <= l; i++){
    alpha[s[i]-'a']++;
  }
  int count = 0;
  for(int i = 0; i < 26; i++){
    if(alpha[i]%2){
      count++;
    }
  }
  /*討論：
    若長度為偶，則奇數個數可能為0，2
    若為2，則兩palindrome為奇+奇
    若長度為奇，則奇數個數可能為0，1
    若為1，則兩palindrome為奇+偶
    奇數個數最多為3
   */
  skiplen = 1;
  if(count > 3){
    return true;
  }
  if(((l+1) % 2 && count <= 1) || ((l+1) % 2 == 0 && count % 2 == 0)){
        if((l+1) % 2 == 0 && count == 2)
          skiplen = 2;
    return false;
  } else
    return true;
}

int main(){
  bool isans = false;
  char st, ed;
  while(gets(s)){
    isans = false;
    l = strlen(s)-1;
    if(!check_false()){    //use some fast check of false result
      st = s[0]; ed = s[l];
      for(int i = 0;i < l; i += skiplen)
	if(st == s[i] && ed == s[i+1] && check_ans(i)){
	  isans = true;
	  break;
	}
    }
    if(isans)
      puts("www");
    else
      puts("vvvvvv");
  }
  return 0;
}
