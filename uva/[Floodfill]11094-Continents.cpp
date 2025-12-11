#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int R, C, r, c;
char s[30][30];
vector< vector<bool> > isLand;
int count, maxcount;

//(x,N-1) should be assumed to  have a common edge with region (x,0)
int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void fillWater(int r, int c){
  if(r < 0 || r >= R)
    return;
  if(c < 0)
    c = C-1;
  else if(c >= C)
    c = 0;
  if(isLand[r][c]){
    count++;
    isLand[r][c] = false;
    for(int i = 0; i < 4; i++){
      fillWater(r+move[i][0], c+move[i][1]);
    }
  }
}

void floodFill(){
  maxcount = 0;
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(isLand[i][j]){
	count = 0;
	fillWater(i, j);
	if(isLand[r][c] && maxcount < count){//not the island people lived in
	  maxcount = count;
	}
	isLand[r][c] = true;
      }
    }
  }
}

int main(){
  isLand.resize(30);
  for(int i = 0; i < 30; i++){
    isLand[i].resize(30);
  }
  while(scanf("%d %d\n", &R, &C) == 2){
    for(int i = 0; i < R; i++){
      gets(s[i]);
      while(strcmp(s[i], "") == 0){
	gets(s[i]);
      }
    }
    scanf("%d %d", &r, &c);
    char landchar = s[r][c];
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
	isLand[i][j] = (s[i][j] == landchar)?true:false;
      }
    }
    
    floodFill();
    
    printf("%d\n", maxcount);
  }
  return 0;
}
