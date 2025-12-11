#include <cstdio>

int N;

//if there are N people, minimum coconut number is N^N - N + 1
//there is at most 10 people in integer number of coconut

bool testCoconut(int n, int p){
  for(int i = 0; i < p; i++){
    n--;
    if(n % p != 0)
      return false;
    else{
      n /= p;
      n *= p-1;
    }
  }
  return (n % p == 0);
}

int getAns(){
  for(int i = 10; i >= 2; i--)
    if(testCoconut(N, i))
      return i;
  return -1;
}

int main(){
  while(scanf("%d", &N) == 1 && N >= 0){
    int ans = getAns();
    if(ans == -1)
      printf("%d coconuts, no solution\n", N);
    else
      printf("%d coconuts, %d people and 1 monkey\n", N, ans);
  }
}
