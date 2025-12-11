#include <stdio.h>
#include <string.h>

int I;
int II;
int v = 0;
char s[128];

inline void getI(){
  memset(s, '\0', 128);
  int count = 0;
  v = 0;
  II = I;
  while(II>0){
    s[count++] = '0'+ II%2;
    v += II%2;
    II /= 2;
  }
  int size = strlen(s);
  for(int i = 0; i < (size+1)/2; i++){
    int tmp = s[i];
    s[i] = s[size-1-i];
    s[size-1-i] = tmp;
  }
  s[size] = '\0';
}

int main(){
  while(scanf("%d", &I) == 1 && I){
    getI();
    printf("The parity of %s is %d (mod 2).\n", s, v);
  }
  return 0;
}
