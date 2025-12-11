#include <stdio.h>

int N;
int ans[101];

int main(){
  ans[1] = 1;
  ans[2] = 5;
  for(int i = 3; i <= 100; i++){
    ans[i] = ans[i-1]+ i*i;
  }
  while(scanf("%d", &N) == 1 && N){
    printf("%d\n", ans[N]);
  }
}
