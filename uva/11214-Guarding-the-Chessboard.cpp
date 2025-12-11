#include <stdio.h>
#include <vector>
using namespace std;

int R, C;
char s[1000];
vector< vector<bool> > board;

void findMinQueen(){
  
}

int main(){
  while(scanf("%d%d\n", &R, &C) == 2 && R+C){
    board.resize(R);
    for(int i = 0; i < R; i++){
      board[i].resize(C);
      std::fill(board[i].begin(), board[i].end(), false);
    }
    for(int i = 0; i < R; i++){
      gets(s);
      for(int j = 0; j < C; j++){
	if(s[j] == 'X')
	  board[i][j] = true;
      }
    }
    findMinQueen();
  }
}
