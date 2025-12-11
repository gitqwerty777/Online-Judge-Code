#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

/*
  two queue(left, right) can fill stimultaniously, not one queue
 */

char s[10000];
int T, L, M;

queue<int> ql;
queue<int> qr;

int main(){
  scanf("%d\n", &T);
  int l;
  while(T--){
    scanf("%d%d\n", &L, &M);
    L *= 100;
    for(int i = 0;i < M; i++){
      gets(s);
      char* p = strtok(s, " ");
      int l;
      sscanf(p, "%d", &l);
      p = strtok(NULL, " ");
      if(strcmp(p, "right") == 0)
	qr.push(l);
      else
	ql.push(l);
    }
    int nowl = 0;
    int ans[2] = {0};
    while(!ql.empty()){
      if(ql.front() + nowl <= L){
	nowl += ql.front();
	ql.pop();
      } else {
	nowl = 0;
	ans[0]++;
      }
    }
    if(nowl)
      ans[0]++;
    nowl = 0;
    while(!qr.empty()){
      if(qr.front() + nowl <= L){
	nowl += qr.front();
	qr.pop();
      } else {
	nowl = 0;
	ans[1]++;
      }
    }
    if(nowl)
      ans[1]++;
    if(ans[0] > ans[1])
      ans[0] = ans[0]*2-1;
    else if(ans[1] >= ans[0])
      ans[0] = ans[1]*2;
    printf("%d\n", ans[0]);
  }
}
