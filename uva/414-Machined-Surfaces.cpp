#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N;
int count[100];
char s[100];

void getCount(int i){
  char* p = strtok(s, " ");
  count[i] = 0;
  while(p != NULL){
    count[i] += strlen(p);
    p = strtok(NULL, " ");
  }
}

int main(){
  while(scanf("%d\n", &N) == 1 && N){
    int maxcount = 0;
    for(int i = 0; i < N; i++){
      gets(s);
      getCount(i);
      maxcount = max(maxcount, count[i]);
    }
    int diff = 0;
    for(int i = 0; i < N; i++){
      diff += maxcount - count[i];
    }
    printf("%d\n", diff);
  }
}
