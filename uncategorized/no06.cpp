#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	string sn;
	string sa;
	int a;
	int n;
	char in[10000];
	stringstream ss;
	vector<vector<int> > ans(46342);
	int power, ppower;
	for(int i = 2; i < 46342; i++){
		power = i;
		ans[i].push_back(1);//ans[i][0]
		ans[i].push_back(power);//ans[i][1]
		ppower = power * i;
		while(ppower > power){
			power = ppower;
			ppower *= i;
			ans[i].push_back(power);
		}
	}
	while(gets(in)){
		//預處理
		/*
		while(sa[0] == '0' && sa.size() > 1)
			sa.erase(sa.begin());
		while(sn[0] == '0' && sn.size() > 1)//0
			sn.erase(sn.begin());*/
		//no clear
		ss.clear();
		ss<<in;
		ss>>a>>n;
		
		int aa = abs(a);
		if(aa <= 1){
			if(a == 0){
				if(sa == "0" && sn == "0"){
					long long overcount = 0;
					while(gets(in))
						overcount++;
					cout<<"All Over. Exceeded "<<overcount<<" lines!"<<endl;
					break;
				}
				else
					cout<<"0"<<endl;
			}
			else if(a == 1 || (sn[sn.size()-1] - '0') % 2 == 0)
				cout<<"1"<<endl;
			else
				cout<<"-1"<<endl;
		}
		else if(aa < 46342){
			if(a > 0 || n % 2 == 0)
				cout<<ans[aa][n]<<endl;
			else
				cout<<-ans[-a][n]<<endl;
		}
		else
			cout<<a<<endl;
	
	}
	
	
	return 0;
}
