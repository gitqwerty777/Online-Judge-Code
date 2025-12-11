#include <stdio.h>
#include <vector>
using namespace std;

int N, L;
vector< vector<int> > bipath;
vector<int> color;
//because problem says each node have path to every other node, so it can be totally filled by deciding color of one node

bool setColor(int n, int c){
  //printf("fill %d = %d\n", n, c);
  if(color[n] == -c)
    return false;
  else if(color[n] == c)
    return true;
  else
    color[n] = c;
  bool isbi = true;
  for(int j = 0; j < bipath[n].size() && isbi; j++){
    isbi = isbi && setColor(bipath[n][j], -c);
  }
  return isbi;
}

int main(){
  int a, b;
  while(scanf("%d", &N) == 1 && N){
    scanf("%d", &L);
    bipath.resize(N);
    for(int i = 0; i < N; i++)
      bipath[i].clear();
    for(int i = 0; i < L; i++){
      scanf("%d %d", &a, &b);
      bipath[a].push_back(b);
      bipath[b].push_back(a);
    }
    color.resize(L);
    std::fill(color.begin(), color.end(), 0);
    printf("%s\n", setColor(0, 1)?"BICOLORABLE.":"NOT BICOLORABLE.");
    
  }
  return 0;
}

