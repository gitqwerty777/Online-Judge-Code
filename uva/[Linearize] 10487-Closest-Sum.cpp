#include <stdio.h>
#include <vector>
#include <algorithm>

int arr[1004];
struct ans{
  int i;//position
  int v;//value
  int a;//ans
};
struct ans quest[30];
std::vector<int> sum; //max = 1000*999/2 = 499500
int sumn = 0;
//from binary search(O(logN) * N) to linear search(O(N)) -> 1000 times faster

/*
int binary_search(int in){
  int start = 0;
  int end = sumn-1;
  int mid = (start + end) / 2;
  while(end - start > 1){
    if(sum[mid] > in){
      end = mid;
    } else if(sum[mid] < in){
      start = mid;
    } else {
      return in;
    }
    mid = (start + end) / 2;
  }
  //  printf("start[%d] = %d, mid[%d] = %d, end[%d] = %d\n", start, sum[start], mid, sum[mid], end, sum[end]);
  return (sum[end]-in > in-sum[start])?(sum[start]):(sum[end]);
  }
*/

bool cmpv(struct ans a, struct ans b){
  return (a.v < b.v);
}

bool cmpi(struct ans a, struct ans b){
  return (a.i < b.i);
}

int main(){
  int N, Q;
  int count = 1;
  while(scanf("%d", &N) == 1 && N){
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);
    sum.resize(N*(N-1)/2);
    sumn = 0;
    for(int i = 0; i < N; i++)
      for(int j = i+1; j < N; j++)
	      sum[sumn++] = arr[i] + arr[j];
    std::sort(sum.begin(), sum.end());
    /*    
      for(int i = 0; i < sum.size(); i++){
       printf("%d ", sum[i]);
      }
      puts("");
    */
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
      scanf("%d", &quest[i].v);
      quest[i].i = i;
    }
    std::sort(quest, quest+Q, cmpv);
    //lenear search
    int qi = 0;//quest index
    while(qi < Q && quest[qi].v < sum[0])
      quest[qi++].a = sum[0];
    bool end = false;
    for(int i = 1; i < sum.size() && !end; i++){
      while(quest[qi].v < sum[i]){
	quest[qi].a = (quest[qi].v-sum[i-1] > sum[i]-quest[qi].v)?(sum[i]):(sum[i-1]);
	qi++;
	if(qi >= Q){
	  end = true; break;
	}
      }
    }
    while(qi < Q)
      quest[qi++].a = sum[sum.size()-1];
    printf("Case %d:\n", count++);
    std::sort(quest, quest+Q, cmpi);
    for(int i = 0; i < Q; i++){
      printf("Closest sum to %d is %d.\n", quest[i].v, quest[i].a);
    }
  }
  return 0;
}