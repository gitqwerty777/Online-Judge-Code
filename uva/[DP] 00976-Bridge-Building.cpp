#include <stdio.h>
#include <string.h>

char s[1000][1004];
int R, C, B, S;
int len[1004];

struct col{
  int n, s;
};
struct col bound[1000];

void find_terror(int r, int c){
  if(r >= R || c >= C || r < 0 || c < 0){
    return;
  }
  if(s[r][c] == '#'){
    s[r][c] = '@';
    find_terror(r+1, c);
    find_terror(r-1, c);
    find_terror(r, c+1);
    find_terror(r, c-1);
  }
}

void find_terrors(){
  find_terror(0, 0);
  for(int c = 0; c < C; c++)
    for(int r = 0; r < R; r++)
      if(s[r][c] == '@')
	bound[c].n = r;
      else if(s[r][c] == '#'){
	bound[c].s = r;
	break;
      }
}

inline void find_length(){
  for(int c = 0; c < C; c++)
    len[c+1] = bound[c].s - bound[c].n - 1;
}

inline int zmin(int a, int b){
  if(a == 0)
    return b;
  return (a>b)?b:a;
}

int dp[104][1004];//dp[bridgenum][nowcolumn] = min cost // 0 -> impossible
int ans;
void DP(){
  memset(dp, 0, sizeof(dp));
  for(int c = 1; c <= C; c++){
    dp[1][c] = zmin(dp[1][c-1], len[c]);//first bridge
    // printf("dp[1][%d] = %d\n", c, dp[1][c]);
  }
  for(int i = 2; i <= B; i++)
    for(int j = 1+(i-1)*S; j <= C; j++){//1 + 間隔*(B-1) <= nowcolumn
	//printf("dp[%d][%d](=%d) and dp[%d][%d](= %d) + [%d](=%d)\n", i, j,dp[i][j], i-1, j-S, dp[i-1][j-S], j, len[j]);
      for(int s = S; s < j; s++){
	//printf("dp[%d][%d](=%d) and dp[%d][%d](= %d) + [%d](=%d)\n", i, j,dp[i][j], i-1, j-s, dp[i-1][j-s], j, len[j]);
	if(dp[i-1][j-s] != 0)
	  dp[i][j] = zmin(dp[i][j], dp[i-1][j-s] + len[j]);
      }
      //printf("dp[%d][%d] = %d\n", i,j, dp[i][j]);
    }
  ans = dp[B][C];
  for(int i = 1+(B-1)*S; i <= C; i++)
    ans = zmin(dp[B][i], ans);
}

void print_len(){
  for(int i = 1; i <= C; i++){
    printf("%d ", len[i]);
  }
  puts("");
}

int main(){
  while(scanf("%d %d %d %d\n", &R, &C, &B, &S) == 4){
    S++; //calculate convinent
    for(int i = 0; i < R; i++)
      gets(s[i]);
    find_terrors();
    find_length();
    //    print_len();
    DP();
    printf("%d\n", ans);
  }
  return 0;
}