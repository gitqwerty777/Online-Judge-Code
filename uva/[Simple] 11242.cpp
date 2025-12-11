#include <stdio.h>
#include <algorithm>

int f[20], r[20];
double d[256];
double sp[256];

int main(){
  int F, R;
  while(scanf("%d %d", &F, &R) == 2 && F){
    for(int i = 0; i < F; i++)
      scanf("%d", &f[i]);
    for(int i = 0; i < R; i++){
      scanf("%d", &r[i]);
      for(int j = 0; j < F; j++)
	d[i*F+j] = double(r[i]) / f[j];
    }
    std::sort(d, d+F*R);
    //puts("sp:");
    for(int i = 0; i < F*R-1; i++){
      sp[i] = d[i+1] / d[i];
      //printf("%lf ", sp[i]);
    }
    std::sort(sp, sp+F*R-1);
    printf("%.2lf\n", sp[F*R-2]);
  }
  return 0;
}