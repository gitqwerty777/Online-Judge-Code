#include <stdio.h>
#include <string.h>

int ans[14][104][104];
//ref:http://www.cppblog.com/y346491470/articles/165064.html

inline int max(int a, int b){
  return (a>b)?a:b;
}

inline int min(int a, int b){
  return (a<b)?a:b;
}

void find_ans(){
  for(int i = 1; i <= 100; i++)
    for(int j = i; j <= 100; j++)
      ans[1][i][j] = (i+j) * (j-i+1) / 2;
  //ans[?][j][j] = j?? not zero???????
  for(int i = 2; i <= 10; i++)
    for(int k = 1; k <= 100; k++)
      for(int j = k; j > 0; j--){
	ans[i][j][k] = j + max(ans[i-1][j][j-1], ans[i][j+1][k]);//t == j
	for(int t = j+1; t <= k; t++){//test which point to explode
	  ans[i][j][k] = min(ans[i][j][k], t + max(ans[i-1][j][t-1], ans[i][t+1][k]));
	}
      }
}

int main(){
  int N;
  int k, m;
  scanf("%d", &N);
  find_ans();
  while(N--){
    scanf("%d%d", &k, &m);
    printf("%d\n", ans[k][1][m]);
  }
  return 0;
}