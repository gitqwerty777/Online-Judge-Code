#include <stdio.h>
#include <math.h>

struct threedPoint{
  threedPoint(){
    mind = 442;//(0, 0, 0) to (255, 255, 255)
  }
  threedPoint(double xx, double yy, double zz){
    x = xx; y = yy; z = zz; mind = 442;
  }
  double x, y, z;
  double mind;//distance
};

double distance(threedPoint a, threedPoint b){
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int main(){
  int up[11] = {0};//up to 10, [0] is not used
  struct threedPoint p[5005];
  int count = 0;
  while(scanf("%lf %lf %lf", &p[count].x, &p[count].y, &p[count].z) == 3 && p[count].x + p[count].y + p[count].z){
    for(int i = 0; i < count; i++){
      double d = distance(p[i], p[count]);
      if(d < p[i].mind)
	p[i].mind = d;
      if(d < p[count].mind)
	p[count].mind = d;
    }
    count++;
  }
  for(int i = 0; i < count; i++){
    if(int(p[i].mind) <= 9){
      up[int(p[i].mind)]++;
    }
  }
  for(int i = 0; i < 10; i++){
    printf("%4d", up[i]);
  }
  puts("");//always forget...
  return 0;
}