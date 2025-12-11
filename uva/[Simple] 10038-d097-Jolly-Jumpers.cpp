#include <stdio.h>
#include <string.h>

inline int abs(int i){
	return (i < 0) ? (-i) : (i);
}

bool arr[3001];//¨â¼Æ®t-1

int main(){
	int N;
	int in[2];
	bool fail = false;
	long diff;
	
	while(scanf("%d", &N) == 1){
		memset(arr, false, sizeof(bool)*N);
		scanf("%d", &in[1]);
		fail = false;
		for(int n = 0; n < N-1; n++){
			scanf("%d", &in[n%2]);
			diff = abs(in[0] - in[1]);
			if(diff < N && diff > 0 && !arr[diff]){
				arr[diff] = true;
			} else {
				while(++n < N-1){
					scanf("%d", &in[0]);
				}
				fail = true;
				break;
			}
		}
		if(!fail){
			puts("Jolly");
		} else {
			puts("Not jolly");
		}
	}
	return 0;
}