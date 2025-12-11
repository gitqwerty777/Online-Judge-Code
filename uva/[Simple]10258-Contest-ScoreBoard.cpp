#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
char s[1000];

struct score{
  int playerNum;
  int problemNum;
  int ct;//correct time
  int wt[10];//wrong time
  bool solved[10];
  score(){}
  score(int i){
    playerNum = i;
    problemNum = 0;    ct = 0; 
    for(int i = 0; i < 10; i++){
      wt[i] = 0; solved[i] = false;
    }
  }
  void addSolve(int &p, int &t){
    solved[p] = true;
    problemNum++;
    ct += wt[p]*20 + t;
  }
  void addWrong(int &p){
    wt[p]++;
  }
  bool operator<(const score cmp) const{
    if(problemNum != cmp.problemNum)
      return problemNum > cmp.problemNum;
    else if(ct != cmp.ct)
      return ct < cmp.ct;
    else
      return playerNum < cmp.playerNum;
  }
};

/*
包括參賽者編號、解出的題數及處罰時間。由於並非1～100號所有的參賽者均有真正出席參賽，所以只需列出有上傳答案的參賽者。
測試資料間亦請空一列
*/

struct Scoreboard{
  score s[100];
  bool isAttend[100];

  Scoreboard(){
    init();
  }
  
  inline void init(){
    for(int i = 0; i < 100; i++){
      s[i] = score(i);
      isAttend[i] = false;
    }
  }
  
  void addQuest(int &i, int&p, int &t, char& st){
    isAttend[i] = true;
    if(st == 'R' || st == 'U' || st == 'E' || s[i].solved[p]){
      return;
    }
    if(st == 'C'){
      s[i].addSolve(p, t);
    } else if (st == 'I'){
      s[i].addWrong(p);
    }
  }

  void sort(){
    std::sort(s, s+100);
  }

  void print(){
    for(int i = 0;i < 100; i++){
      if(isAttend[s[i].playerNum]){
	printf("%d %d %d\n", s[i].playerNum+1, s[i].problemNum, s[i].ct);
      }
    }
  }
};

int main(){
  Scoreboard sb;
  scanf("%d\n", &T);
  bool first = true;
  
  while(gets(s)){
    if(strcmp(s, "") == 0){
      sb.sort();
      sb.print();
      sb.init();
      puts("");
    } else {
      int i, p, t;
      char st;
      sscanf(s, "%d%d%d %c", &i, &p, &t, &st);
      i--; p--;
      sb.addQuest(i, p, t, st);
    }
  }
  sb.sort();
  sb.print();
  sb.init();
}
