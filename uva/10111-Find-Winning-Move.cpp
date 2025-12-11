#include <cstdio>
#include <cstring>

char s[4][5];
int board[4][4];

int transform(char c){
  switch(c){
  case '.':
    return 0;
  case 'x':
    return 1;
  case 'o':
    return -1;
  }
}

enum COLOR{
  EMPTY = 0, BLACK = 1, WHITE = -1
};
int testBoard[4][4];

bool checkWin(COLOR c){
  bool isWinRow[4] = {true, true, true, true};
  bool isWinCol[4] = {true, true, true, true};
  bool isWinX[2] = {true, true};
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++){
      if(testBoard[i][j] != c){
	isWinRow[i] = false;
	isWinCol[j] = false;
	if(i == j)
	  isWinX[0] = false;
	if(i + j == 3)
	  isWinX[1] = false;
      }
    }
  bool isWin = isWinX[0] || isWinX[1];
  for(int i = 0; i < 4; i++){
    isWin = isWin || isWinRow[i];
    isWin = isWin || isWinCol[i];
  }
  return isWin;
}

bool checkBlackWinMove(){
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      if(testBoard[i][j] == EMPTY){
	testBoard[i][j] = BLACK;
	if(checkWin(BLACK)){
	  testBoard[i][j] = EMPTY;
	  return true;
	} else
	  testBoard[i][j] = EMPTY;
      }
  return false;
}

bool testMove(int r, int c){
  memcpy(testBoard, board, sizeof(board));
  if(testBoard[r][c] != EMPTY)
    return false;
  //printf("test (%d, %d)\n", r, c);
  testBoard[r][c] = BLACK;
  if(checkWin(BLACK))
    return true;
  bool isWin = false;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      if(testBoard[i][j] == EMPTY){
	testBoard[i][j] = WHITE;
	if(!checkWin(WHITE) && checkBlackWinMove()){
	  //printf("check white (%d, %d) win\n", i, j);
	  isWin = true;
	} else {
	  //printf("check white (%d, %d) lose\n", i, j);
	  testBoard[i][j] = EMPTY;
	  return false;
	}
	testBoard[i][j] = EMPTY;
      }
  testBoard[r][c] = EMPTY;
  return isWin;
}

int winMove[2];
bool getWinMove(){
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      if(testMove(i, j)){
	winMove[0] = i; winMove[1] = j;
	return true;
      }
  return false;
}

int main(){
  while(gets(s[0])){
    if(strcmp(s[0], "$") == 0)
      break;
    for(int i = 0; i < 4; i++)
      gets(s[i]);
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	board[i][j] = transform(s[i][j]);
    if(getWinMove())
      printf("(%d,%d)\n", winMove[0], winMove[1]);
    else
      puts("#####");
  }
}
