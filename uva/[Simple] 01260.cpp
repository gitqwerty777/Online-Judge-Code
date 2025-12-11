#include <stdio.h>
#include <string.h>

int a[5004];
int b[5004];

int main(){
  int T, A;
  scanf("%d", &T);
  while(T--){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &A);
    for(int i = 0; i < A; i++){
      scanf("%d", &a[i]);
      for(int j = 0; j < i; j++){
	if(a[j] <= a[i])
	  b[i]++;
      }
    }
    long sum = 0;
    for(int i = 0; i < A; i++){
      sum += b[i];
    }
    printf("%ld\n", sum);
  }
}