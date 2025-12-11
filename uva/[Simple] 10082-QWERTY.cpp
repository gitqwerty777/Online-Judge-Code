#include <stdio.h>
#include <string.h>

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main(){
  char in[10000] = "";
  char* sindex;
  while(gets(in)){
    int len = strlen(in);
    for(int i = 0; i < len; i++){
      //      if(in[i] == ' ' || in[i] == '\n'){
      //	continue;
      //      }
      if((sindex = strchr(s, in[i])) != NULL){
	in[i] = *(sindex-1);//VERY dangerous
      }
    }
    puts(in);
  }
  return 0;
}