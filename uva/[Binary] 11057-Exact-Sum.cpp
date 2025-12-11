#include <stdio.h>
#include <algorithm>

int arr[10004];
int N;

inline int abs(int n){
  return (n >= 0)?n:-n;
}

inline int min(int a, int b){
  return (a>b)?a:b;
}

int find_mid(int n){
  int start = 0, end = N-1;
  int mid = (start + end) / 2;
  while(start <= end){
    if(arr[mid] > n)
      end = mid-1;
    else if(arr[mid] < n)
      start = mid + 1;
    else
      return mid;
    mid = (start+end)/2;
  }
  //printf("start = %d end = %d\n", start, end);
  if(start > N-1)
    start--;
  if(end < 0)
    end++;
  //printf("start = %d end = %d\n", start, end);
  int ret;
  if(abs(arr[start]-n) <= abs(arr[end]-n))
    ret = start;
  else
    ret = end;
  while(ret-1 >= 0 && arr[ret]>n)
    ret--;
  return ret;
}

int main(){
  int in;
  while(scanf("%d", &N) == 1){
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);
    std::sort(arr, arr+N);
    scanf("%d", &in);
    int mid = in/2;
    int index = find_mid(mid);
    int u = index+1, d = index;//assured in find_mid
    //printf("now d[%d] = %d u[%d] = %d\n", d, arr[d], u, arr[u]);
    while(u < N && d >= 0){
      //printf("now d[%d] = %d u[%d] = %d\n", d, arr[d], u, arr[u]);
      if(arr[u] + arr[d] > in)
	d--;
      else if(arr[u] + arr[d] < in)
	u++;
      else
	break;
    }
    if(d >= 0 && u < N)
      printf("Peter should buy books whose prices are %d and %d.\n", arr[d], arr[u]);
    puts("");
  }
  return 0;
}