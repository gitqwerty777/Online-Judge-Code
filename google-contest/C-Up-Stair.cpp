#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, F, B;
  vector<int> worker;
  int inf, inb;
  int minf;
  scanf("%d", &N);//dummy
  while(scanf("%d %d %d", &N, &F, &B) == 3){
    minf = F;
    worker.clear();
    for(int i = 0; i < N; i++){
      scanf("%d %d", &inf, &inb);
      if(inb == 1){
	worker.push_back(3*F-inf);//from start to second package
      } else {
	worker.push_back(F+inf);//from start to first package
      }
    }
    sort(worker.begin(), worker.end());
    int count = 0;
    while(B > N){
      count++;
      B -= N;
    }
    int timesum;
    if(B > 0)
      timesum = count * 2 * F + worker[B-1];
    else
      timesum = count * 2 * F;
    printf("%d\n", timesum);
  }
  //assume worker's box are send, calculate the time they send to 
  return 0;
}
