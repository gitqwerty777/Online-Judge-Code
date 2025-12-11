#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#define ELE_NUM 1005
using namespace std;
//http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html

struct ele{
  ele(int i, int wei, int sta){
    index = i; w = wei; s = sta;
  }
  int index;
  int w, s;
};

bool weightSort(ele e1, ele e2){
  return e1.w < e2.w;
}
bool iqSort(ele e1, ele e2){
  return e1.s > e2.s;
}

int main(){
  int W, S;
  vector<ele> e;
  vector<ele> we, se;
  int count = 0;
  
  while(scanf("%d %d", &W, &S) == 2){
    e.push_back(ele(count++, W, S));
  }

  we = e; se = e;
  sort(we.begin(), we.end(), weightSort);
  sort(se.begin(), se.end(), iqSort);

  int windex[ELE_NUM];
  int sindex[ELE_NUM];

  for(int i = 0; i < count; i++){
    windex[i] = we[i].index;
    sindex[i] = se[i].index;
    //printf("wei[%d] = %d, sei[%d] = %d\n", i, we[i].index, i, se[i].index);
  }

  int LCS_table[ELE_NUM][ELE_NUM];
  int prev_table[ELE_NUM][ELE_NUM];
  //find LCS of windex and sindex
  #define ANS 0
  #define LEFT 1
  #define UP 2
  for(int i = 0; i <= count; i++){
    LCS_table[i][0] = 0;
    LCS_table[0][i] = 0;
  }
  for(int i = 1; i <= count; i++){
    for(int j = 1; j <= count; j++){
      if(sindex[i-1] == windex[j-1]){
	LCS_table[i][j] = LCS_table[i-1][j-1] + 1;
	prev_table[i][j] = ANS;
      } else {
	if(LCS_table[i][j-1] > LCS_table[i-1][j]){
	  LCS_table[i][j] = LCS_table[i][j-1];
	  prev_table[i][j] = LEFT;
	} else {
	  LCS_table[i][j] = LCS_table[i-1][j];
	  prev_table[i][j] = UP;
	}
      }
    }
  }

  stack<int> ansindex;

  int nowi = count, nowj = count;
  int anscount = 0;
  while(nowi > 0 && nowj > 0){
    //    printf("now pre[%d][%d] = %d\n", nowi, nowj, prev_table[nowi][nowj]);
    switch(prev_table[nowi][nowj]){
    case ANS:
      if(ansindex.empty() || e[sindex[nowi-1]].w != e[ansindex.top()].w && e[sindex[nowi-1]].s != e[ansindex.top()].s){
	ansindex.push(sindex[nowi-1]);//-1, not good to read
	anscount++;
      }
      nowi--;
      nowj--;
      break;
    case UP:
      nowi--;
      break;
    case LEFT:
      nowj--;
      break;
    }
  }

  printf("%d\n", anscount);
  while(!ansindex.empty()){
    int i = ansindex.top();
    //    printf("[%d] = %d %d\n", i+1, e[i].w, e[i].s);
    printf("%d\n", i+1);
    ansindex.pop();
  }
    return 0;
}