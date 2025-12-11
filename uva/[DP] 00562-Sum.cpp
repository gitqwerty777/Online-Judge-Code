#include <stdio.h>
#include <string.h>

int T, N;
int dp[50004];// max = 500cent * 100
int arr[104];
int sum;

void dps(){
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for(int i = 0; i < N; i++){
    for(int j = sum-1; j >= 0; j--){
      if(j-arr[i] >= 0)
	dp[j] += dp[j-arr[i]];
    }
  }
}

inline int abs(int a){
  if(a < 0)
    return -a;
  else
    return a;
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    if(N == 0){//n = 0, weird...
      puts("0");
      continue;
    }
    sum = 0;
    for(int i = 0; i < N; i++){
      scanf("%d", &arr[i]);
      sum += arr[i];
    }
    dps();
    int ansi; //ans index
    int d = sum/2;
    while(d >= 0){
      if(dp[d]){
	ansi = d;
	break;
      }
      d--;
    }
    //    printf("sum = %d, ansi = %d\n", sum, ansi);
    printf("%d\n", abs(ansi-(sum-ansi)));
  }
  return 0;
}