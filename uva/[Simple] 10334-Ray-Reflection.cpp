#include <stdio.h>

//wait for bignumber.h complete
unsigned long long ans[1001];

void find_ans(){
	ans[0] = 1;
	ans[1] = 2;
	ans[2] = 3;
	for(int i = 4; i <= 1000; i++){
		ans[i] = ans[i-1] + ans[i-2];
	}
}


int main(){
	int L;
	
	find_ans();
	
	while(scanf("%d", &L) && L){
		printf("%llu\n", ans[L]);
	}
	return 0;
}