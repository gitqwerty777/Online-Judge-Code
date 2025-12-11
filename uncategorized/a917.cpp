#include <stdio.h>
#include <string.h>
int ans[10001];

int way(int money, int Money){
	if(money < 0){
		return 0;
	} else if(money == 0){
		return 1;
	} else {
		if(Money == 50){
			if(ans[money] == -1){
				ans[money] = 1 + way(money-5, 5)
				+ way(money-10, 10) + way(money-50, 50);
			}
			return ans[money];
		} else if(Money == 10){
			return 1 + way(money-5, 5)
			+ way(money-10, 10);
		} else if(Money == 5){
			return 1 + way(money-5, 5);
		}
		
	}
}

int main(){
	int T, N;
	memset(ans, -1, sizeof(int)*10001);
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		scanf("%d", &N);
		if(ans[N] != -1){
			printf("%d\n", ans[N]);
		} else {
			ans[N] = way(N, 50);
			printf("%d\n", ans[N]);
		}
	}

	return 0;
}