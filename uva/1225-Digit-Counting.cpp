#include <cstdio>
#include <cstring>

int T, N;
int ans[10001][10];
int count[10] = {0};

void getAns(){
  for(int i = 1; i <= 10000; i++){
    int num = i;
    while(num > 0){
      count[num%10]++;
      num/=10;
    }
    for(int j = 0; j < 10; j++)
      ans[i][j] = count[j];
  }
}

int main(){
  getAns();
  
  scanf("%d\n", &T);
  while(T--){
    scanf("%d", &N);
    printf("%d", ans[N][0]);
    for(int i = 1; i < 10; i++)
      printf(" %d", ans[N][i]);
    puts("");
  }
}
