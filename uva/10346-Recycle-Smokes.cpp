#include <cstdio>

int N, R;
int ans;

void recycle(){
  ans = N;
  int remain = N;
  while(remain >= R){
    int news = remain/R;
    ans += news;
    remain %= R;
    remain += news;
  }
}

int main(){
  while(scanf("%d%d", &N, &R) == 2){
    recycle();
    printf("%d\n", ans);
  }
}
