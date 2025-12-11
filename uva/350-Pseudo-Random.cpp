#include <cstdio>
#include <set>
#include <map>
using namespace std;

int Z, I, M, L;
map<int, int> reverse;
set<int> s;
int cycleNum;

void generateNumber(){
  L = (Z*L + I) % M;
}

void getCycle(){
  s.clear(); reverse.clear();  int nowi = 0;
  reverse[L] = nowi++;
  s.insert(L);
  while(1){
    generateNumber();
    if(s.insert(L).second == false){//cycle
      cycleNum = nowi - reverse[L];
      return;
    } else
      reverse[L] = nowi++;
  }
}

int main(){
  int T = 1;
  while(scanf("%d%d%d%d", &Z, &I, &M, &L) == 4 && Z+I+M+L){
    getCycle();
    printf("Case %d: %d\n", T++, cycleNum);
  }
}
