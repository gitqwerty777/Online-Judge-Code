#include <stdio.h>
#include <string.h>

char ans[14][20];

int main(){
	int n;
	strcpy(ans[8],"40320");
	strcpy(ans[9],"362880");
	strcpy(ans[10],"3628800");
	strcpy(ans[11],"39916800");
	strcpy(ans[12],"479001600");
	strcpy(ans[13],"6227020800");
	
	while(scanf("%lld", &n) == 1){
		if(n < 0){//What the ... !?
			n = -n;
            if(n % 2 == 0)
                puts("Underflow!");
            else
                puts("Overflow!");
		} else if(n > 13){
			puts("Overflow!");
		} else if (n < 8){
			puts("Underflow!");
		} else{
			puts(ans[n]);
		}
	}
	return 0;
}