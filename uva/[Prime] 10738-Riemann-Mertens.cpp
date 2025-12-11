#include <stdio.h>
#include <string.h>
#include <math.h>

int m[1000004];
int mu[1000004];
int prime[80000];

int main(){
	int in;
	//prime table
	int pi = 0;
	memset(m, 0, sizeof(m));
	for(int i = 2; i <= 1000000; i++){
		if(m[i] != 0){
			continue;
		} else {
			prime[pi++] = i;
			m[i] = 1;
			for(int j = 2*i; j <= 1000000; j += i){
				m[j] = 1;
			}
		}
	}
	//printf("pi = %d\n", pi);
	//mu and m table
	memset(m, 0, sizeof(m));
	m[1] = 1;
	mu[1] = 1;
	int facn;	bool issquare; int nown;
	for(int i = 2; i <= 1000000; i++){
		facn = 0;
		issquare = false;
		nown = i;
		for(int j = 0; prime[j] <= sqrt(i); j++){
			if(nown % prime[j] == 0){
				nown /= prime[j];
				facn++;
				while(nown % prime[j] == 0){
					nown /= prime[j];
					facn++;
					issquare = true;
				}
			}
		}
		if(nown != 1){//½è¼Æ
			facn++;
		}
		if(issquare){
			mu[i] = 0;
		} else {
			if(facn % 2){
				mu[i] = -1;
			} else {
				mu[i] = 1;
			}
		}
		m[i] = m[i-1] + mu[i];
	}
	
	//deal with input
	while(scanf("%d", &in) == 1 && in){
		printf("%8d%8d%8d\n", in, mu[in], m[in]);
	}
	return 0;
}