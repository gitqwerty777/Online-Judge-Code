#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 2147483647
//Edmonds-Karp Algorithm
//http://pisces.ck.tp.edu.tw/~peng/index.php?action=showfile&file=f6cdf7ef750d7dc79c7d599b942acbaaee86a2e3e

int N, S, T, C;
vector< vector<int> > flow;
vector< vector<int> > edge;
queue<int> q;

vector<int> path;
vector<bool> isVisited;

void initFlow(){
  flow.resize(C);
  for(int i = 0; i < C; i++){
    flow[i].resize(C);
    std::fill(flow[i].begin(), flow[i].end(), 0);
  }
  while(!q.empty())
    q.pop();
  path.resize(C);
  isVisited.resize(C);
}

bool findShortestPath(){
  while(!q.empty()){
    q.pop();
  }
  std::fill(isVisited.begin(), isVisited.end(), false);
  q.push(S);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < C; i++){
      if(edge[u][i] == 0)
	continue;
      if(!isVisited[i]){
	path[i] = u;
	q.push(i);
	isVisited[i] = true;
	if(i == T)
	  return true;
      }
    }
  }
  return false;
}

int doAugment(){
  int c = INF;
  int v = T;
  while(v != S){//find min flow in the path
    c = min(c, edge[path[v]][v]);
    v = path[v];
  }
  //printf("add %d\n", c);
  v = T;
  //printf("path: %d -> ", T);
  while(v != S){//update flow(used) and edge(remain flow)
    //printf("%d -> ", path[v]);
    //flow[path[v]][v] += c;//not used
    //flow[v][path[v]] -= c;
    edge[v][path[v]] -= c;
    edge[path[v]][v] -= c;
    v = path[v];
  }
  return c;
}

int Edmonds_Karp(){
  int ans = 0;
  initFlow();
  while(findShortestPath()){
    ans += doAugment();
  }
  return ans;
}

int main(){
  int count = 1;
  while(scanf("%d", &N) == 1 && N){    
    scanf("%d %d %d", &S, &T, &C);
    S--; T--;
    edge.resize(C);
    for(int i = 0; i < C; i++){
      edge[i].resize(C);
      std::fill(edge[i].begin(), edge[i].end(), 0);
    }
    int a, b, c;
    for(int i= 0; i < C; i++){
      scanf("%d%d%d", &a, &b, &c);
      edge[a-1][b-1] += c;
      edge[b-1][a-1] += c;
    }
    printf("Network %d\nThe bandwidth is %d.\n\n", count++, Edmonds_Karp());//fuxk you! format
  }
}
