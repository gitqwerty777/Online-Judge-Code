#include <stdio.h>
#include <math.h>
#define SCOPE 100000
/*
  p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0
  where 0 <= x <= 1.
  Input consists of multiple test cases and terminated by an EOF. Each test case consists of 6 integers in a single line: p, q, r, s, t and u (where 0 <= p,r <= 20 and -20 <= q,s,t <= 0). There will be maximum 2100 lines in the input file.
  Output 0.0000 ~ 1.0000 -> decreasing function
  !!!: all zero -> must output zero
*/

double pre[SCOPE+1][6];
int in[6];

void pre_op(){
  for(int i = 0; i <= SCOPE; i++){
    double x = double(i)/SCOPE;
    pre[i][0] = pow(M_E, -x);
    pre[i][1] = sin(x);
    pre[i][2] = cos(x);
    pre[i][3] = tan(x);
    pre[i][4] = pow(x, 2);
    pre[i][5] = 1;
  }
}

double check(int m){
  double sum = 0;
  for(int i = 0; i < 6; i++){
    sum += double(in[i]) * pre[m][i];
  }
  //printf("check %d, sum = %lf\n", m, sum);
  return sum;
}

int main(){
  pre_op();
  int start, end, mid;
  while(scanf("%d%d%d%d%d%d", &in[0], &in[1], &in[2], &in[3], &in[4], &in[5]) == 6){
    if(in[0] == 0 && in[1] == 0 && in[2] == 0 && in[3] == 0 && in[4] == 0 && in[5] == 0){
      puts("0.0000"); continue;}
    if(check(SCOPE) > 0 || check(0) < 0){
      puts("No solution"); continue;}
    start = 0;
    end = SCOPE;
    while(end - start > 1){
      mid = (start + end)/2;
      double bs = check(mid);
      if(int(bs*SCOPE) > 0){
	     start = mid;
      } else if(int(bs*SCOPE) < 0){
	     end = mid;
      } else {
	     break;
      }
    }
    mid = (start+end)/2;
    while(mid+1 <= SCOPE && check(mid+1) > 0)
      mid++;
    while(mid-1 >= 0 && check(mid-1) < 0)
      mid--;
    while(check(mid) < 0)//f(x=mid) > 0
      mid--;
    if(mid - mid/10*10 >= 5)//四捨五入
      mid += 10;
    printf("%d.%04d\n", mid/SCOPE, (mid%SCOPE)/10);
  }
  return 0;
}