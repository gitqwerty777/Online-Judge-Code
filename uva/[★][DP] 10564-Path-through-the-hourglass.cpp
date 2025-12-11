#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n[40][20];
long long dp[40][20][360];
int pre[40][20][360];

int main(){
	int N, S;
	bool first = true;
	while(scanf("%d %d", &N, &S) == 2 && (N + S)){
		if(first){
			first = false;
		} else {
			puts("");
		}
		int max = 9*(2*N-1);
		if(S > max){
			int allnum = N*N + N - 1;
			int junk;
			for(int i = 0; i < allnum; i++)
				scanf("%d", &junk);
			puts("0");
			continue;
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N-i; j++){
				scanf("%d", &n[i][j]);
			}	
		}
		for(int i = 1; i < N; i++){
			for(int j = 0; j < i+1; j++){
				scanf("%d", &n[N-1+i][j]);
			}	
		}
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(pre));
		int allL = 2*N - 1;
		for(int i = 0; i < N; i++){
			dp[allL-1][i][n[allL-1][i]] = 1;
		}
		for(int i = allL-2; i >= 0; i--){//--
		  for(int j = 0; j < abs(i-N+1)+1; j++)
			for(int k = n[i][j]; k <= max; k++){
			    if(i >= N-1){//¤U¤T¨¤
					if(dp[i+1][j+1][k-n[i][j]]){
						dp[i][j][k] += dp[i+1][j+1][k-n[i][j]];
						pre[i][j][k] = 0;//right
					}
					if(dp[i+1][j][k-n[i][j]]){
						dp[i][j][k] += dp[i+1][j][k-n[i][j]];
						pre[i][j][k] = 1;//left
					}
			    } else {
					if(j<abs(i-N+1) && dp[i+1][j][k-n[i][j]]){
						dp[i][j][k] += dp[i+1][j][k-n[i][j]];
						pre[i][j][k] = 0;//right
					}
					if(j-1 >= 0 && dp[i+1][j-1][k-n[i][j]]){
						dp[i][j][k] += dp[i+1][j-1][k-n[i][j]];
						pre[i][j][k] = 1;//left
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 0; i < N; i++){
		  ans += dp[0][i][S];
		}
		if(ans == 0){
			puts("0");
			continue;
		} else {
			printf("%lld\n", ans);
		}
		for(int i = 0; i < N; i++){
		  if(dp[0][i][S]){
			printf("%d ", i);
			int x = 0, y = i, z = S;
			while(x < allL-1){
				//printf("pre[%d][%d][%d] = %d\n", x, y, z, pre[x][y][z]);
				if(pre[x][y][z] == 1){
				  z -= n[x][y];
				  putchar('L');
				  x++;
				  if(x <= N-1){
					y--;
				  }
				} else if(pre[x][y][z] == 0) {
			      z -= n[x][y];
				  putchar('R');
				  x++;
				  if(x > N-1){
					y++;
				  }
				} else {
				  z -= n[x][y];
				  putchar('X');
				}
				
			}
			break;
		  }
		}
	}
	return 0;
}
