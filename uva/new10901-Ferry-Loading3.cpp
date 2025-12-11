#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int T, N, t, C;
queue<int> ql;
queue<int> il;
queue<int> qr;
queue<int> ir;
vector<int> ans;
int mindir;
char s[100];

/*
1
1 5 2
0 left
0 left

5
15

what the fuck is it?
 */

//this question no need two queue because ship will move if some car is waiting or on the ship.

struct car{
  car(int index, int time, int dir){
    i = index;
    t = time;
    d = dir;
  }
  int i;
  int t;
  int d;
}

int main(){
  scanf("%d\n", &T);
  while(T--){
    scanf("%d%d%d\n", &N, &t, &C);
    ans.clear();
    ans.resize(C);
    for(int i = 0; i < C; i++){
      gets(s);
      char *p = strtok(s, " ");
      int ct;
      sscanf(p, "%d", &ct);
      p = strtok(NULL, " ");
      if(strcmp(p, "left") == 0){
	q.push(car(ct, i, -1));
      } else{
	q.push(car(ct, i, 1));
      }
    }
    int nowd = -1;
    int nowt = 0;
    int nown = 0;
    bool first = true;
    ql.push(q.front());
    q.pop();
    while(!q.empty()){
      if(q.front().d != ){
	godir(-1);
	
      }
    }
      
    for(int i = 0; i < ans.size(); i++)
      printf("%d\n", ans[i]);
    if(T)
      puts("");
  }
}
