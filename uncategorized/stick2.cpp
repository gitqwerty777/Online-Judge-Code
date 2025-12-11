#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

bool DFS(vector<int> stick,int &vertex, int &sticklo, int nowver, int nowlo){//1. 用vvector以外 2.大數先解決
	if(nowlo == sticklo){
		nowver++;
		nowlo = 0;
		if(nowver == vertex){
			if(stick.empty())
				return true;
			else
				return false;
		}
	}
	else if(stick.empty())
		return false;
	
	int plus, i;
	for(i = 0; i < stick.size(); i++){
		if(nowlo + stick[i] <= sticklo){
			vector<int> temp(stick);
			plus = stick[i];
			//cout<<"plus"<<plus<<endl;
			temp.erase(temp.begin()+i);
			if(DFS(temp, vertex, sticklo ,nowver, nowlo + plus))
				return true;
		}
	}
	
	return false;
}

int comp(int a, int b){
	return a > b;
}
int main(){
	int n; string in; int vertex, stick_num; stringstream ss; double sticklo;
	vector<int> stick;
	
	cin>>n;
	getline(cin, in);//dumb

	while(n--){
		scanf("%d %d", &vertex, &stick_num);
		
		stick.resize(stick_num);
		int sum = 0;
		for(int i = 0; i < stick_num; i++){
			scanf("%d", &stick[i]);
			sum += stick[i];
		}
		
		sticklo = double(sum) / double(vertex);
		if(int(sticklo) != sticklo){
			puts("0");
			continue;
		}
		
		sort(stick.begin(), stick.end(), comp);
		if(sticklo < stick[0]){
			puts("0");
			continue;
		}
		/*
		int max = 100, min = 1;
		while(stick[max] == 0)
			max--;
		while(stick[min] == 0)
			min++;
		if(sticklo < max){
			cout<<"0"<<endl;
			continue;
		}
		
		
		int bu;
		if(sticklo >= 100)
			bu = sticklo - 100;
		else
			bu = 0;
		for(int i = bu; i < 101; i++){//ok?不影響？
			if(stick[sticklo - i] && stick[i])
				while(stick[sticklo - i] && stick[i]){
					stick[sticklo - i] --;
					stick[i]--;
					vertex--;
				}
		}
		*/
		if(vertex == 0 && stick.empty())
			puts("1");
		else if(DFS(stick, vertex, stickloint, 0, 0))
			puts("1");
		else
			puts("0");
	}

	return 0;
}