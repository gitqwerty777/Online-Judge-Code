#include <cstdio>

int N, R;

int main(){
  int count = 1;
  while(scanf("%d%d", &N, &R) == 2 && N+R){
    int z = N / R;
    if(N%R)
      z++;

    printf("Case %d: ", count++);
    if(z > 27)
      puts("impossible");
    else
      printf("%d\n", z-1);
  }
}
