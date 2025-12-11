#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

/*
只要反覆尋找沒有被任何邊連向的點，然後刪去此點以及刪去由此點連出去的邊，就可以找出一個合理的排列順序了。
 */

int M, N;
map<int, vector<int> > adj;
map<int, int> visit;
vector<int> order;
bool cycle;
int mi;

void DFS(int n){
  if(visit[n] == 1) cycle = true;
  if(visit[n] == 2) return; //already in tree

  visit[n] = 1;
  for(int i = 0; i < adj[n].size(); i++){
    DFS(adj[n][i]);//find next node
  }
  visit[n] = 2;

  order.push_back(n);
}

void find_topological_order(){
  for(int i = 1; i <= M; i++)
    if(visit[i] == 0)
      DFS(i);
}

void print_order(){
  for(int i = M-1; i >= 1; i--)//should reverse it
    printf("%d ", order[i]);
  printf("%d", order[0]);
  puts("");
}

int main(){
  int a, b;
  while(scanf("%d %d", &M, &N) == 2 && M + N){//N could be zero...
    adj.clear();
    visit.clear();
    order.clear();
    for(int i = 0; i < N; i++){
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
    }
    find_topological_order();
    print_order();
  }
  return 0;
}
