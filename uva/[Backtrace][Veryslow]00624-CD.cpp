#include <stdio.h>
#include <string.h>
#include <vector>
int arr[20];
std::vector<bool> ans;
std::vector<bool> sol;
int T, N, max;

void backtrack(int di){//dimension
  int sum = 0;
  for(int i = 0; i < N; i++)
    if(sol[i])
      sum += arr[i];
  if(sum <= T && sum > max){
    max = sum;
    ans = sol;
  }
  if(di == N)
    return;
  sol[di] = false;
  backtrack(di+1);
  sol[di] = true;
  backtrack(di+1);
}

int main(){
  ans.resize(24);
  sol.resize(24);
  while(scanf("%d%d", &T, &N) == 2){
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);
    max = 0;
    for(int i = 0; i < N; i++){
      sol[i] = false; ans[i] = false;}
    backtrack(0);
    for(int i = 0; i < N; i++)
      if(ans[i])
	printf("%d ", arr[i]);
    printf("sum:%d\n", max);
  }
  return 0;
}