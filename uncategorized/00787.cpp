#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;
#define MINL LLONG_MIN

int main(){
  int in;
  int count = 0;
  long long max = MINL, p = 1;
  vector<long long> v;
  while(scanf("%d", &in) == 1){
    if(in == -999){
      bool first = true; int minm;
      for(int i = 0; i < v.size(); i++){
	if(v[i] > max)
	  max = v[i];
	if(first && v[i] < 0){
	  minm = i;
	  first = false;
	}
	if(v[i] == 0){//at the end of a sequence
	  if(v[i-1] < 0 && i-1 != minm && v[i-1] / v[minm] > max){
	    max = v[i-1] / v[minm];
	  }
	  first = true;
	}
	//	printf("v[%d] = %lld\n", i, v[i]);
	if(i == v.size()-1 && v[i] < 0 && i != minm && v[i] / v[minm] > max)
	    max = v[i] / v[minm];
      }
      printf("%lld\n", max);
      v.clear();
      max = MINL;
    } else{//zero?, minus?, pos?
      v.push_back(in);
      if(v.size() >= 2 && v[v.size()-2] != 0){
	v[v.size()-1] *= v[v.size()-2];
      }
    }
  }
}