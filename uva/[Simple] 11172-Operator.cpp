#include <stdio.h>

int main(){
	int N, a, b;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &a, &b);
		if(a < b)
			puts("<");
		else if(a > b)
			puts(">");
		else
			puts("=");
	}
	return 0;
}
