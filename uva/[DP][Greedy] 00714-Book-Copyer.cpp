#include <stdio.h>
#include <string.h>
#define INT_INF 2147483647
#define INF 5000000001

int book[500]; long booksum[500];
long dp[500][500];
//scribers, scribed-booknum, value = max books values by one scriber
int realans[500];
int N, C, B;//CUT BOOK

void print_answer(){
	int count = 0;
	for(int i = 0; i < B; i++){
		printf("%d", book[i]);
		if(count <= C-2 && i == realans[count]){
			putchar(' ');
			putchar('/');
			count++;
		}
		if(i != B-1)
			putchar(' ');
	}
	//if(N) 
	/* ========== What the FUCK is it? It SOULD tolerate NO new line
				  at the end, and I get AC after this line =========== */
		puts("");
}

inline long max(long a, long b){
	return a > b ? a : b;
}

inline long min(long a, long b){
	return a < b ? a : b;
}

void book_test(){//by DP
	for(int j = 0; j < B; j++)
		dp[0][j] = booksum[j];
	long maxn;
	for(int i = 1; i < C; i++){
		for(int j = i; j < B; j++){//到第i個人時，已用j本書(j >= i)(j <= B-(C-i))
			maxn = INF;
			for(int k = i-1; k < j; k++){//設i-1人時，已用k本書(k >= i-1), 所以第i人用k-j本 //最後一次可以移除
				maxn = min(maxn, max(dp[i-1][k], booksum[j]-booksum[k]));
			}
			dp[i][j] = maxn;
			//printf("dp[%d][%d] = %d\n", i, j, maxn);
		}
	}
}

void find_real_answer(){//by Greedy
	long max_bookn = dp[C-1][B-1];
	//printf("max_bookn = %d\n", max_bookn);
	
	int nowc = C-2;
	long nowb = 0;
	for(int i = B-1; i >= 0; i--){
		if(nowc == i){//not enough books!
			while(i >= 0)
				realans[nowc--] = i--;
			break;
		}
		if(nowb + book[i] > max_bookn){
			realans[nowc--] = i;
			nowb = book[i];
		} else {
			nowb += book[i];
		}
	}
	//for(int i = 0; i < C-2; i++){
	//	printf("realans[%d] = %d\n", i, realans[i]);
	//}
}

int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &B, &C);
		memset(dp, INT_INF, sizeof(dp));
		for(int i = 0; i < B; i++)
			scanf("%d", &book[i]);
		booksum[0] = book[0];
		for(int i = 1; i < B; i++)
			booksum[i] = booksum[i-1] + book[i];
			
		book_test();
		//printf("ans = %d\n", dp[C-1][B-1]);
		find_real_answer();
		
		print_answer();
	}
	return 0;
}