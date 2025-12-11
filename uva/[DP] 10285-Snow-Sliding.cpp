#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int r, c;
	int h;
};
typedef struct Node node;

int R, C, N;
int arr[100][100];//height
int step[100][100];//max number of skiing, at [r][c]
node nodearr[10000];

int cmp(const void* a, const void* b){ //from small to big
	return ((node*)a)->h - ((node*)b)->h;
}

int inline max(int a, int b){
	return (a > b)? a: b;
}

void check_steps(node *a){
	int r = a->r;
	int c = a->c;
	if(r >= 1 && arr[r-1][c] > arr[r][c])//зя r and c ??
		step[r-1][c] = max(step[r-1][c], step[r][c]+1);
	if(r <= R-2 && arr[r+1][c] > arr[r][c])
		step[r+1][c] = max(step[r+1][c], step[r][c]+1);
	if(c >= 1 && arr[r][c-1] > arr[r][c])
		step[r][c-1] = max(step[r][c-1], step[r][c]+1);
	if(c <= C-2 && arr[r][c+1] > arr[r][c])
		step[r][c+1] = max(step[r][c+1], step[r][c]+1);
	
	/*printf("nowstate:(%d, %d)\n", r, c);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C;j++){
			printf("%d ", step[i][j]);
		}
		printf("\n");
	}*/
}

int main(){
	char n[16];
	scanf("%d", &N);
	while(N--){
		scanf("%s", n);
		scanf("%d %d", &R, &C);
		//memset(step, 1, sizeof(step)); // memset of 1 is dangerous http://jhengjyun.blogspot.tw/2010/02/cc-memset.html
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C;j++){
				step[i][j] = 1;
			}
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C;j++){
				scanf("%d", &arr[i][j]);
				nodearr[C*i+j].r = i;
				nodearr[C*i+j].c = j;
				nodearr[C*i+j].h = arr[i][j];
			}
		qsort(nodearr, R*C, sizeof(node), cmp);
		for(int i = 0; i < R*C; i++)
			check_steps(&nodearr[i]);	//O(n) time complexity
		int ans = 0;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++)
				if(step[i][j] > ans)
					ans = step[i][j];
		}
		printf("%s: %d\n", n, ans);
	}
	return 0;
}