#include <stdio.h>

inline double abs(double in){
  return (in<0)?-in:in;
}

int main(){
  int h, m;
  double hd, md, dif;
  while(scanf("%d:%d", &h, &m) == 2 && h+m){
    hd = double(h)*30 + double(m)*0.5;
    md = double(m)*6;
    dif = abs(hd-md);
    if(dif > 180){
      dif = 360-dif;
    }
    printf("%.03lf\n", dif);
  }
  return 0;
}