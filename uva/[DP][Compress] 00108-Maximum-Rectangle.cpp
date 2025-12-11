#include <stdio.h>
#include <string.h>

int ans[100][100];
//Source:http://www.csie.ntnu.edu.tw/~u91029/Sequence.html#2

int main(){
  int N;
  int max;
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf("%d", &ans[i][j]);

  max = ans[0][0];
  for(int i = 0; i < N; i++){
    int p = 0;
    for(int j = 0; j < N; j++){
      p += ans[j][i];
      if(p > max)
	max = p;
      if(p < 0)
	p = 0;
    }
  }
  for(int i = 0; i < N; i++){
    int p = 0;
    for(int j = 0; j < N; j++){
      p += ans[i][j];
      if(p > max)
	max = p;
      if(p < 0)
	p = 0;
    }
  }
  for(int i = 0; i < N; i++)
    for(int j = 1; j < N; j++)
      ans[i][j] += ans[i][j-1];//壓縮成1D，以計算由ia到ib行的和

  for(int i = 0; i < N; i++)
    for(int j = i+1; j < N; j++){//from i to j row, if i == j, it means 1 * X rectangle, 
      int p = 0;
      for(int k = 0; k < N; k++){
	if(i > 0)
	  p += ans[k][j] - ans[k][i-1];
	else
	  p += ans[k][j];
	if(p > max)
	  max = p;
	if(p < 0)
	  p = 0;
      }
    }
  printf("%d\n", max);
  return 0;
}
