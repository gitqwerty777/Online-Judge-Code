#include <stdio.h>
#include <stack>
using namespace std;

int main(){
  stack<int> s;
  int arr[1004];
  int N; int in;
  while(scanf("%d", &N) == 1 && N){
    while(scanf("%d", &arr[0]) == 1){
      if(arr[0] == 0){
	puts("");
	break;
      } else {
	for(int i = 1; i < N; i++)
	  scanf("%d", &arr[i]);
	while(!s.empty())
	  s.pop();
	int count = 0;
	for(int i = 1; i <= N; i++){
	  s.push(i);
	  while(count < N && !s.empty() && arr[count] == s.top()){
	    s.pop(); count++;
	  }
	}
	if(s.empty())
	  puts("Yes");
	else
	  puts("No");
      }
    }
  }
  return 0;
}