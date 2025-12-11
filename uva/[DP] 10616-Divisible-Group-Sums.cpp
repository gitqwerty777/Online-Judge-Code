#include <stdio.h>
#include <string.h>

int N, Q, D, M;
int arr[204];
int dp[204][24];//select i nums, sum = j (mod d) -> ans = dp[n][0]
//compare to dp[i][j][k], from index 0 to i, select j nums, sum = k (i >= j)

inline int my_remain(int n, int d){
  if(n >= 0){
    return n % d;
  } else {
    return n + (-n/d + 1) * d; //to get the positive number (d > remain >= 0)
  }
}

int dp_sum(int d, int n){
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i = 0; i < N; i++){
    int remain = my_remain(arr[i], d);
    for(int j = n-1; j >= 0 ; j--)
      for(int k = d-1; k >= 0; k--)
	if(dp[j][k]){
	  //dp[j+1][(k+arr[i])%d] = dp[j][k] + 1; //get WA
	  dp[j+1][(k+remain)%d] += dp[j][k];
	}
  }
  return dp[n][0];
}
int main(){
  int count = 1;
  while(scanf("%d %d", &N, &Q) == 2 && N+Q){
    printf("SET %d:\n", count++);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);
    for(int q = 1; q <= Q; q++){
      scanf("%d %d", &D, &M);
      printf("QUERY %d: %d\n", q, dp_sum(D, M));
    }
  }
  return 0;
}