#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

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

int vertex, stick_num; double sticklo;int stickloint;int stick[31]; bool isuse[31];

bool DFS(int nowindex, int nowver, int nowlo){
	
	int plus, i;
	for(i = nowindex; i < stick_num; i++){
		if(!isuse[i] && nowlo + stick[i] <= stickloint){
			//cout<<"plus"<<plus<<endl;
			isuse[i] = true;
			
			if(nowlo + stick[i] == stickloint){
				if((nowver + 1 == vertex - 1) || DFS(nowver+1, nowver+1, 0))//nowver op
					return true;}
			else{
				if(DFS(i+1, nowver, nowlo+stick[i]))
					return true;}
			
			isuse[i] = false;
			while(i+1 < stick_num && stick[i] == stick[i+1])
				i++;
		}
	}
	//找不到組合
	return false;
}

int comp(int a, int b){
	return a > b;
}

int main(){
	int n;

	n = Input();
	
	while(n--){
		vertex = Input();
		stick_num = Input();
		
		int sum = 0, max = 0;
		for(int i = 0; i < stick_num; i++){
			stick[i] = Input();
			if(stick[i] > max)
				max = stick[i];
			sum += stick[i];
		}
		
		sticklo = double(sum) / double(vertex);
		stickloint = int(sticklo);
		if(stickloint != sticklo || max > stickloint){
			puts("0");
			continue;
		}
		
		sort(stick, stick+stick_num, comp);
		
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
		
		memset(isuse, false, sizeof(bool)*stick_num);
		if(DFS(0 , 0, 0))
			puts("1");
		else
			puts("0");
	}

	return 0;
}
