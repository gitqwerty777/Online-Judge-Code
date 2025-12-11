#include <cstdio>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

int S, N;

//c++11

struct number{
  int v;
  int n;
};

number arr[15];
int arrsize;
int ans[15];
bool hasAns;
void findAns(int d, int s){
  if(d == arrsize){
    if(s != S)
      return;
    hasAns = true;
    bool first = true;
    for(int i = 0; i < arrsize; i++){
      for(int j = 0; j < ans[i]; j++){
	if(!first)
	  putchar('+');
	else
	  first = false;
	printf("%d", arr[i].v);
      }
    }
    puts("");
  } else {
    //printf("now depth = %d, sum = %d\n", d, s);
    for(int i = arr[d].n; i >= 0; i--){
      if(s+arr[d].v*i > S)
	continue;
      ans[d] = i;
      findAns(d+1, s+arr[d].v*i);
    }
  }
}

int main(){
  int input[15];
  map<int, int, std::greater<int> > m;
  while(scanf("%d%d", &S, &N) == 2 && S+N){
    hasAns = false;
    m.clear();
    for(int i = 0; i < N; i++){
      scanf("%d", &input[i]);
      m[input[i]]++;
    }
    int count = 0;
    for(auto it = m.begin(); it != m.end(); it++){
      arr[count].v = it->first;
      arr[count++].n = it->second;
    }
    arrsize = count;
    printf("Sums of %d:\n", S);
    findAns(0, 0);
    if(!hasAns)
      puts("NONE");
  }
}
