#include <stdio.h>
/*
I can't understand the problem
ref: http://maplewing.blogspot.tw/2011/03/uva10550combination-lock.html
此題感覺很簡單，
但是請你一定要想一想，
如果你順時針轉數字鎖的時候，
數字卻是會逆時針轉動的！= =
*/

int main(){
  int s, a, b, c;
  while(scanf("%d %d %d %d", &s, &a, &b, &c) == 4 && s+a+b+c){
    int ans = 0;
    ans = (400+s-a)%40 + (400+b-a)%40 + (400+b-c)%40;
    //    printf("ans = %d\n", ans);
    printf("%d\n", 1080+ans*9);
  }
  return 0;
}