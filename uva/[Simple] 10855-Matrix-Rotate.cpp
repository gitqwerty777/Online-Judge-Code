#include <stdio.h>
#include <string.h>

char s[1000][1000];
char ss[1000][1000];
int n, N;

int matrix_fit(){
  int count = 0;
  for(int i = 0; i <= N-n; i++)
    for(int j = 0; j <= N-n; j++)
      if(s[i][j] == ss[0][0]){
	bool isfit = true;
	for(int ii = 0; ii < n; ii++)
	  for(int jj = 0; jj < n; jj++)
	    if(ss[ii][jj] != s[i+ii][j+jj]){
	      isfit = false;
	      break;
	    }
	if(isfit)
	  count++;      
      }
  return count;
}

char temp[1000][1000];
void rotate(){
  memcpy(temp, ss, sizeof(ss));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n ;j++){
      ss[i][j] = temp[n-1-j][i];
      //      printf("%c", ss[i][j]);
    }
    //    puts("");
  }
}

int main(){
  char in[50];
  while(scanf("%d %d", &N, &n) == 2 && N + n){
    memset(s, '\0', sizeof(s));
    memset(ss, '\0', sizeof(ss));
    gets(s[0]);
    for(int i = 0; i < N; i++)
      gets(s[i]);
    for(int i = 0; i < n; i++)
      gets(ss[i]);
    int ans[4];
    for(int i = 0; i < 4; i++){
      ans[i] = matrix_fit();
      printf("%d", ans[i]);
	if(i != 4)
	putchar(' ');
      rotate();
    }
    puts("");
  }
  return 0;
}