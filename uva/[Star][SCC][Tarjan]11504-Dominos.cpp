#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int T, N, L;
vector< vector<int> > edge;
int ansnum;

vector<int> visit;
int vnum;
vector<int> lowParent;
stack<int> s;
vector<bool> instack;
vector<int> contract;


//Tarjan: http://www.csie.ntnu.edu.tw/~u91029/Component.html#4
//
void DFS(int n){
  lowParent[n] = visit[n] = ++vnum;
  s.push(n);
  instack[n] = true;

  for(int i = 0; i < edge[n].size(); i++){
    int nowi = edge[n][i];
    if(!visit[nowi])
      DFS(nowi);
    if(instack[nowi])
      lowParent[n] = min(lowParent[n], lowParent[nowi]);
  }
  
  if(visit[n] == lowParent[n]){
    int i;
    do{
      i = s.top();
      s.pop();
      instack[i] = false;
      contract[i] = n;
    }while(i != n);
  }
}

void DoTarjan(){//hard algorithm...
  while(!s.empty())
    s.pop();
  instack.resize(N);
  std::fill(instack.begin(), instack.end(), false);
  lowParent.resize(N);
  contract.resize(N);
  visit.resize(N);
  std::fill(visit.begin(), visit.end(), 0);
  vnum = 0;
  for(int i = 0; i < N; i++){
    if(!visit[i])
      DFS(i);
  }
}

vector<bool> ismerged;
void MergeVertex(){
  ismerged.resize(N);
  std::fill(ismerged.begin(), ismerged.end(), false);
  ansnum = 0;
  for(int i = 0; i < N; i++){
    if(contract[i] != i){
      ismerged[i] = true;
      int newi = contract[i];
      edge[newi].insert(edge[newi].end(), edge[i].begin(), edge[i].end());
    }
  }
  for(int i = 0; i < N; i++)
    if(!ismerged[i])
      for(int j = 0; j < edge[i].size(); j++)
	edge[i][j] = contract[edge[i][j]];//transform to new index
}

void CalculateHeadVertex(){
  vector<bool> isHead(N);
  std::fill(isHead.begin(), isHead.end(), true);
  ansnum = 0;
  for(int i = 0; i < N; i++)
    if(!ismerged[i])
      for(int j = 0; j < edge[i].size(); j++)
	if(edge[i][j] != i)//it means it's part of cycle
	  isHead[edge[i][j]] = false;
  for(int i = 0; i < N; i++)
    if(isHead[i] && !ismerged[i])
      ansnum++;
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &N,&L);
    edge.clear(); edge.resize(N);
    int a, b;
    for(int i = 0; i < L; i++){
      scanf("%d %d", &a, &b);
      edge[a-1].push_back(b-1);
    }
    DoTarjan();
    MergeVertex();
    CalculateHeadVertex();
    printf("%d\n", ansnum);
  }
}
