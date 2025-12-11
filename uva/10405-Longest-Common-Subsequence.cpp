#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int myans;
int ans[1004][1004];
char a[2000], b[2000];
void DoLCS(){
  int lena = strlen(a), lenb = strlen(b);
  for(int i = 0; i <= lena; i++)
    for(int j = 0; j <= lenb; j++)
      ans[i][j] = 1;
  for(int i = 0; i <= lena; i++)
    ans[i][0] = 0;
  for(int i = 0; i <= lenb; i++)
    ans[0][i] = 0;
  for(int i = 1; i <= lena; i++)
    for(int j = 1; j <= lenb; j++)
      if(a[i-1] == b[j-1])
	ans[i][j] = ans[i-1][j-1]+1;
      else
	ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
  myans = ans[lena][lenb];
}

int main(){
  while(gets(a)){
    gets(b);
    DoLCS();
    printf("%d\n", myans);
  }
}
