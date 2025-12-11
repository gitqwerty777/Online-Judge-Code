#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> poly;
char s[100000];

int getAns(int n){
  int base = 1;
  int ans = 0;
  for(int i = poly.size()-1; i >= 0; i--){
    ans += poly[i] * base;
    base *= n;
  }
  return ans;
}

int main(){
  while(gets(s)){
    poly.clear();
    char* p = strtok(s, " ");
    while(p != NULL){
      poly.push_back(atof(p));
      p = strtok(NULL, " ");
    }
    
    gets(s);
    bool first = true;
    p = strtok(s, " ");
    while(p != NULL){
      if(first){
	first = false;
      	printf("%d", getAns(atof(p)));}
      else
	printf(" %d", getAns(atof(p)));
      p = strtok(NULL, " ");
    }
    puts("");
  }
}
