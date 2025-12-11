#include <stdio.h>
#include <math.h>

/*
Given a set of numbers, p(choose two numbers with no common factor) = 6/(pi^2)

For example, using the small collection of numbers: 2, 3, 4, 5, 6; there are 10 pairs that can be formed: (2,3), (2,4), etc. Six of the 10 pairs: (2,3), (2,5), (3,4), (3,5), (4,5) and (5,6) have no common factor other than one.
*/


bool isprime(int a, int b){
  while(a != 0){
    if(a < b){
      int temp = a;
      a = b;
      b = temp;
    }
    a %= b;
  }
  return b == 1;
}

int arr[54];
int main(){
  int N;
  while(scanf("%d", &N) == 1 && N){
    int p = 0;
    int sum = N * (N-1) / 2;
    for(int i = 0; i < N; i++){
      scanf("%d", &arr[i]);
      for(int j = 0; j < i; j++)
	if(isprime(arr[i], arr[j]))
	  p++;
    }
    if(p == 0){
      puts("No estimate for this data set.");
    }else{
      double pi = sqrt((double)6 / p * sum);
      printf("%lf\n", pi);
    }
  }
  return 0;
}