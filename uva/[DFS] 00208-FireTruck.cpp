#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

bool r[21][21];//isopen
vector<int> in;//inside the road circle of fire
int inn;//in size
int N;
char s[24] = "";

void find_possible_vertex(){
  bool isin[21];//inside
  memset(isin, false, sizeof(isin));
  queue<int> q;
  q.push(N);
  while(!q.empty()){
    int temp = q.front();
    for(int i = 1; i < 21; i++){
      if(!isin[i] && r[i][temp]){
	isin[i] = true;
	q.push(i);
      }
    }
    q.pop();
  }
  in.clear();
  for(int i = 2; i < 21; i++){//no 0 and 1
    if(isin[i])
      in.push_back(i);
  }
  inn = in.size();
}

int routecount = 0;
bool passed[21];//
void find_route(int index, int n){
  if(n == N){
    int len = strlen(s);
    for(int i = 0;i < len; i++){
        printf("%d", s[i]);//char (<128)
	if(i != len-1)
	  putchar(' ');
    }
    puts("");
    routecount++;
  } else {
    for(int i = 0; i < inn; i++){//順找
      if(!passed[in[i]] && r[in[i]][n]){
	s[index] = in[i];//沒有零，沒差？
	passed[in[i]] = true;
	find_route(index+1, in[i]);
	passed[in[i]] = false;//needed
	s[index] = '\0';//needed, if there is last time
      }
    }
  }
}

int main(){
  int count = 1;
  int a, b;
  passed[1] = true;    //first step is 1
  s[0] = 1;
  
  while(scanf("%d", &N) == 1){
    memset(r, false, sizeof(r));
    memset(passed+1, false, sizeof(passed)-sizeof(bool));
    routecount = 0;
    while(scanf("%d %d", &a, &b) == 2 && a+b){
      r[a][b] = true; r[b][a] = true;
    }
    find_possible_vertex();
    printf("CASE %d:\n", count++);
    find_route(1, 1);
    printf("There are %d routes from the firestation to streetcorner %d.\n", routecount, N);
  }
  return 0;
}