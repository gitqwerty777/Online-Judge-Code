#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a, int b){
	
	while(a && b){
		if(a > b)
			a %= b;
		else
			b %= a;
	}
	if(b)
		return b;
	else
		return a;
}
int main(){
	double a, n;
	double ans, yu;
	
	while(cin>>a>>n){
		if(gcd(int(a), int(n)) != 1)//互質才有inverse
			puts("No Inverse");
		else{
			for(int i = 0; i < a; i++){//check
				ans = (1-i*n) / a;
				if(ans == int(ans))
					break;
			}
			while(ans < 0)
				ans += n;
			cout<<int(ans)<<endl;
		}
	}

	return 0;
}