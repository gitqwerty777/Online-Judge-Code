#include <stdio.h>
#include <math.h>

//1 <= a,b,c <= 10000
//1 <= x^2+y2+z^2 <= 10000
//-100 <= x, y, z <= 100
double para[3];//x^3+[0]x^2+[1]x^1+[2];
bool check_root(int n){
  double ans = 0;
  int base = 1;
  for(int i = 2; i >= 0; i--){
    ans += para[i]*base;
    base *= n;
  }
  ans += base;
  return (ans == 0);
}

int main(){
  int T;
  int in[3];
  int ans[3];
  scanf("%d", &T);
  while(T-- && scanf("%d%d%d", &in[0], &in[1], &in[2]) == 3){
    para[0] = -in[0];
    para[1] = (in[0]*in[0]-in[2])/2;
    para[2] = -in[1];
    //        printf("[0]%lf [1]%lf [2]%lf\n", para[0], para[1], para[2]);
    /*if(para[0]*para[0]-4*para[1] > 0){
      printf("%lf ", para[0]*para[0]-4*para[1]);
      puts("para No solution.");
      continue;
      }*/
    int count = 0;
    for(int i = -100; i <= 100 && count < 3; i++)
      if(check_root(i))
	ans[count++] = i;
    if(count < 3){
      puts("No solution.");
      continue;
    }
    for(int i = 0; i < 3; i++){
      printf("%d", ans[i]);
      if(i != 2)
	putchar(' ');
    }
    puts("");
  }
  
  return 0;
}