#include <stdio.h>
#include <string.h>

char s[512];
char name[8] = "BUSPFTM";
int num[8];

bool findway;
bool way;
int prevj;

bool add_num(int n){
  num[n]++;
  if(num[n] >= 10){
    //    printf("-> number flow ");
    return false;
  }
  if(!findway){
    if(prevj != -1 && prevj != n){
      way = prevj < n;
      findway = true;
    }
  } else if(prevj != n && way != (prevj < n)){
    return false;
  }
  prevj = n;
  //  printf("findway = %s, way = %s, prevj = %d n = %d\n", (findway)?"true":"false", (way)?"true":"false", prevj, n);
  return true;
}

int main(){
  int N;
  scanf("%d\n", &N);
  while(N--){
    memset(num, 0, sizeof(num));
    gets(s);
    //printf("input = %s\n", s);
    int len = strlen(s);
    bool err = false;
    findway = false; prevj = -1;
    for(int i = 0; i < len && !err; i++)
      for(int j = 0; j < 7; j++)
	if(s[i] == name[j]){
	  if(!add_num(j))
	    err = true;
	  break;
	}
    //print ans
    if(err){
      puts("error");
    } else {
      int ans = 0, base = 1;
      for(int i = 0; i < 7; i++){
	ans += base * num[i];
	base *= 10;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}