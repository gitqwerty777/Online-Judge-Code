#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int T, N, R;
vector<pair<int, int> > vertex;

inline double getDistance(int ai, int bi){
  double x = vertex[ai].first - vertex[bi].first;
  double y = vertex[ai].second - vertex[bi].second;
  return sqrt(x*x + y*y);
}

struct Edge{
  Edge(int ai, int bi){
    index[0] = ai; index[1] = bi;
    length = getDistance(ai, bi);
    //printf("%d, %d distance = %d\n", ai, bi, int(length));
  }
  bool operator<(const struct Edge e) const{
    return this->length < e.length;
  }
  double length;
  int index[2];
};

vector<Edge> edge;
int stateNum;
double roadNum, railNum;

//https://zh.wikipedia.org/zh-tw/%E5%85%8B%E9%B2%81%E6%96%AF%E5%85%8B%E5%B0%94%E6%BC%94%E7%AE%97%E6%B3%95
void DoKruskal(){
  stateNum = 1;
  roadNum = railNum = 0;
  vector<int> g(N);
  for(int i = 0; i < g.size(); i++)
    g[i] = i;
  
  for(int i = 0; i < edge.size(); i++){
    int ai = edge[i].index[0], bi = edge[i].index[1];
    if(g[edge[i].index[0]] != g[edge[i].index[1]]){
      int mini = min(g[edge[i].index[0]], g[edge[i].index[1]]);
      int maxi = max(g[edge[i].index[0]], g[edge[i].index[1]]);  
      g[edge[i].index[0]] = g[edge[i].index[1]] = mini;
      if(maxi != mini)//stupid way
	for(int k = 0; k < g.size(); k++)
	  if(g[k] == maxi)
	    g[k] = mini;

      if(edge[i].length >= R){
	stateNum++;
	railNum += edge[i].length;
      } else{
	roadNum += edge[i].length;
      }
    }
  }
}

int main(){
  scanf("%d", &T);
  int count = 1;
  while(T--){
    vertex.clear(); edge.clear();
    scanf("%d%d", &N, &R);
    int a, b;
    for(int i = 0; i < N; i++){
      scanf("%d%d", &a, &b);
      vertex.push_back(pair<int, int>(a, b));
    }
    for(int i = 0; i < N; i++)
      for(int j = i+1; j < N ;j++)
	edge.push_back(Edge(i, j));
    std::sort(edge.begin(), edge.end());
    DoKruskal();
    if(roadNum - int(roadNum) >= 0.5)
      roadNum += 1;
    if(railNum - int(railNum) >= 0.5)
      railNum += 1;
    
    printf("Case #%d: %d %d %d\n", count++, int(stateNum), int(roadNum), int(railNum));
  }
}
