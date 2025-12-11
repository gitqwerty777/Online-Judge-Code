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
	long test_num;
	test_num = Input();
	int r, c;
	int i, j;
	long rline[2001], cline[2001];
	long long rans[2001], cans[2001];
	long long left, right, ans;	int ansr, ansc; long long diff;
	
	int count = 0;
	while(test_num--){
		r = Input();
		c = Input();
		long long all = 0;

		memset(rline, 0, sizeof(long) * r);
		memset(cline, 0, sizeof(long) * c);
		
		int in;
		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++){
				in = Input();
				rline[i] += in;
				cline[j] += in;
			}
		
		for(i = 0; i < r; i++)
			all += rline[i];
			
		ans = 0;	left = 0;	right = all - rline[0];
		rans[0] = ans;
		int realindex = 0; long long realvalue = rans[0];
		
		for(i = 0; i < r-1; i++){
			left += rline[i];
		
			rans[i+1] = rans[i] + left - right;
			if(rans[i+1] < realvalue){
				realindex = i+1;
				realvalue = rans[i+1];
			}
			right -= rline[i+1];
		}
		ansr = realindex;
				
		left = 0;		right = all - cline[0];		ans = 0;
		cans[0] = ans;
		realindex = 0; 	realvalue  = cans[0];
		
		for(i = 0; i < c-1; i++){
			left += cline[i];

			cans[i+1] = cans[i] + left - right;
			if(cans[i+1] < realvalue){
				realindex = i+1;
				realvalue = cans[i+1];
			}
				
			right -= cline[i+1];
		}
		ansc = realindex;
		printf("%d %d\n", ansr+1, ansc+1);
		///////////////////////////////////////////////////////
		ans = 0;
		long long anscount = 0;
		long long wei;
		for(i = 0; i < r; i++){
			wei = (long long)rline[i] * (long long)(ansr-i);
			
			if(wei > 0)
				ans += wei;
			else
				ans -= wei;
			//////    ///9223372036854775807
					  ///400000000000000000
			while(ans >= (long long)(10000000000000000)){
				ans -= (long long)(10000000000000000);
				anscount++;
			}
		}
		for(i = 0; i < c; i++){
			wei = (long long)cline[i] * (long long)(ansc-i);
			
			if(wei > 0)
				ans += wei;
			else
				ans -= wei;
			/////////9223372036854775807
			/////////////////////////4000000000000000
			while(ans >= (long long)(10000000000000000)){
				ans -= (long long)(10000000000000000);
				anscount++;
			}
		}
		
		if(anscount){
			string anss;
			anss.assign(17, '0');
			i = 16;
			while(ans > 0){
				anss[i--] += ans % 10;// % ok?
				ans /= 10;
			}
			printf("%lld",anscount);
			puts(anss.c_str());
		}
		else
			printf("%lld\n", ans*100);
	
	}
	return 0;
}