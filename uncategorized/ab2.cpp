#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <cassert>

using namespace std;//test getline and cin line
void toint(string &in, int *temp){
	int count = 0; int lo = in.size();
	for(int i = 0; i < lo; i++)
		if(isdigit(in[i])){
			temp[count++] = in[i] - '0';
			if(count == 4)
				break;
		}
}
int min(int a, int b){
	return a < b ? a : b;
}
int main(){
	string anss; int ans[4]; int n; string dumb; string in; int temp[4]; int a, ab;
	stringstream ss;
	int ten[10], toten[10]; vector<int> inten;
	int i, j;
	
	while(getline(cin, anss)){
		if(anss.empty())
			continue;
		toint(anss, ans);
		cin>>n;
		getline(cin, dumb);
		
		memset(ten, 0, sizeof(int)*10);
		
		inten.clear();
		for(i = 0; i < 4; i++){
			ten[ans[i]]++;
			if(ten[ans[i]] == 1)
				inten.push_back(ans[i]);
		}
		for(i = 0; i < n; i++){
			memset(toten, 0, sizeof(int)*10);
			getline(cin, in);
			
			toint(in, temp);
			//ss.str("");
			//ss.clear();
			//ss<<in;
			
			a = 0; ab = 0;
			for(j = 0; j < 4; j++){
				toten[temp[j]]++;
				if(temp[j] == ans[j])
					a++;
			}
			
			for(j = 0; j < inten.size(); j++)
				ab += min(ten[inten[j]], toten[inten[j]]);
			
			
			cout<<a<<"A"<<ab-a<<"B"<<endl;
		}
		
	}
	
	return 0;
}