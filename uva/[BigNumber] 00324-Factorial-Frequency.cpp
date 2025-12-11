#include <stdio.h>
#include "BigNumber/test.h"

int ans[370][10];

void count_num(int n, string s){
  int len = s.size();
  for(int i = 0; i < len; i++){
    ans[n][s[i]-'0']++;
  }
}

int main(){
  int in;
  BigNumber a = 1;
  count_num(0, a.get_string());
  for(int i = 1; i <= 366; i++){
    a = a*i;
    count_num(i, a.get_string());
  }
  while(scanf("%d", &in) == 1 && in){
    printf("%d! --\n", in);
    for(int i = 0; i < 10; i++){
      if(i % 5 == 0)
	printf("   ");
      if(i % 5 == 4){
	printf("(%d)%5d\n", i, ans[in][i]);
      } else {
	printf("(%d)%5d    ", i, ans[in][i]);
      }
    }
    /*
      output format:
      3! --
      (0)    0    (1)    0    (2)    0    (3)    0    (4)    0
      (5)    0    (6)    1    (7)    0    (8)    0    (9)    0
      1231
      (0)   30    (1)   15    (2)   19    (3)   10    (4)   10
      (5)   14    (6)   19    (7)    7    (8)   14    (9)   20
     */
  }
  return 0;
}