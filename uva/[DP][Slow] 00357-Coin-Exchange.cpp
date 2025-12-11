#include <stdio.h>
#include <string.h>
#define MAXN 30004

long long ans[MAXN];
/*
p.s 美國的零錢共有以下幾種硬幣以及其面值：
penny, 1 cent
nickel, 5 cents
dime, 10 cents
quarter, 25 cents
half-dollar, 50 cents
*/
int c[4] = {5, 10, 25, 50};

void find_ans(){
  for(int i = 0; i < MAXN; i++)//for 1 cent
    ans[i] = 1;
  for(int j = 0; j < 4; j++)
    for(int i = MAXN; i >= 0; i--)//from big to small to get correct answer
      for(int k = 1; i >= k*c[j]; k++)//???
	ans[i] += ans[i-k*c[j]];
}

int main(){
  int in;
  find_ans();
  while(scanf("%d", &in) == 1){
    if(ans[in] == 1)
      printf("There is only 1 way to produce %d cents change.\n", in);
    else
      printf("There are %lld ways to produce %d cents change.\n", ans[in], in);
  }
  return 0;
}