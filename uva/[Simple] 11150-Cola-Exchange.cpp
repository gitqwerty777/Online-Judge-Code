#include <stdio.h>

int ans[201] = {0};
void Make_Ans(){
  ans[1] = 1;
  ans[2] = 3;
  for(int i = 3; i < 201; i++){
    int a = (i%2)?1:2;
    ans[i] = ans[i-1] + a;
  }
}

int main(){
  int N;
  Make_Ans();

  while(scanf("%d", &N) == 1){
    printf("%d\n", ans[N]);
  }
  return 0;
}