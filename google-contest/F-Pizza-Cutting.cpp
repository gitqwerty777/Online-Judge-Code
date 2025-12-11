#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct top{
  double tan;
  double argtan;
  int pre;
};

bool cmp(top a, top b){//reference - no
  return a.argtan < b.argtan;
}

int main(){
  int T, N;
  int p, x, y;
  vector<top> v;
  scanf("%d", &T);
  int u, d;//up down
  while(T--){
    scanf("%d", &N);
    v.resize(N);
    u = 0; d = 0;
    for(int i = 0; i < N; i++){
      scanf("%d %d %d", &v[i].pre, &x, &y);
      v[i].tan = double(x) / double(y);//precision?
      v[i].argtan = atan2(y, x);//why not x, y?
      if(y > 0)//no y == 0
	u += v[i].pre;
      else if(y < 0)
	d += v[i].pre;
    }
    sort(v.begin(), v.end(), cmp);
    //轉半圈
    int i = 0, j = N-1;
    while(i < j){
      if(M_PI/2 - v[j].argtan > v[i].argtan - M_PI/2){//逆時針larger
	//
      }
    }
  }
  return 0;
}
