#include <stdio.h>
//I don't know the faster solution

int ans[10001];
int ans_noten[10001];//without two and five
int two = 0; int five = 0;

int inline min(int a, int b){
	return (a<b)?a:b;
}

void find_ans(){
	ans[0] = 1;
	ans[1] = 1;
	ans_noten[0] = 1;
	ans_noten[1] = 1;
	
	int pretmp = 1;
	for(int i = 2; i <= 10000; i++){
		int temp = i;
		while(temp % 2 == 0){
			temp /= 2;
			two++;
		}
		while(temp % 5 == 0){
			temp /= 5;
			five++;
		}
		int ten = min(two, five);
		two -= ten;
		five -= ten;
		int tmp = ans_noten[i-1] * temp;
		ans_noten[i] = tmp % 20000;
		if(two){
			switch(two % 4){
				case 0:
					tmp *= 6;
					break;
				case 1:
					tmp *= 2;
					break;
				case 2:
					tmp *= 4;
					break;
				case 3:
					tmp *= 8;
					break;
			}
		}
		if(five){
			tmp *= 5;
		}
		ans[i] = tmp % 10;
	}
}


int main(){
	int n;
	
	find_ans();
	
	while(scanf("%d", &n) == 1){
		printf("%5d -> %d\n", n, ans[n]);
	}
	return 0;
}