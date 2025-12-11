#include <cstdio>

int T;
int N;

int main(){
  scanf("%d", &T);
  int count = 1;
  while(T--){
    scanf("%d", &N);
    int ansi = N/2;
    int a;
    for(int i = 0; i <= ansi; i++)
      scanf("%d", &a);
    printf("Case %d: %d\n", count++, a);
    for(int i = ansi+1; i < N; i++)
      scanf("%d", &a);
  }
}
