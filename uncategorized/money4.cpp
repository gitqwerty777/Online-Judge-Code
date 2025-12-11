#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>


using namespace std;

int main(){
	int n;
	cin>>n;
	
	long long a, b; long long rate;
	
	int count = 0;
	while(n--){
		cin>>a>>b;
		
		rate = (b-a)*100000 / a;
		long long rrate = rate / 1000;
		//cout<<rate<<endl;
		if(rate <= 4 && rate >= -4){
			cout<<"0.00% keep"<<endl;
			continue;
		}
		
		if(rate < 0){
			rate = -rate;
			cout<<"-";
		}
		if(rate % 10 >= 5)
			rate += 10;
		//cout<<"rate % 10  "<<(rate % 10)<<endl;
		long long fl = (rate % 1000) / 10;
		//cout<<"fl "<<fl<<endl;
		if(fl < 10)
			cout<<rate/1000<<".0"<<fl;
		else
			cout<<rate/1000<<"."<<fl;
		
		
		if(rrate >= 10 || rrate <= -7)
			cout<<"% dispose"<<endl;
		else
			cout<<"% keep"<<endl;
	}
	
	
	return 0;
}