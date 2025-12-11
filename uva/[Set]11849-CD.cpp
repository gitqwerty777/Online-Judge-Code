#include <cstdio>
#include <set>
using namespace std;

//slow: 1.448s

int M,N;
set<int> s;

int main(){
  int n;
  while(scanf("%d%d", &M,&N) == 2 && M+N){
    s.clear();
    for(int i = 0; i < M; i++){
      scanf("%d", &n);
      s.insert(n);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
      scanf("%d", &n);
      if(s.find(n) != s.end())
	ans++;
    }
    printf("%d\n", ans);
  }
}
