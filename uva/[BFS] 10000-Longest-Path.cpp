#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <stack>
#include <cstring>
#include <vector>
#define MAX 101

using namespace std;

list<int> road[MAX];//100 100 
vector<int> layer;//³Ìªø
int length[MAX];

int Input(){  
    char cha;  
    int x=0;  
    while(cha=getchar())  
        if((cha >= 48 && cha < 58) || cha == EOF) break;
	if(cha == EOF) return -1;
    x=cha-48;
    while(cha=getchar()) {  
        if(cha < 48 || cha >= 58) break;  
        x=x*10+cha-48;  
    }  
    return x;
}

struct Ans{
	int l;
	int f;
};

Ans checkLong(int s, int n){//BFS
	list<int>::iterator i;
	vector<int> templay;
	
	int len = 0;
	length[s] = len++;
	layer.clear();
	
	for(i = road[s].begin(); i != road[s].end(); i++){
		if(length[*i] != len){
			length[*i] = len;
			layer.push_back(*i);
		}
	}
	
	while(!layer.empty()){
		len++;
		for(int j = 0; j < layer.size(); j++)
			for(i = road[layer[j]].begin(); i != road[layer[j]].end(); i++){
				if(length[*i] != len){
					length[*i] = len;
					templay.push_back(*i);
				}
			}
		layer = templay;
		templay.clear();
	}
	len--;
	
	Ans maxans;
	maxans.l = len;
	for(int j = 1; j <= n; j++){
		if(length[j] == len){
			maxans.f = j;
			break;
		}}
	
	return maxans;
}

int main(){
	int n, s, a, b;
	int count = 1;
	int fin, l;
	Ans ans;
	
	n = Input();
	while(n){
		s = Input();
		a = Input();
		b = Input();
		
		memset(length, -1, sizeof(int) * (n+1));
		while(a){
			road[a].push_back(b);
			a = Input();
			b = Input();}
		
		ans = checkLong(s, n);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", count, s, ans.l, ans.f);
		count++;
		for(int i = 1; i <= n; i++){
			road[i].clear();}
		n = Input();
	}
	return 0;
}
