#include <stdio.h>

int arr[9];//b g c
char name[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
int ans[6];

int main(){
	int N, T;
	while(scanf("%d", &arr[0]) == 1){
		scanf("%d%d%d%d%d%d%d%d", &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8]);
		int sum = 0;
		for(int i = 0; i < 9; i++){
			sum += arr[i];
		}
		ans[0] = sum - arr[0] - arr[5] - arr[7];
		ans[1] = sum - arr[0] - arr[4] - arr[8];
		ans[2] = sum - arr[2] - arr[3] - arr[7];
		ans[3] = sum - arr[2] - arr[4] - arr[6];
		ans[4] = sum - arr[1] - arr[3] - arr[8];
		ans[5] = sum - arr[1] - arr[5] - arr[6];
		int win, min = sum+1;
		for(int i = 0; i < 6; i++){
			if(ans[i] < min){
				win = i;
				min = ans[i];
			}
		}
		printf("%s %d\n", name[win], ans[win]);
	}
	
	return 0;
}