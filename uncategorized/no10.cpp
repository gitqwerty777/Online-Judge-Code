#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	long long n;
	long long a;
	
	cin>>a>>n;
	
	int base = 1;
	vector<long long> lastbase;
	vector<long long> lastav;//記錄用
	
	lastbase.push_back(1);
	lastav.push_back(a);
	
	long lobase;
	if(n == 0)//n!=0
		cout<<1<<endl;
	else{
		cout<<(long long)(pow(a, n))<<endl;/*
		while(base < n){
			if(base * 2 <= n){
				base *= 2;
				a *= a;
				lastbase.push_back(base);
				lastav.push_back(a);
			}
			else{
				lobase = lastav.size();
				for(long i = lobase - 1; i >= 0; i--)
					while(lastbase[i] + base <= n){
						a *= lastav[i];
						base += lastbase[i];
					}
			}
		}
		cout<<a<<endl;*/
	}
	
	
	return 0;
}