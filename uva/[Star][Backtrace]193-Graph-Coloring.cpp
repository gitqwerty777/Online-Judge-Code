#include <cstdio>
#include <vector>
using namespace std;

int T;
int N, E;
int maxBlack;
bool maxAns[105];
bool ans[105];
vector< vector<int> > edge;

void findAns(int d, int blacknum){
  if(d == 0){
    //fill node 1(0)
    bool isBlack = true;
    for(int i = 0; i < edge[0].size(); i++)
      if(ans[edge[0][i]]){
	isBlack = false;
	break;
      }
    if(isBlack){ blacknum++; ans[0] = true;}
    if(blacknum > maxBlack){
      maxBlack = blacknum;
      for(int i = 0; i < N; i++)
	maxAns[i] = ans[i];
    }
  } else {
    //fill black
    bool isBlack = true;
    for(int i = 0; i < edge[d].size(); i++){
      if(ans[edge[d][i]]){
	isBlack = false;
	break;
      }
    }
    if(isBlack){//can fill black
      ans[d] = true;
      findAns(d-1, blacknum + 1);
      for(int i = d-1; i >= 0; i--)//cleanup
	ans[i] = false;
    }
    //fill white
    ans[d] = false;
    findAns(d-1, blacknum);
  }
}

void findPossibleAns(){
  std::fill(ans, ans+N, false);
  maxBlack = 0;
  findAns(N-1, 0);
}

void printAns(){
  printf("%d\n", maxBlack);
  bool first = true;
  for(int i = 0; i < N; i++){
    if(maxAns[i]){
      if(!first)
	putchar(' ');
      else
	first = false;
      printf("%d", i+1);
    }
  }
  puts("");
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &N, &E);
    edge.clear();
    edge.resize(N);
    int a, b;
    for(int i = 0; i < E; i++){
      scanf("%d%d", &a, &b);
      a--; b--;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
    findPossibleAns();
    printAns();
  }
}
