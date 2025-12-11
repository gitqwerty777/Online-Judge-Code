#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

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
	int dra, yushia;
	int i;
	bool lose = false;
	int d[20001], y[20001];
	long long money; 
	
	while(1){
		dra = Input();
		yushia = Input();
		lose = false;
		
		if(dra == 0 && yushia == 0)
			break;
		
		if(dra > yushia)
			lose = true;
			
		for(i = 0; i < dra; i++)//負數??
			d[i] = Input();
		for(i = 0; i < yushia; i++)
			y[i] = Input();
		
		if(lose){
			puts("Loowater is doomed!");continue;
		}
			
		sort(d, d+dra); sort(y, y+yushia);
		
		if(d[dra-1] > y[yushia-1]){
			puts("Loowater is doomed!");continue;
		}
		
		money = 0;
		int ycount = 0;
		for(i = 0; i < dra; i++){//?
			while(ycount < yushia && y[ycount] < d[i])
				ycount++;
			if(yushia - ycount < dra - i){
				lose = true;break;}
			money += y[ycount++];
		}
			
		if(!lose)
			printf("%lld\n", money);
		else
			puts("Loowater is doomed!");
	}
	return 0;
}