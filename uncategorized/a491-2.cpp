#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

int Input(){  
    char cha;  
    int x=0;  
    while(cha=getchar())  
        if(cha >= 48 && cha < 58) break;  
    x=cha-48;
    while(cha=getchar()) {  
        if(cha < 48 || cha >= 58) break;  
        x=x*10+cha-48;  
    }  
    return x;
}

int main(){
	int test_num;
	cin>>test_num;
	int r, c;
	int i, j;
	int rline[2001], cline[2001];
	long long left, right, ans;	int ansr, ansc; long long diff;
	
	int count = 0;
	while(test_num--){
		r = Input();
		c = Input();
		long long all = 0;
		long long rsum = 0;
		long long csum = 0;
		memset(rline, 0, sizeof(int) * r);
		memset(cline, 0, sizeof(int) * c);
		
		int in;
		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++){
				in = Input();
				rline[i] += in;
				cline[j] += in;
			}
		
		for(i = 0; i < r; i++){
			rsum += rline[i] * i;
			all += rline[i];
		}
		for(i = 1; i < c; i++)
			csum += cline[i] * i;
			
		ans = 0;	ansr = -1;	ansc = -1;
		left = 0;	right = all - rline[0];
		
		ans += rsum;
		for(i = 0; i < r-1; i++){
			left += rline[i];
			
			diff = left - right;
			
			if(diff < 0)
				ans += diff;
			else{
				ansr = i;break;}
				
			right -= rline[i+1];
		}
		if(ansr == -1)
			ansr = r-1;//ok?
				
		left = 0;		right = all - cline[0];
		ans += csum;
		for(i = 0; i < c-1; i++){
			left += cline[i];
			
			diff = left - right;
			if(diff < 0)
				ans += diff;
			else{
				ansc = i;break;}
				
			right -= cline[i+1];
		}
		if(ansc == -1)
			ansc = c-1;//ok?
		
		printf("%d %d\n%lld\n", ansr+1, ansc+1, ans*100);
	}
	return 0;
}