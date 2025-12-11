#include <stdio.h>

int main(){
	int N;
	int node[100][2];
	double tan[100];
	while(scanf("%d", &N) && N){
		for(int i = 0; i < 2*N; i++){
			scanf("%d %d", &node[i][0], &node[i][1]);
			tan[i] = double(node[i][1]) / node[i][0];
		}
		bool ok = false;
		int place, left, right;
		for(int i = -500; i <= 500 && !ok; i++)
			for(int j = -500; j <= 500 && !ok; j++){
				bool cut = false;
				left = 0;
				right = 0;
				for(int k = 0; k < 2*N; k++){
					place = i*node[k][0] + j*node[k][1];
					if(place > 0){
						right++;
					} else if(place < 0){
						left++;
					} else {
						cut = true;
						break;
					}
				}
				if(!cut && left == N && right == N){
					printf("%d %d\n", i, j);
					ok = true;
				}
			}
	}
	return 0;
}