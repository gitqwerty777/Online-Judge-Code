#include <stdio.h>

int T, N; 
int arr[55];
int count;

void Bubble_Sort_Counter(){
  count = 0;
  for(int i = N-2; i >= 0; i--){//???
    for(int j = 0; j <= i; j++)
      if(arr[j] > arr[j+1]){
	count++;
	int temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
      }
  }
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
      scanf("%d", &arr[i]);
    }
    Bubble_Sort_Counter();
    printf("Optimal train swapping takes %d swaps.\n", count);
  }
  return 0;
}