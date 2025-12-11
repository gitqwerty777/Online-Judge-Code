#include <stdio.h>

int main(){
  char in[16];
  while(gets(in) != NULL){
    if(in[0] == '|'){
      int base = 0;
      for(int i = 2; i < 10; i++){
	if(in[i] == 'o'){
	  base *= 2;
	  base++;
	} else if(in[i] == ' '){
	  base *= 2;
	}
      }
      putchar(base);
    }
  }
  return 0;
}