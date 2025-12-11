#include <stdio.h>
#include <string.h>
//different output format...
//wrong: http://uva.onlinejudge.org/external/127/p12700.pdf
//correct: http://uva.onlinejudge.org/contests/327-a712ef27/12700.pdf

int main(){
  int T;
  int G;
  int arr[4];//b, w, t, a
  char in[14] = "";

  scanf("%d", &T);
  int count = 1;
  while(T--){
    memset(arr, 0, sizeof(int)*4);
    scanf("%d", &G);
    scanf("%s", in);
    int len = strlen(in);
    for(int i = 0; i < len; i++){
      switch(in[i]){
      case 'B':
	arr[0]++;
	break;
      case 'W':
	arr[1]++;
	break;
      case 'T':
	arr[2]++;
	break;
      case 'A':
	arr[3]++;
	break;
      default:
	printf("Unexpected Input!\n");
      }
    }
    printf("Case %d: ", count++);
    if(arr[3] == len){
      printf("ABANDONED");
    } else if (arr[0] == arr[1]) {
      printf("DRAW %d %d", arr[0], arr[2]);
    } else if(arr[2] == 0 && arr[0] == 0){
      printf("WHITEWASH");
    } else if (arr[2] == 0 && arr[1] == 0){
      printf("BANGLAWASH");
    } else {
      if(arr[0] > arr[1]){
	printf("BANGLADESH %d - %d", arr[0], arr[1]);
      } else {
	printf("WWW %d - %d", arr[1], arr[0]);
      }
    }
    puts("");
  }
  return 0;
}