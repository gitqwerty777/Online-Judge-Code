#include <stdio.h>
#include <string.h>
#include "matrix.h"

/*
hint: 
   A+A^2+...+A^(2n) = (A+A^2+...+A^n) + A^n (A+A^2+...+A^n)
*/

int main(){
  int N, P;
  while(scanf("%d %d", &N, &P) == 2 && N + P){
    matrix arr(N, N);
    matrix sum(N, N);
    for(int r = 0; r < N; r++)
      for(int c = 0; c < N; c++){
	scanf("%d", &arr.s[r][c]);
	sum.s[r][c] = arr.s[r][c];
      }


    bool sq[20]; // log_2 (1000000) = 19.93...
    memset(sq, false, sizeof(sq));
    int sqnum = P;
    int count = 0;
    while(sqnum){
      if(sqnum % 2)
	sq[count] = true;
      count++;
      sqnum /= 2;
    }
    for(int i = count-1; i >= 0; i--)
      printf("%d", sq[i]?1:0);
    puts("");
    if(count == 1){
      
    } else {
      matrix ori(arr);
      //square and multiply
      for(int i = count-2; i >= 0; i--){//start from 10
	sum = sum + sum * arr;
	if(sq[i]){
	  sum = sum * ori + ori;
	}
	arr = arr ^ 2;
	sum.mod(10);
	arr.mod(10);
      }
    }
    sum.print();
    puts("");
  }
  return 0;
}
