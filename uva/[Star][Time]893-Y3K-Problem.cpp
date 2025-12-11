#include <stdio.h>

int D, d, m, y;

inline bool isLeapYear(){
  return ((y%4) == 0)
    && (((y%100)!=0) || ((y%400) == 0));
}

inline int getDay(){
  if(isLeapYear())
    return 366;
  else
    return 365;
}

int monthday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int getMonthDay(int mm){
  if(mm == 2 && isLeapYear() )
    return 29;
  else
    return monthday[mm];
}

void addDay(){//assure it will not across the year
  if(d != 1){
    D += d-1;
    d = 1;    
  }
  while(D >= getMonthDay(m)){
    D -= getMonthDay(m);
    m++;
  }
  d += D;
}

int calculateRemainDate(){
  int day = 0;
  int mm = m;
  day += getMonthDay(mm)-d; mm++;

  while(mm <= 12){
    day += getMonthDay(mm);
    mm++;
  }
  return day+1;
}

void calculateDate(){
  int r = calculateRemainDate();
  if(r > D){
    addDay();
    return;
  }
  D -= r; d = 1; m = 1; y++; 
  while(D >= getDay()){
    D -= getDay();
    y++;
  }
  addDay();
}

int main(){
  while(scanf("%d%d%d%d", &D, &d,&m, &y) == 4 && D+d+m+y){
    calculateDate();
    printf("%d %d %d\n", d, m, y);
  }
}
