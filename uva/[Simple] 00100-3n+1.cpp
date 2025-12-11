#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int ans[1000001] = {0};

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

int toans(int n){
	int count = 0;
	while(n != 1){
		if(n % 2)
			n = 3*n+1;
		else
			n = n/2;
			
		count++;
	}
	return count+1;
}

int main(){
	int a, b;
	int ra, rb;
	int i;
	int max;
	
	while(1){
		a = Input();
		if(a == -1)
			break;
		b = Input();
		
		if(a < b){
			ra = a; rb = b;}
		else{
			ra = b; rb = a;}
			
		max = 0;
		for(i = ra; i <= rb; i++){
			if(!ans[i])
				ans[i] = toans(i);
			if(max < ans[i])
				max = ans[i];
		}
		
		printf("%d %d %d\n", a, b, max);
	}
	return 0;
}