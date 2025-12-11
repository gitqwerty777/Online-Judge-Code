#include <stdio.h>
#include <vector>
using namespace std;

long long N, ans[2];
long long arr[32];
vector<int> one;

void getArr(){
  arr[0] = 1;
  for(int i = 1; i < 32; i++)
    arr[i] = arr[i-1] * 2;
}

void split(){
  int nowi = 0;
  one.clear();
  while(N>0){
    if(N%2)
      one.push_back(nowi);
    N /= 2;
    nowi++;
  }
}

void getAns(){
  ans[0] = ans[1] = 0;
  int nowansi = 0;
  for(int i = 0; i < one.size(); i++){
    ans[nowansi] += arr[one[i]];
    nowansi = (nowansi == 0)?1:0;
  }
}

int main(){
  getArr();
  while(scanf("%lld", &N)==1 && N){
    split();
    getAns();
    printf("%lld %lld\n", ans[0], ans[1]);
  }
}
