#include <stdio.h>
#include <string.h>

//input value < 100
int arr[100];

int main(){
  int N, in;
  while(scanf("%d", &N) == 1 && N){
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < N; i++){
      scanf("%d", &in);
      arr[in]++;
    }
    //print first
    for(int i = 0; i < 100; i++){
      if(arr[i]){
        arr[i]--;
	printf("%d", i);
	break;
      }
    }
    for(int i = 0; i < 100;i++){
      while(arr[i]--){
	printf(" %d", i);
      }
    }
    puts("");
  }
  return 0;
}