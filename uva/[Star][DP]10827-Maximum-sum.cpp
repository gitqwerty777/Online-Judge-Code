#include <cstdio>
#include <vector>
using namespace std;

int T, N;
vector< vector<int> > arr;
int maxv;

/*
  overlap -> duplicate the matrix 4 times to make bigger matrix
  others -> the same as uva-108(dp, compress)
 */

int main(){
  scanf("%d", &T);
  while(T--){
    maxv = -100;
    scanf("%d", &N);
    //printf("ss%d\n", N);
    arr.resize(2*N);
    for(int i = 0; i < 2*N; i++)
      arr[i].resize(2*N);
    //dot-based sum
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++){
	scanf("%d", &arr[i][j]);
	arr[i+N][j+N] = arr[i+N][j] = arr[i][j+N] = arr[i][j];
	if(maxv < arr[i][j])
	  maxv = arr[i][j];
      }
    N *= 2;
    //line-based sum
    for(int i = 0; i < N; i++)
      for(int j = 1; j < N; j++){
	arr[i][j] += arr[i][j-1];
	if(i < N/2 && j < N/2 && arr[i][j] > maxv)
	    maxv = arr[i][j];
      }
    for(int i = 0; i < N; i++)
      for(int j = 1; j < N; j++){
	arr[j][i] += arr[j-1][i];
	if(i < N/2 && j < N/2 && arr[j][i] > maxv)
	    maxv = arr[j][i];
      }
    //block-based sum
    for(int i1 = 0; i1 < N; i1++)
      for(int j1 = 0; j1 < N; j1++)
	for(int i2 = i1+1; i2 < N && i2 < i1+N/2+1; i2++)
	  for(int j2 = j1+1; j2 < N && j2 < j1+N/2+1; j2++)
	    if(arr[i2][j2]-arr[i1][j2]-arr[i2][j1]+arr[i1][j1] > maxv)
	      maxv = arr[i2][j2]-arr[i1][j2]-arr[i2][j1]+arr[i1][j1];

    printf("%d\n", maxv);
  }
}
