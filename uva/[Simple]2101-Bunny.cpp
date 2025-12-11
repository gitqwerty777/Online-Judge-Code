#include <stdio.h>
#include MAXARR 10000001
int ans[MAXARR];

struct ans{
  long long ans;
  
};

void make_ans(){
  ans[2] = 3;
  ans[3] = 5;
  ans[4] = 8;
  for(int i = 0;i < MAXARR; i++){
    ans[i] = ans[i-1] + ans[i-2];
  }
}

int main(){
  int n;
  make_ans();
  int in;
  scanf("%d", &in);
  while(scanf("%d", &in) == 1){
    if()
    printf("%d\n", ans[in]);
  }
  return 0;
}
