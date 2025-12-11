#include <stdio.h>
#include <string>
#include <list>
using namespace std;

//list is better than vector because it's implemented by link list

char s[100010];
list<string> l;

int main(){
  while(gets(s)){
    string ss(s);
    int starti = 0;
    bool isfront = false;
    l.clear();
    for(int i = 0; i < ss.size(); i++){
      if(ss[i] == '[' || ss[i] == ']'){
	string stok = ss.substr(starti, i-starti);
	//printf("stok  = %s\n", stok.c_str());
	starti = i+1;
	if(isfront)
	  l.push_front(stok);
	else
	  l.push_back(stok);
	isfront = (ss[i] == '[');
      }
    }
    string stok = ss.substr(starti, ss.size()-starti);
    //printf("stok  = %s\n", stok.c_str());
    if(isfront)
      l.push_front(stok);
    else
      l.push_back(stok);

    
    while(!l.empty()){
      string stok = l.front();
      l.pop_front();
      printf("%s", stok.c_str());
    }
    puts("");
  }
}
