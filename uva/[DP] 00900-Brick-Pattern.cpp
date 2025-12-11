#include <stdio.h>

unsigned long long ans[51];

void find_ans(){
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 3;
	for(int i = 4; i <= 50; i++){
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