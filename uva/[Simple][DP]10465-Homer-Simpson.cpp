#include <cstdio>
#include <cstring>

int M, N, T;
int t[10000];

int inline max(int a, int b){
  return (a>b)?a:b;
}

void getTime(){
  memset(t, 0, sizeof(t));
  t[N] = 1;
  t[M] = 1;
  for(int i = 0; i <= T; i++){
    if(i >= M && t[i-M] > 0)
      t[i] = max(t[i], t[i-M]+1);
    if(i >= N && t[i-N] > 0)
      t[i] = max(t[i], t[i-N]+1);
  }
  for(int i = T; i >= 0; i--){
    if(t[i] != 0){
      printf("%d", t[i]);
      if(i != T)
	printf(" %d\n", T-i);
      else
	puts("");
      return;
    }
  }
  printf("0 %d\n", T);//no burger
}

int main(){
  while(scanf("%d%d%d", &M, &N, &T) == 3){
    getTime();
  }
}
