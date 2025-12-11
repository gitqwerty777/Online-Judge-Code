#include <stdio.h>

int main(){
  int N;
  int in;
  while(scanf("%d", &N) == 1 && N){
    int max = 0; int sum = 0;
    int msum = 0; bool isminus = false;
    for(int i = 0; i < N; i++){
      scanf("%d", &in);
      /*      if(isminus){
	msum += in;
	if(msum > 0){
	 isminus = false;
	 sum += msum;
	} else 	if(-msum > sum){
	  sum = 0;
	  isminus = false;
	}
      } else if(in >= 0){
	sum += in;
      } else {
	isminus = true;
	msum = in;
	if(-msum >= max){
	  sum = 0;
	  isminus = false;
	}
      }
      if(sum > max)
      max = sum;*/

      //sometimes we only think it simply...
      if(sum + in > 0)
	sum += in;
      else
	sum = 0;
      if(sum > max)
	max = sum;
    }
    if(max > 0)// 0 = losing
      printf("The maximum winning streak is %d.\n", max);
    else
      puts("Losing streak.");
  }
  return 0;
}