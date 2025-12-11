#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

//really a hard question!

int H, W;
char s[200][55];
char bi[200][210];
int frame[204][220];

char hex[] = "0123456789abcdef";
char bistr[][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

void decode(char s[], char bi[]){
  int size = strlen(s);
  char* h;
  int index;
  memset(bi, '\0', sizeof(bi));
  for(int i = 0; i < size; i++){
    h = strchr(hex, s[i]);
    index = (int)(h - hex);
    strcat(bi, bistr[index]);
  }

}

void makeFrame(){
  W = W*4;
  for(int i = 0; i < H; i++){// real value in 1~H
    for(int j = 0; j < W; j++){
      frame[i+1][j+1] = bi[i][j]-'0';
    }
  }
  for(int i = 0; i <= H+1; i++){
    frame[i][0] = 0;
    frame[i][W+1] = 0;
  }
  for(int i = 0; i <= W+1; i++){
    frame[0][i] = 0;
    frame[H+1][i] = 0;
  }

}

char ancientWords[] = "WAKJSD";
char words[10000];
int fillValue;

void fillBlack(int r, int c){
  if(r >= 0 && r <= H+1 && c >= 0 && c <= W+1){
    if(frame[r][c] == 1){//black
      frame[r][c] = fillValue;
      fillBlack(r, c+1);
      fillBlack(r, c-1);
      fillBlack(r+1, c);
      fillBlack(r-1, c);
    }
  }
}

int blackNeighbor;
bool isBlank;
void fillWhite(int r, int c){
  if(r >= 0 && r <= H+1 && c >= 0 && c <= W+1){
    if(frame[r][c] == -1)
	return;
    if(frame[r][c] != 0){//not white
      if(blackNeighbor == 0){//initial black Neighbor
	blackNeighbor = frame[r][c];
      } else {
	if(blackNeighbor != frame[r][c])
	  isBlank = false;
      }
    } else {
      if(r == 0 || c ==0 || c == W+1 || r == H+1){//touch the frame, not inside the word
	isBlank = false;
      }
      frame[r][c] = -1;
      fillWhite(r, c+1);
      fillWhite(r, c-1);
      fillWhite(r+1, c);
      fillWhite(r-1, c);
    }
  }
}


int wordCount;
void fillBlank(){
  wordCount = 0;
  fillValue = 2;//black=1, white = 0,start from 2
  memset(words, '\0', sizeof(words));
  int blankCount[10000] = {0};
  for(int i = 1; i <= H; i++)
    for(int j = 1; j <= W; j++)
      if(frame[i][j] == 1) {
	fillBlack(i, j);
	fillValue++;
	wordCount++;
      }

  //printf("%d words\n", wordCount);
  for(int i = 1; i <= H; i++){
    for(int j = 1; j <= W; j++){
      if(frame[i][j] == 0){
	isBlank = true;
	blackNeighbor = 0;
	fillWhite(i, j);
	if(isBlank){
	  blankCount[blackNeighbor-2]++;
	}
      }
    }
  }
  for(int i = 0; i<fillValue-2; i++){
    words[i] = ancientWords[blankCount[i]];
  }
}

int charcmp(const void* a, const void* b){
  return *(char*)a - *(char*)b;
}

int main(){
  int T = 1;
  while(scanf("%d %d\n", &H, &W) == 2 && H+W){
    for(int i = 0; i < H; i++){
      gets(s[i]);
      decode(s[i], bi[i]);
    }
    makeFrame();
    fillBlank();
    qsort(words, wordCount, sizeof(char), charcmp);
    printf("Case %d: %s\n", T++, words);
  }
}
