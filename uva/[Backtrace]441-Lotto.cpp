#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> arr;
int ans[6];

void printAns(int d){
  if(d == 6){
    for(int i = 0; i < 5; i++)
      printf("%d ", arr[ans[i]]);
    printf("%d\n", arr[ans[5]]);
    return;
  }
  int starti = (d==0)?-1:ans[d-1];
  for(int i = starti+1; i < N-(5-d); i++){
    ans[d] = i;
    printAns(d+1);
  }
}

void printAllAns(){
  for(int i = 0; i < 6; i++)
    ans[i] = arr[i];
  printAns(0);
}

int main(){
  arr.resize(15);
  bool first = true;
  while(scanf("%d", &N) == 1 && N){
    if(!first)
      puts("");
    else
      first = false;
    for(int i = 0; i < N; i++){
      scanf("%d", &arr[i]);
    }
    std::sort(arr.begin(), arr.begin()+N);
    printAllAns();

  }
}
