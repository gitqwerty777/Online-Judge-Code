#include <stdio.h>
#include <vector>
using namespace std;

int Input(){  
  char cha;  
  int x=0;  
  while(cha=getchar())  
    if((cha >= 48 && cha < 58) || cha == EOF) break;
  if(cha == EOF) return -1;
  x=cha-48;
  while(cha=getchar()) {  
    if(cha < 48 || cha >= 58) break;  
    x=x*10+cha-48;  
  }  
  return x;
}

int L, N;
vector<int> v;//size = N+2(0~N+1) //no need of vector... just array
int dp[55][55];//min value from i th cut to j th cut

int dp_cut(){
  for(int i = 0; i < N+2-1; i++){
    dp[i][i+1] = 0;// at least two boards, one board = 0
  }
  for(int i = 2; i < N+2; i++){//相差cut數
    for(int j = 0; j < N+2-i; j++){//start point
      int min = 2147483647;
      for(int k = j+1; k < j+i; k++){//cut point
	int temp = dp[j][k] + dp[k][j+i];
	if(min > temp)
	  min = temp;
      }
      dp[j][j+i] = v[j+i] - v[j] + min;
      //printf("dp[%d][%d] = %d - %d + %d(min) = %d\n", j, j+i, v[j+i], v[j], min, dp[j][j+i]);
    }
  }
  return dp[0][N+1];
}

int main(){
  int in;
  while( (L = Input()) != 0){
    N = Input();
    v.clear();
    v.push_back(0);//start point
    prein = 0;
    for(int i = 0;i < N; i++){
	    in = Input();
      v.push_back(in);
    }
    v.push_back(L);//end point
    printf("The minimum cutting is %d.\n", dp_cut());
  }
  return 0;
}