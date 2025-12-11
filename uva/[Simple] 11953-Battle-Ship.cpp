#include <stdio.h>

int T, N;
char b[104][104];
bool isLive;
void dfs(int i, int j){
  if(!(i >= 0 && j >= 0 && i < N && j < N && (b[i][j] == 'x' || b[i][j] == '@')))
    return;
  if(b[i][j] == 'x')
    isLive = true;
  b[i][j] = '.';
  dfs(i-1, j);
  dfs(i+1, j);
  dfs(i, j-1);
  dfs(i, j+1);
}

int dfs(){
  int num = 0;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(b[i][j] == 'x' || b[i][j] == '@'){
	isLive = false;
	dfs(i, j);
	//printf("%d %d = %d\n", i, j, isLive);
	if(isLive)
	  num++;
      }
  return num;
}

int main(){
  scanf("%d", &T);
  for(int t = 0; t < T; t++){
    scanf("%d", &N);
    for(int n = 0; n < N;n++){
      scanf("%s", b[n]);
      //printf("line %d: %s\n", n, b[n]);
    }
    int num = dfs();
    printf("Case %d: %d\n", t+1, num);
  }
  return 0;
}
