#include <stdio.h>
#include <string.h>
int arr[1000000];
char data[10004][24];

int main(){
  int T;
  int N, Q;
  int u, d;
  scanf("%d", &T);
  while(T-- && scanf("%d", &N) == 1){
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= N; i++){
      scanf("%s %d %d", data[i], &d, &u);
      for(int j = d; j <= u; j++){
	if(arr[j])
	  arr[j] = -1;
	else
	  arr[j] = i;
      }
    }
    scanf("%d", &Q);
    int in;
    for(int i = 0; i < Q; i++){
      scanf("%d", &in);
      if(arr[in] <= 0)
	puts("UNDETERMINED");
      else
	puts(data[arr[in]]);
    }
    if(T)//I hate to check whether should output empty line at the end
      puts("");
  }
  return 0;
}