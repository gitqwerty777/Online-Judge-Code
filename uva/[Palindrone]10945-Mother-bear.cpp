#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[10000];
int len;

void trim(){
  len = strlen(s);
  int nowi = 0;
  for(int i = 0; i < len; i++)
    if(isalpha(s[i]))
      s[nowi++] = tolower(s[i]);
  s[nowi] = '\0';
}

inline bool isPalinDrone(){
  trim();
  len = strlen(s);
  for(int i = 0; i < (len+1)/2; i++)
    if(s[i] != s[len-1-i])
      return false;
  return true;
}

int main(){
  while(gets(s)){
    if(strcmp("DONE", s) == 0)
      break;
    printf("%s\n", isPalinDrone()?"You won't be eaten!":"Uh oh..");
  }
}
