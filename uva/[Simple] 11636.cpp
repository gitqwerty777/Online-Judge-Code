#include <stdio.h>

int ans[10004];
void make_ans(){
  ans[1] = 0;
  int nowans = 1;
  int nexti = 2;
  for(int i = 2;i < 10001; i++){
    ans[i] = nowans;
    if(i >= nexti){
      nowans++;
      nexti *= 2;
    }
  }
}

int main(){
  //2^n ~ 2^n+1 - 1 => n pastes
  make_ans();

  int in, count = 1;
  while(scanf("%d", &in) == 1 && in > 0){
    printf("Case %d: %d\n", count++, ans[in]);
  }
  return 0;
}