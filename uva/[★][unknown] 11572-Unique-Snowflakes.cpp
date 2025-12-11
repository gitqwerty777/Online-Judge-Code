#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;
map<int, int> m;

int main(){
	int r = 0;
	int R, N, d;
	int bagn, maxn, start;
	scanf("%d", &R);
	while(r++ < R){
		//if(r > 1)
		//	puts("");
		bagn = 0; maxn = 0; start = 0;
		m.clear();
		scanf("%d", &N);
		for(int n = 0; n < N; n++){
			scanf("%d", &d);
			if(m.find(d) != m.end() && m[d] >= 0 && start <= m[d]){//­«
				bagn = n - start;
				printf("bagn %d, start from %d to %d\n", bagn, start, n-1);
				start = m[d]+1;
				printf("new start is %d\n", start);
				if(bagn > maxn){
					maxn = bagn;
				}
			}
			m[d] = n;
		}
		bagn = N - start;
		printf("bagn %d, start from %d to %d\n", bagn, start, N-1);
		if(bagn > maxn){
			maxn = bagn;
		}
		printf("%d\n", maxn);
	}
	return 0;
}