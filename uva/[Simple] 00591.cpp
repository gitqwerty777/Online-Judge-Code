#include <stdio.h>

int main(){
  int N;
  int r[54];
  int ans, sum, avg;
  int count = 1;
  
  while(scanf("%d", &N) == 1 && N){
    sum = 0;
    for(int i = 0; i < N; i++){
      scanf("%d", &r[i]);
      sum += r[i];
    }
    avg = sum / N;
    ans = 0;
    for(int i = 0; i < N; i++){
      if(r[i] > avg)
	ans += r[i] - avg;
    }
    printf("Set #%d\n", count++);
    printf("The minimum number of moves is %d.\n\n", ans);//these output format really waste the time...
  }
  return 0;
}