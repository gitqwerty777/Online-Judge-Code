#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int T, R,C,M,N,W, r, c;
vector< vector<bool> > isWater;

class Point{
public:
  int r, c;
  Point(){
  }
  Point(int rr, int cc){
    r = rr;
    c = cc;
  }
  bool checkAvaliable(){
    return r >= 0 && r < R && c >= 0 && c < C && !isWater[r][c];
  }		   		    
  vector<Point> move(vector<Point>& plist){
    plist.push_back(Point(r+M, c+N));
    plist.push_back(Point(r+M, c-N));
    plist.push_back(Point(r-M, c+N));
    plist.push_back(Point(r-M, c-N));
    plist.push_back(Point(r+N, c+M));
    plist.push_back(Point(r+N, c-M));
    plist.push_back(Point(r-N, c+M));
    plist.push_back(Point(r-N, c-M));
    return plist;
  }
};
typedef class Point point;
bool isVisited(point& p, vector<point>& visited);

int main(){
  scanf("%d", &T);
  for(int t = 0; t < T; t++){
    scanf("%d %d %d %d %d", &R, &C, &M, &N, &W);
    isWater.resize(R);
    for(int i = 0; i < R; i++){
      isWater[i].resize(C);
      std::fill(isWater[i].begin(), isWater[i].end(), false);
    }
    for(int i = 0; i < W; i++){
      scanf("%d %d", &r, &c);
      isWater[r][c] = true;
    }
    stack<point> movelist;
    movelist.push(point(0,0));
    vector< vector<bool> > visited;
    visited.clear();
    visited.resize(R);
    for(int i = 0; i < R; i++){
      visited[i].resize(C);
      std::fill(visited[i].begin(), visited[i].end(), false);
    }
    vector<int> ans;//even and odd
    ans.resize(2); ans[0] = 0; ans[1] = 0;
    point nowp;
    vector<point> nextplist;
    while(!movelist.empty()){
      while(!movelist.empty() && visited[movelist.top().r][movelist.top().c]){
	movelist.pop();	
      }
      if(movelist.empty()){
	break;
      }	
      nowp = movelist.top();
      movelist.pop();
      visited[nowp.r][nowp.c] = true;
      nextplist.clear();
      nowp.move(nextplist);
      int count = 0;
      for(int i = 0; i < nextplist.size(); i++){
	if(nextplist[i].checkAvaliable()){
	  movelist.push(nextplist[i]);
	  count++;
	}
      }
      if(M == 0 || N == 0 || M == N){//duplicate...
	count = count/2;
      }
      ans[count%2]++;
    }
    printf("Case %d: %d %d\n", t+1, ans[0], ans[1]);
  }
}
