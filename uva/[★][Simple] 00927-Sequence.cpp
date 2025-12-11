#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gene[21];//generate function
int maxn = 0;//max power

long long get_num(int n){
  long long num = 0;
  long long base = 1;
  for(int i = 0; i <= maxn; i++, base *= n){
    num += base * gene[i];
  }
  return num;
}

int main(){
  int T, D, K;
  scanf("%d", &T);
  while(T--){
    //input:
    //degree i followed by i+1 coefficients(n^0 ~ n^i)
    //D
    //K
    scanf("%d", &maxn);
    for(int i = 0; i <= maxn; i++)
      scanf("%d", &gene[i]);
    scanf("%d", &D);
    //calculate all possibilities -> don't calculate, only find n = ?
    scanf("%d", &K);
    int count = 1;
    int nowi = D;
    int nowinterval = 2*D;
    while(nowi < K){
      count++;
      nowi += nowinterval;
      nowinterval += D;
    }
    printf("%lld\n", get_num(count));
  }
  return 0;
}