#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
//hard to think this is a bipartite problem...
//I know it from uhunt

int T, J, S;//junction, street
vector< vector<int> > bipath;
vector< int > color;
int fillColorNum = 0;

int colorcount[2];
bool setColor(int n, int c){
  //printf("fill %d = %d\n", n, c);
  if(color[n] == -c)
    return false;
  else if(color[n] == c)
    return true;
  else{
    //printf("fill %d as %d\n", n, c);
    colorcount[(c*2+2)/4]++;//0 or 1
    color[n] = c;
  }
  bool isbi = true;
  for(int j = 0; j < bipath[n].size() && isbi; j++){
    if(bipath[n][j] == n)
      continue;
    isbi = isbi && setColor(bipath[n][j], -c);
  }
  return isbi;
}

int fillColor(){
  color.resize(J);
  std::fill(color.begin(), color.end(), 0);
  bool isFill =  true;
  int ans = 0;
  for(int i = 0; i < J && isFill; i++)
    if(color[i] == 0){
      colorcount[0] = 0;
      colorcount[1] = 0;
      isFill = isFill && setColor(i, 1);
      int minv = (colorcount[0]>colorcount[1])?colorcount[1]:colorcount[0];
      ans += (minv == 0)?1:minv;
    }
  if(isFill)
    return ans;
  else
    return -1;
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &J, &S);
    int a, b;
    bipath.resize(J);
    for(int i = 0; i < J; i++)
      bipath[i].clear();
    for(int i = 0; i < S; i++){
      scanf("%d %d", &a, &b);
      bipath[a].push_back(b);
      bipath[b].push_back(a);
    }
    printf("%d\n", fillColor());
  }
  return 0;
}
