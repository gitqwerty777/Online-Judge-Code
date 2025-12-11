#include <stdio.h>

int T;
int M, N;
char ans[][10] = {"NO", "NE", "SO", "SE", "divisa"};
int main(){
  int x, y;
  while(scanf("%d", &T) == 1 && T){
    scanf("%d%d", &M, &N);
    while(T--){
      scanf("%d%d", &x, &y);
      int xx = x-M;
      int yy = y-N;
      int ansi;
      if(xx == 0 || yy == 0)
	ansi = 4;
      else if (xx > 0 && yy > 0)
	ansi = 1;
      else if (xx < 0 && yy > 0)
	ansi = 0;
      else if (xx < 0 && yy < 0)
	ansi = 2;
      else if (xx > 0 && yy < 0)
	ansi = 3;
      printf("%s\n", ans[ansi]);
    }
  }
  return 0;
}
