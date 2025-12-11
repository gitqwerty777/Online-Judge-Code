#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int binary_search(vector<int>& t, int n){
  int start = 0, end = t.size()-1;
  int mid = (start + end) / 2;
  while(start < end){
    if(t[mid] > n){
      end = mid;
    } else if(t[mid] < n){
      start = mid;
    } else {
      return mid;
    }
    mid = (start + end) / 2;
  }
  return start;
}
/*
struct num{
  num(){
    len = 1;
    prev = -1;
  }
  int len;
  int prev;
  };*/

int main(){
  /*  vector<int> v;
  v.reserve(100000);
  int in;
  while(scanf("%d", &in) == 1){
    v.push_back(in);
  }
  int N = v.size();
  if(N == 0){
    puts("0");
    return 0;
  }
  vector<num> n;
  n.resize(N);
  
  for(int i = 0; i < N; i++)
    for(int j = i+1; j < N; j++)
      if(v[i] < v[j] && n[i].len+1 >= n[j].len){//use for last instance
	  n[j].len = n[i].len + 1;
	  n[j].prev = i;
	}
  int maxlen = n[0].len, maxi = 0;
  for(int i = 1; i < N; i++)
    if(n[i].len >= maxlen){
      maxi = i;
      maxlen = n[i].len;
    }

  stack<int> s;
  s.push(maxi);
  int temp = maxi;
  while(n[temp].prev != -1){
    temp = n[temp].prev;
    s.push(temp);
  }

  //print ans
  printf("%d\n-\n", maxlen);
  while(!s.empty()){
    printf("%d\n", v[s.top()]);
    s.pop();
  }
  return 0;
  */

  // using Robinson-Schensted-Knuth Algorithm -> O(NlogL)
  //ref:http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html#2
  vector<int> v;
  v.reserve(100000);
  int in;
  while(scanf("%d", &in) == 1)
    v.push_back(in);

  int N = v.size();
  if(N == 0){
    puts("0");
    return 0;
  }
  vector<int> t, p;//templen, pos
  t.push_back(v[0]);
  p.resize(N);
  for(int i = 1; i < N; i++){
    int n = v[i];
    if(n > t.back()){
      t.push_back(n);
      p[i] = t.size()-1;
    } else {
      vector<int>::iterator pt = lower_bound(t.begin(), t.end(), n);//good function
      //ref:http://www.cplusplus.com/reference/algorithm/lower_bound/
      //http://www.cnblogs.com/cobbliu/archive/2012/05/21/2512249.html
      //int pos = complete_search(t, n);      -> not good way
      int pos = pt-t.begin(); //good way to use
      t[pos] = n;
      p[i] = pos;
    }
  }

  //print ans
  int maxlen = t.size();
  printf("%d\n-\n", maxlen);
  t.clear();
  int tmpi = maxlen;
  stack<int> s;
  for(int i = N-1; i >= 0; i--){
    if(p[i] == tmpi-1){
      
      s.push(v[i]);
      tmpi--;
    }
  }
  while(!s.empty()){
    printf("%d\n", s.top());
    s.pop();
  }
  
  return 0;
}