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

int mintime(int d){
  if(ql.empty()){
    mindir = 1;
    return qr.front();
  } else if(qr.empty()){
    mindir = -1;
    return ql.front();
  } else{
    if(qr.front() == ql.front()){
      mindir = d;
      if(d == -1)
	return ql.front();
      else
	return qr.front();
    } else {
      if(qr.front() > ql.front()){
	mindir = -1;
	return ql.front();
      } else {
	mindir = 1;
	return qr.front();
      }
    }
  }
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
	ql.push(ct);
	il.push(i);
      } else{
	qr.push(ct);
	ir.push(i);
      }
    }
    int nowd = -1;
    int nowt = 0;
    int nown = 0;
    bool first = true;
    while(!ql.empty() || !qr.empty()){
      if(nowd == -1 && !ql.empty() && ql.front() <= nowt){
	//nowt = ql.front();
	ql.pop();
	nown++;
	if(ql.empty() || first || ql.front() > nowt || nown == C){//go to right
	  first = false;
	  nowt += t;
	  for(int i = 0; i < nown; i++){
	    ans[il.front()] = nowt;
	    //printf("ans left:nowt = %d, dir = %d\n", nowt, nowd);
	    il.pop();
	  }
	  nown = 0;
	  nowd *= -1;
	}
	//	printf("left:nowt = %d, dir = %d\n", nowt, nowd);
      } else if(nowd == 1 && !qr.empty() &&qr.front() <= nowt){
	//nowt = qr.front();
	qr.pop();
	nown++;
	if(qr.empty() || first || qr.front() > nowt || nown == C){//go to left
	  first = false;
	  nowt += t;
	  for(int i = 0; i < nown; i++){
	    ans[ir.front()] = nowt;
	    ir.pop();
	  }
	  nown = 0;
	  nowd *= -1;
	} 
	//printf("right:nowt = %d, dir = %d\n", nowt, nowd);
      } else {
	nowt = max(nowt, mintime(nowd));
	if(mindir != nowd){
	  //printf("before wait:nowt = %d, dir = %d\n", nowt, nowd);	  
	  nowt += t;
	  nowd *= -1;
	}
	//printf("wait:nowt = %d, dir = %d\n", nowt, nowd);
      }
    }
    while(!il.empty()){
      ans[il.front()] = nowt+t;
      il.pop();
    }
    while(!ir.empty()){
      ans[ir.front()] = nowt+t;
      ir.pop();
    }
    for(int i = 0; i < ans.size(); i++)
      printf("%d\n", ans[i]);
    if(T)
      puts("");
  }
}
