#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, P;
char s[100];

struct Company{
  Company(float price, int check, int index, string name){
    p = price;
    v = check;
    i = index;
    n = name;
  }
  float p;
  int v;
  int i;
  string n;
};

bool cmp(const Company& a, const Company& b){
  if(a.v != b.v){
    return a.v > b.v;
  } else if(a.p != b.p){
    return a.p < b.p;
  } else
    return a.i < b.i;
}

vector<Company> companies;

int main(){
  int T = 0;
  bool first = true;
  while(scanf("%d%d\n", &N, &P) == 2 && N+P){
    if(!first)
      puts("");
    else
      first = false;
    companies.clear();
    for(int i = 0; i < N; i++){
      gets(s);
    }
    for(int i = 0; i < P; i++){
      gets(s);
      string name(s);
      gets(s);
      float p; int v;
      sscanf(s, "%f %d", &p, &v);
      for(int j = 0; j < v; j++){
	gets(s);
      }
      companies.push_back(Company(p, v, i, name));
    }
    std::sort(companies.begin(), companies.end(), cmp);
    printf("RFP #%d\n%s\n", ++T, companies[0].n.c_str());
  }
}
