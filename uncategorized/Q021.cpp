#include <stdio.h>
#include <list>
#include <stdlib.h>
#include <ctype.h>
#define MAXVOTER 20000000
using namespace std;

class voter{
public:
  voter(){
    v = -1;
  }
  int v;//0~3
  std::list<struct voter*> c;//child, people who rely on his vote
};

void find_parent(voter* v){
    while(!v->c.empty()){
      v->c.front()->v = v->v;
      find_parent(v->c.front());
      v->c.pop_front();
    }
}

voter v[MAXVOTER];
int main(){
  int ans[500] = {0, 0, 0, 0};
  char in[200] = "";
  int inid, count = 0;//num who really vote(include invalid)
  char vo[100];
  int maxid = 0;
  
  while(gets(in)){
    count++;
    sscanf(in, "%d %s", &inid, vo);
    if(maxid < inid)
      maxid = inid;
    if(isalpha(vo[0])){
      v[inid].v = vo[0];
    } else {
      int voi = atoi(vo);
      if(maxid < voi)
	maxid = voi;
      v[voi].c.push_back(&v[inid]);
    }
  }
  for(int i = 1; i <= maxid; i++){
    if(v[i].v >= 0)
      find_parent(&v[i]);
  }
  for(int i = 1; i <= maxid; i++){
    if(v[i].v >= 0){
      ans[v[i].v]++;
    }
  }
  printf("Steve %d\nJenny %d\nEva %d\nInvalid %d\n", ans['S'], ans['J'], ans['E'], count-ans['S']-ans['J']-ans['E']);
  return 0;
}
