#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	string sn;
	string sa;
	long long int a;
	long long int n;
	
	vector<long long int > lastbase;
	vector<long long int > lastav;//記錄用

	while(cin>>sa>>sn){
		//預處理
		int i = 0;
		if(sa == "0" && sn == "0"){
			cout<<"All Over."<<endl;
			break;
		}
			/*
		while(sa[0] == '0' && sa.size() > 1)
			sa.erase(sa.begin());
		while(sn[0] == '0' && sn.size() > 1)//0
			sn.erase(sn.begin());*/
		stringstream ss;
		ss.clear();
		ss<<sa<<" "<<sn;
		ss>>a>>n;
		

		if(a == 0)
			cout<<"0"<<endl;
		else if(n == 0){
			cout<<"1"<<endl;
		}
		else if(a == 1 || a == -1){
			if(a == 1 || n % 2 == 0)
				cout<<"1"<<endl;
			else
				cout<<"-1"<<endl;
		}
		else{
			long long int base = 1;
			lastbase.clear();
			lastav.clear();
			lastbase.push_back(1);
			lastav.push_back(a);
			while(base < n){
				if(base * 2 <= n){
					base *= 2;
					a *= a;
					lastbase.push_back(base);
					lastav.push_back(a);
				}
				else{
					int lobase = lastav.size();
					for(int i = lobase - 1; i >= 0; i--)
						if(lastbase[i] + base <= n){
							a *= lastav[i];
							base += lastbase[i];
							lastbase.push_back(base);
							lastav.push_back(a);
							break;
						}
				}
			}
			
			cout<<a<<endl;
		}
		
	}
	
	
	return 0;
}