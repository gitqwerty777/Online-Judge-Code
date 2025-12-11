#include <stdio.h>

long double H, U, D, F;

int main(){
  int day; bool success;
  while(scanf("%Lf%Lf%Lf%Lf", &H, &U, &D, &F) == 4 && H+U+D+F){
    success = false;
    day = 1;
    long double nowh = 0.0, nowu = U, nowd = U/100.0L*F;//nowd is fixed...
    while(1){
      nowh += nowu;
      if(nowu > nowd)
	nowu -= nowd;
      else nowu = 0;
      if(nowh > H){
	success = true; break;
      }
      nowh -= D;
      if(nowh < 0){
	break;
      }
      day++;
    }
    printf("%s on day %d\n", success?"success":"failure", day);
  }
}
