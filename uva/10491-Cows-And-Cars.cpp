#include <cstdio>

//7/8 * 3/5
//

double cow, car, open;
int main(){
  while(scanf("%lf%lf%lf", &cow, &car, &open) == 3){
    printf("%.05lf\n", (cow+car-1)/(cow+car) * (car)/(cow+car-1-open));
 }
}
