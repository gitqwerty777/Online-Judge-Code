#include <stdio.h>
#include <string.h>

// unsigned long long => %llu
//N, B < 0

/*
__int64 is a 64-bit integer data type in Visual C++. So the following code was written in Visual C++.
typedef unsigned __int64 datatype;
datatype count;
 
datatype trib(int n, unsigned int back)
{
    datatype sum=0;
    int i;
    count++;
    if(n<=0) return 0;
    if(n==1) return 1;
    for(i=1;i<=back;i++)
         sum+=trib(n-i,back);
    return sum;
}
 
void main(void)
{
    count=0;
    trib(5,5);
    printf(¡u%I64u\n¡v,count);
}
*/
unsigned long long ans[61][61];

unsigned long long sum_ans(int n, int b){
	unsigned long long sum = 0;
	for(int i = 1; i <= b && n >= i; i++){
		sum += ans[n-i][b];
	}
	if(n < b){
		sum += b-n;
	}
	return sum;
}

void find_ans(){
	unsigned long long sum = 0;
	unsigned long long tempsum = 0;
	for(int i = 0; i < 61; i++)//back
		for(int j = 0; j < 61; j++){//n
			if(j <= 1){
				ans[j][i] = 1;
			} else {
				ans[j][i] = sum_ans(j, i) + 1;
			}
			//printf("[%d][%d] = %llu\n", j, i, ans[j][i]);
		}
}

int main(){
	int N, B;
	memset(ans, 0, sizeof(ans));
	find_ans();
	int count = 1;
	while(scanf("%d %d", &N, &B) && N <61 && B < 61){
		if(B<0 || N<0){
			printf("Case %d: %llu\n", count++, 1);
		} else 
			printf("Case %d: %llu\n", count++, ans[N][B]);
	}
	return 0;
}