#include <stdio.h>
//I confuse how to calculate at the beginning...

unsigned long long inline max(unsigned long long a, unsigned long long b){
	return (a>b)?a:b;
}

unsigned long long arr[21][21];

int main(){
	int i, j, N;
	int in;
	
	while(scanf("%d", &N) == 1 && scanf("%d", &arr[N][1]) == 1){
		bool first = true;
		for(int i = N; i >= 1; i--){
			for(int j = 1; j <= N; j++){
				if(first){//arr[N][1]
					first = false;
					continue;
				}
				unsigned long long tmp1 = 0, tmp2 = 0;
				if(i >= j){
					if(i != N){
						for(int k = i+1; k <= N; k++){
							tmp2 = max(tmp2, arr[k][1] + arr[k][j]);
						}
					}
					if(j != 0){
						for(int k = 1; k < j; k++){
							tmp1 = max(tmp1, arr[i][k] + arr[N][k]);
						}
					}
				} else {
					for(int k = i; k < j; k++){
						tmp1 = max(tmp1, arr[i][k] + arr[k+1][j]);
					}
				}
				arr[i][j] = tmp1 + tmp2;
			}
		}
		
		printf("%llu\n", arr[1][N]);
	}
	
	
	return 0;
}