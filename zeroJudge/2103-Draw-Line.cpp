#include <stdio.h>
#include <string.h>

char s[1000004];
int main(){
  int T;
  int ans;
  scanf("%d", &T);
  gets(s);
  while(T--){
    gets(s);
    int l = strlen(s);
    ans = 0;
    if(l > 10){//speed up
      //12 and 1
      if(s[0] == s[l-1])
	ans++;
      if(s[0] == s[l-2] && s[1] == s[l-1])
	ans++;
      //剛好三個?
      char end[4];
      end[0] = s[l-3];
      end[1] = s[l-2];
      end[2] = s[l-1];
      end[3] = '\0';
      char* p = s;
      while((p = strstr(p+1, end)) != NULL){
	bool isans = true;
	if(p == &s[l-3])
	  break;
	char* tempp = p;
	char* st = &s[0];
	char* en = &s[l-3];
	while(tempp != st){
	  if(*en != *tempp){
	    isans = false;
	    break;
	  }
	  en--; tempp--;
	}
	if(isans)
	  ans++;
      }
    } else {
      for(int i = l-1; i > 0 ;i--){
	bool isans = true;
	int jmax = l - i;
	for(int j = 0; j < jmax; j++)
	  if(s[j] != s[j+i]){
	    isans = false;
	    break;
	  }
	if(isans)
	  ans++;
      }
    }
    printf("%d\n", ans);
  }  
  return 0;
}
