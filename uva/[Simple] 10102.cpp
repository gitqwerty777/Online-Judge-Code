#include <stdio.h>
#include <string.h>
#include <vector>

struct point{
  point(int i, int j){
    x = i; y = j;
  }
  int x, y;
};
typedef struct point p;
//http://www3.tcgs.tc.edu.tw/~sagit/luckycat/q10102.htm

inline int abs(int a){
  return (a>0)?a:-a;
}

inline int dist(p &a, p &b){
  return abs(a.x-b.x) + abs(a.y-b.y);
}

int main(){
  int N;
  std::vector<p> v1, v2;
  char c;
  while(scanf("%d", &N) == 1){
    v1.clear(); v2.clear();
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++){
	while((c = getchar()) == '\n')
	  continue;
	if(c == '1'){
	  v1.push_back(p(i,j));
	} else if(c == '3'){
	  v2.push_back(p(i,j));
	}
      }
    int max = 0;
    for(int i = 0; i < v1.size(); i++){
      int min = dist(v1[i], v2[0]);
      for(int j = 1; j < v2.size() && min > max; j++){
	int d = dist(v1[i], v2[j]);
	if(d < min)
	  min = d;
      }
      //      printf("min start from(%d, %d) = %d\n", v1[i].x, v1[i].y, min);
      if(min > max)
	max = min;
    }
    printf("%d\n", max);
  }
  return 0;
}