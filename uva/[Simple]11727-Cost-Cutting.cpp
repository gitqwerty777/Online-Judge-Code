#include <stdio.h>

inline void swap(int&a, int&b){
  int c = a;
  a = b;
  b = c;
}

int main(){
  int T, count = 0;
  scanf("%d", &T);
  int a[3];
  while(T--){
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    for(int i = 0; i < 3; i++)
      for(int j = i+1; j < 3; j++)
	if(a[i] > a[j])
	  swap(a[i], a[j]);
    printf("Case %d: %d\n", ++count, a[1]);
  }
  return 0;
}
