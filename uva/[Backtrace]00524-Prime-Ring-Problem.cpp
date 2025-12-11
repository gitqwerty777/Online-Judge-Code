#include <cstdio>
#include <cstring>

int N;
int ans[20];
bool used[20];
bool isPrime[50];

void findAns(int d, bool used[]){
  if(d == N){
    if(!isPrime[ans[N-1] + ans[0]])
      return;
    for(int i = 0; i < N-1; i++)
      printf("%d ", ans[i]);
    printf("%d\n", ans[N-1]);
    return;
  } else {
    int prev = ans[d-1];
    for(int i = 1; i <= N; i++){
      if(!used[i] && isPrime[i+prev]){
	used[i] = true; ans[d] = i;
	findAns(d+1, used);
	used[i] = false;
      }
    }
  }
}

void printPossibleAns(){
  memset(used, false, sizeof(used));
  ans[0] = 1;
  used[1] = true;
  findAns(1, used);
}

void makePrime(){
  for(int i = 0; i < 50; i++){
    bool isprime = true;
    for(int j = 2; j < i; j++)
      if(i%j == 0)
	isprime = false;
    isPrime[i] = isprime;
  }
}

int main(){
  int T = 0;
  makePrime();
  bool first = true;
  while(scanf("%d", &N) == 1){
    if(!first )
      puts("");
    else
      first = false;
    T++;
    printf("Case %d:\n", T);
    printPossibleAns();

  }
}
