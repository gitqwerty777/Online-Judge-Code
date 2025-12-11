#include <cstdio>

int T;
int N, H;
char ans[20] = "";

void findHamming(int d, int nowh){
  if(d == N){
    if(nowh == H){
      ans[N] = '\0';
      puts(ans);
    }
  } else {
    int remain = N-d-1;
    if(remain+nowh >= H){//possible
      ans[d] = '0';
      findHamming(d+1, nowh);
    }
    if(nowh+1 <= H){
      ans[d] = '1';
      findHamming(d+1, nowh+1);
    }
  }
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &N, &H);
    findHamming(0, 0);
    if(T)
      puts("");
  }
}
