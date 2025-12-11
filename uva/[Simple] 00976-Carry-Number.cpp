#include <stdio.h>
#include <string.h>

int main(){
	char a[12], b[12];
	int asize, bsize;
	int carnum;
	int carry;
	int flow = '0' + '9';
	while(scanf("%s %s", a, b) == 2 && a[0] + b[0] != '0' + '0'){ 
		carnum = 0;
		carry = 0;
		asize = strlen(a);
		bsize = strlen(b);
		int size = asize > bsize ? bsize : asize;
		while(asize >= 1 || bsize >= 1){
			if(asize < 1 || bsize < 1){
				if(asize < 1)
					while(bsize >= 1){
						if(b[bsize-1] + '0' + carry > flow){
							carry = 1;
							carnum++;
							bsize--;
						} else {
							bsize = -1;
							break;
						}
					}
				else
					while(asize >= 1){
						if(a[asize-1] + '0' + carry > flow){
							carry = 1;
							carnum++;
							asize--;
						} else {
							asize = -1;
							break;
						}
					}
			} else if(a[asize-1] + b[bsize-1] + carry > flow){
				carry = 1;
				carnum++;
			} else {
				carry = 0;
			}
			asize--;
			bsize--;
		}
		if(carnum == 1)
			puts("1 carry operation.");
		else if(carnum == 0)
			puts("No carry operation.");
		else
			printf("%d carry operations.\n", carnum);
	}
	return 0;
}