#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, T = 1;
int a[105], b[105];
int lcs[105][105];

void findLCS(){
  for(int i = 0; i <= A; i++)
    for(int j = 0; j <= B; j++)
      lcs[i][j] = 0;
  for(int i = 1; i <= A; i++)//start from 1, so can use i-1, j-1
    for(int j = 1; j <= B; j++)
      if(a[i-1] == b[j-1])
	lcs[i][j] = max(lcs[i][j], lcs[i-1][j-1]+1);
      else
	lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
}

int main(){
  while(scanf("%d%d", &A, &B) == 2 && A+B){
    for(int i = 0; i < A; i++)
      scanf("%d", &a[i]);
    for(int i = 0; i < B; i++)
      scanf("%d", &b[i]);
    findLCS();
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", T++, lcs[A][B]);
  }
}
