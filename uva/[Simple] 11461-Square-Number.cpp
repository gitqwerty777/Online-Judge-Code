#include <stdio.h>

int sq[100001];
void Make_Square(){
  int count = 0;
  for(int i = 0; i < 318; i++){//square root of (100000)
    while(count < 100001 && count < i*i){
      sq[count++] = i+1;
    }
  }
}

int main(){
  int lo, hi;
  Make_Square();
  while(scanf("%d %d", &lo, &hi) == 2 && lo+hi){
    if(lo)
      printf("%d\n", sq[hi] - sq[lo-1]);
    else//lo == 0
      printf("%d\n", sq[hi] - sq[lo] + 1);      
  }
  return 0;
}