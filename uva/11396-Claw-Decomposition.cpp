#include <cstdio>
#include <vector>
using namespace std;

int N;
vector< vector<int> > edge;
vector<int> color;

bool fillcolor(int n, int c){
  if(color[n] == -c)
    return false;
  else if(color[n] == c)
    return true;
  else{
    color[n] = c;
    bool isbi = true;
    for(int i = 0; i < edge[n].size() && isbi; i++)
      isbi = isbi && fillcolor(edge[n][i], -c);
    return isbi;
  }
}

bool findClaw(){
  color.clear();
  color.resize(N);
  std::fill(color.begin(), color.end(), 0);
  for(int i = 0; i < N; i++){
    if(color[i] == 0){
      if(!fillcolor(i, 1))
	return false;
    }
  }
  return true;
}

int main(){
  while(scanf("%d", &N) == 1 && N){
    edge.clear();
    edge.resize(N);
    int a, b;
    while(scanf("%d %d", &a, &b) == 2 && a+b){
      edge[a-1].push_back(b-1);
      edge[b-1].push_back(a-1);
    }
    printf("%s\n", findClaw()?"YES":"NO");
  }
}
