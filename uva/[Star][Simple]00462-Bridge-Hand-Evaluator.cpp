#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
/*
1. Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack counts one point.
2. Subtract a point for any king of a suit in which the hand holds no other cards.
3. Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
4. Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
5. Add a point contains exactly two cards.
6. Add two points contains exactly one card.
7. Add two points contains no cards.
 */

struct card{
  card(int value, int color){
    v = value; c = color;
  }
  int v;//A is 14
  int c;//shdc
};

int maxindex(int arr[]){
  int maxi = 0, maxv = arr[0];
  for(int i = 1;i < 4; i++)
    if(maxv < arr[i]){
      maxi = i; maxv = arr[i];
    }
  return maxi;
}

char colorchar[5] = "SHDC";
char valuechar[15] = "023456789TJQKA";//1->13
class hand{
public:
  int count[4];
  int bigCount[4][4];//jqka
  int bigCounts[4];//jqka, total
  bool isStopped;
  int score[2];//1~4, 5~7
  int bestBid;
  hand(){
    score[0] = score[1] = 0;
    for(int i = 0; i < 4; i++){
      count[i] = 0;
      bigCounts[i] = 0;
    }
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	bigCount[i][j] = 0;
    isStopped = false;
  }
  card parse(string& s){
    char* p = strstr(valuechar, s.substr(0, 1).c_str());
    int v = p-valuechar;
    p = strstr(colorchar, s.substr(1, 2).c_str());
    int c = p-colorchar;
    //printf("parse %d, %d\n", v+1, c);
    return card(v+1, c);
  }
  void addCard(string& s){
    card c = parse(s);
    if(c.v > 10){
      score[0] += c.v-10;//1
      bigCount[c.c][c.v-11]++;
      bigCounts[c.v-11]++;
    }
    count[c.c]++;
  }
  int getBestBid(){
    //printf("nowscore = %d\n", score[0]);
    //printf("nowcount = %d, %d, %d, %d\n", count[0], count[1], count[2], count[3]);
    for(int i = 0; i < 4; i++){
      if(count[i] <= 2){//5~7
	score[1]++;
	if(count[i] < 2)
	  score[1]++;
      }
      for(int v = 0; v < 3; v++)//2~4
        if(bigCount[i][v] && count[i] <= 3-v)//j and <=3, q and <=2, k and <=1
	  score[0] -= bigCount[i][v];
    }
    //printf("nowscore = %d+%d\n", score[0], score[1]);
    for(int i = 0; i < 4; i++){
      isStopped = false;
      for(int j = 1; j < 4; j++)
	if(bigCount[i][j] && count[i] >= 4-j)//3q 2k 1a
	  isStopped = true;
      if(!isStopped){
	//printf("%d stop\n", i);
	break;
      }
    }
    if(isStopped && score[0] >= 16)
      bestBid = 4;
    else if(score[0] + score[1] >= 14){
      bestBid = maxindex(count);//0123
    } else {
      bestBid = -1;
    }
    return bestBid;
  }
};

char s[50];
char bidchar[][10] = {"S", "H", "D", "C", "NO-TRUMP"};
int main(){
  while(gets(s)){
    string ss(s);
    hand b;
    bool isEnd = false;
    int prei = 0, nowi;
    string nows;
    while(!isEnd){
      nowi = ss.find(' ',prei);
      if(nowi == ss.npos)
	isEnd = true;
      nows = ss.substr(prei, 2);
      b.addCard(nows);
      prei = nowi+1;
    }
    int bid = b.getBestBid();
    if(bid >= 0)
      printf("BID %s\n", bidchar[bid]);
    else
      puts("PASS");
  }
}
