#include <stdio.h>
#include <vector>
using namespace std;

int T, N;

vector<int> total;
vector<int> next;
vector<bool> isvisited;

void doDFS(){
  for(int i = 0; i < N; i++){
    if(isvisited[i])
      continue;
    isvisited[i] = true;
    vector<bool> visited(N);
    std::fill(visited.begin(), visited.end(), false);
    int count = 0, nowi = i;
    while(!visited[nowi]){
      visited[nowi] = true;
      nowi = next[nowi];
      count++;
    }
    if(nowi == i){// i in the cycle
      for(int j = 0; j < N; j++){
	if(visited[j]){
	  total[j] = count;
	  isvisited[j] = true;
	}
      }
    } else {
      total[i] = count;
    }
  }
}

int main(){
  scanf("%d", &T);
  total.resize(50000);
  next.resize(50000);
  isvisited.resize(50000);
  int u, v;
  
  for(int t = 0; t < T; t++){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
      scanf("%d %d", &u, &v);
      next[u-1] = v-1;//0 ~ N-1
    }

    std::fill(isvisited.begin(), isvisited.end(), false);
    doDFS();
    
    int maxv = total[0], maxi = 0;
    for(int i = 0; i < N; i++){
      //printf("p%d = %d\n", i+1, total[i]);
      if(maxv < total[i]){
	maxv = total[i];
	maxi = i;
      }
    }
    printf("Case %d: %d\n", t+1, maxi+1);
  }
  return 0;
}
