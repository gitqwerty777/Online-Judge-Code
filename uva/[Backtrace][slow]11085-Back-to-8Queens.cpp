#include <cstdio>
#include <cstring>
#include <unistd.h>

int queen[8];

int ans[8];
int minmove;
int minans[8];
int board[8][8];

inline void fillboard(int r, int c){
  for(int i = 0; i < 8; i++){
    board[i][c] = 1;
    board[r][i] = 1;
    if(i+r < 8 && i+c < 8)
      board[r+i][c+i] = 1;
    if(r-i >= 0 && c-i >= 0)
      board[r-i][c-i] = 1;
    if(r+i < 8 && c-i >= 0)
      board[r+i][c-i] = 1;
    if(r-i >= 0 && c+i < 8)
      board[r-i][c+i] = 1;
  }
}

bool isComflict(int d, int v){
  memset(board, 0, sizeof(board));
  for(int i = 0; i < d; i++)
    if(ans[i] == v)
      return true;
  for(int i = 0; i < d; i++)
    fillboard(i, ans[i]);
  //for(int i = 0; i < d; i++)
  //printf("%d = %d ", i, ans[i]);
  //printf("\ncannot fill (%d, %d)\n", d, v);
  return board[d][v] != 0;
}

void findAns(int d, int move){
  if(d == 8){
    if(move < minmove)
      minmove = move;
  } else {
    //move to other
    for(int i = 0; i < 8; i++){
      if(!isComflict(d, i)){
	ans[d] = i;
	if(i != queen[d])
	  findAns(d+1, move+1);
	else
	  findAns(d+1, move);
      }
    }
  }
}

void findMinAns(){
  minmove = 10000;
  for(int i = 0; i < 8; i++)
    queen[i]--;
  findAns(0, 0);
}

int main(){
  int T = 1;
  while(scanf("%d%d%d%d%d%d%d%d", &queen[0], &queen[1],&queen[2],&queen[3],&queen[4],&queen[5],&queen[6],&queen[7]) == 8){
    findMinAns();
    printf("Case %d: %d\n", T++, minmove);
  }
}

