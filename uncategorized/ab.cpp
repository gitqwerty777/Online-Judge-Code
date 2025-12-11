#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

int main(){
	string in; int ans[4]; string toans; int ansi;
	int ansp[10]; string n; int ni;
	int quest;
	stringstream ss;
	//注意到，在loop 裡面有清除 flag 動作，stream.clear()。若要清文字內容，是用 stream.str("")，二者不同。要用 stringstream 產生 A001.txt~A100.txt 字串較麻煩一點，要先引入 iomanip
	while(getline(cin, in)){
		if(in.empty())
			continue;
		getline(cin, n);
		ss.str("");
		ss.clear();
		ss<<n;
		ss>>ni;
		cout<<"n "<<ni<<endl;
		ss.str("");
		ss.clear();
		ss<<in;
		int i, j;
		vector<int> ansp;
		ansp.assign(10, 0);
		cout<<"real ans ";
		for(i = 0; i < 4; i++){
			ss>>ansi;
			ans[i] = ansi;
			cout<<ansi;
			ansp[ansi]++;
		}
		cout<<endl;
		int a, b;
		vector<int> temp;
		for(i = 0; i < ni ;i++){
			getline(cin, toans);
			ss.str("");
			ss.clear();
			ss<<toans;
			a = 0; b = 0;
			temp = ansp;
			cout<<"test ans ";
			for(j =0; j <4; j++){
				ss>>ansi;
				cout<<"ansi "<<ansi<<"ans[j] "<<ans[j]<<" "<<endl;
				temp[ansi]--;
				if(ansi == ans[j])
					a++;
				else if(temp[ansi] >= 0)
					b++;
			}
			cout<<endl;
			cout<<a<<"A"<<b<<"B"<<endl;	
		}
	}
	
	return 0;
}