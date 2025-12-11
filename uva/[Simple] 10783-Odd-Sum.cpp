#include <stdio.h>

int ans[101];
void make_ans(){
  ans[0] = 0;
  ans[1] = 1;
  ans[2] = 1;
  for(int i = 3; i < 101; i++){
    if(i % 2){
      ans[i] = ans[i-1] + i;
    } else {
      ans[i] = ans[i-1];
    }
  }
}

int main(){
  int T;
  int a, b;
  make_ans();
  scanf("%d", &T);
  int count = 1;
  while(T--){
    scanf("%d %d", &a, &b);
    if(a > 0)
      printf("Case %d: %d\n", count++, ans[b] - ans[a-1]);
    else
      printf("Case %d: %d\n", count++, ans[b]);
  }
  return 0;
}