#include <stdio.h>
#include <math.h>

//ref: http://blog.csdn.net/zcube/article/details/8545523
int main(){
  double n, p;
  while(scanf("%lf%lf", &n, &p) == 2){
    printf("%.lf\n", pow(p, 1/n));//too good!
  }
  return 0;
}