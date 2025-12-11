#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

//C++11

int T, B, O;
struct beverage{
  /*void addParent(int p){
    parent.push_back(p);
    count++;
  }
  void removeParent(int p){
    auto it = std::find(parent.begin(), parent.end(), p);
    parent.erase(it);
    count--;
  }
  vector<int> parent;*/
  vector<int> child;
  int count;
};
vector<beverage> v;
vector<int> a;
vector<bool> isVisited;
 
void TopologicalSort(){
  a.clear();  
  isVisited.resize(B);
  std::fill(isVisited.begin(), isVisited.end(), false);
  while(a.size() < B){
    for(int i = 0; i < v.size(); i++){
      if(v[i].count == 0 && !isVisited[i]){
	isVisited[i] = true;
	for(int j = 0; j < v[i].child.size(); j++){
	  v[v[i].child[j]].count--;
	}
	a.push_back(i);
	break;
      }
    }
  }
}

int main(){
  T = 1;
  char s[150];
  while(1){
    if(scanf("%d\n", &B) != 1)
      break;
    v.clear(); v.resize(B);
    map<string, int> m;
    m.clear();
    vector<string> reversemap;
    reversemap.clear();

    for(int i = 0; i < B; i++){
      gets(s); string cs(s);
      m[cs] = i;
      reversemap.push_back(cs);
    }
    scanf("%d\n", &O);
    for(int i = 0; i < O; i++){
      gets(s); string cs(s);
      int space = cs.find(" ");
      string b1 = cs.substr(0, space), b2 = cs.substr(space+1, cs.size());
      int i1 = m[b1], i2 = m[b2];
      //v[i2].addParent(i1);
      v[i2].count++;
      v[i1].child.push_back(i2);
    }
    TopologicalSort();
    printf("Case #%d: Dilbert should drink beverages in this order:", T++);
    for(int i: a){
      printf(" %s", reversemap[i].c_str());
    }
    puts(".");
    puts("");
  }
  return 0;
}
