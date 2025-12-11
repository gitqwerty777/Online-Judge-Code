#include <iostream>
#include <cstdio>

using namespace std;

int arr[501][501];

int Input(){  
    char cha;  
    int x=0;  
    while(cha=getchar())  
        if((cha >= 48 && cha < 58) || cha == EOF) break;
	if(cha == EOF) return -1;
    x=cha-48;
    while(cha=getchar()) {  
        if(cha < 48 || cha >= 58) break;  
        x=x*10+cha-48;  
    }  
    return x;
}

int main(){
	int n, m;
	int i, j;
	
	while(1){
		n = Input();
		if(n == -1)
			break;
		m = Input();
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				arr[i][j] = Input();
		
		for(i = 0; i <= n; i++){
			arr[0][i] = 0;
			arr[i][0] = 0;
		}
			
		for(i = 2; i <= 2*n; i++)
			for(j = 1; j < i; j++)
				arr[j][i-j] += arr[j-1][i-j] + arr[j][i-j-1] - arr[j-1][i-j-1];
		
		int x, y, xx, yy;
		for(i = 0; i < m; i++){
			x = Input();	y = Input();
			xx = Input();	yy = Input();
			
			printf("%d\n", arr[xx][yy] - arr[x-1][yy] - arr[y-1][xx] + arr[x-1][y-1]);
		}
		
	}
	return 0;
}