#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

//http://www.csie.ntnu.edu.tw/~u91029/Component.html#1
// problem meaning: find point to make the graph disconnected

int N;
int count;
char *ss = new char[1000];
vector< vector<bool> > edge;
vector<int> depth;
vector<int> lowestAncestor;
int nowdepth;

void DFS(int p, int n){
  nowdepth++;
  depth[n] = nowdepth;
  lowestAncestor[n] = nowdepth;

  int child = 0;
  bool notConnected = false;
  for(int i = 0; i < N; i++){
    if(edge[n][i] && i != p){
      int nowe = i;
      if(depth[nowe]){//back
	lowestAncestor[n] = min(lowestAncestor[n], depth[nowe]);
      } else {
	child++;
	DFS(n, nowe);
	lowestAncestor[n] = min(lowestAncestor[n], lowestAncestor[nowe]);
	if(lowestAncestor[nowe] >= depth[n])//my child cannot connect my ancestor
	  notConnected = true;
      }
    }
  }
  if((n == p && child > 1) || (n != p && notConnected)){
    count++;
  }
}
void findCutVertex(){
  depth.resize(N);
  std::fill(depth.begin(), depth.end(), 0);
  lowestAncestor.resize(N);
  std::fill(lowestAncestor.begin(), lowestAncestor.end(), 0);
  count = 0;
  nowdepth = 0;
  for(int i = 0; i < N; i++)
    if(!depth[i]){
      	DFS(i, i);
}

int main(){
  while(scanf("%d", &N) == 1 && N){
    edge.clear();
    edge.resize(N);
    for(int i = 0; i < N; i++){
      edge[i].resize(N);
      std::fill(edge[i].begin(), edge[i].end(), false);
    }
    while(gets(ss)){
      if(strcmp(ss, "0") == 0)
	break;
      if(strcmp(ss, " ") == 0)
	continue;
      int b, n, offset;
      char *s = ss;
      sscanf(s, "%d%n", &b, &offset);
      b--;
      s += offset;
      //http://stackoverflow.com/questions/12683775/sscanf-iterative-loop-for-float-numbers
      while(sscanf(s, "%d%n", &n, &offset) > 0){
	s += offset;
	n--;
	edge[b][n] = true;
	edge[n][b] = true;
      }
    }
    findCutVertex();
    printf("%d\n", count);
  }
}
