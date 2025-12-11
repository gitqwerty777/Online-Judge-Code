#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> ans(30);
vector<int> input(30);
vector<int> tryorder(30);
vector<int> correct(30);
vector<int> correctorder(30);
vector<int> reversecorrect(30);

//the difficulty of this problem is its input...

void findLIS(){
  for(int i = 0; i < N; i++)
    ans[i] = 1;
  for(int i = 1; i < N; i++)
    for(int j = 0; j < i; j++)
      if(tryorder[i] > tryorder[j])
	ans[i] = max(ans[j]+1, ans[i]);
}

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &correct[i]);
    correctorder[correct[i]-1] = i;//order array
  }
  for(int i = 0; i < N ;i++)
    reversecorrect[correctorder[i]] = i;//renumber
  /*printf("correct order");
  for(int i = 0; i < N ;i++)
    printf("%d ", correctorder[i]);
    puts("");*/
  while(scanf("%d", &input[0]) == 1){//is also an ordered array
    tryorder[input[0]-1] = reversecorrect[0];//assign new number
    for(int i = 1; i < N; i++){
      scanf("%d", &input[i]);
      tryorder[input[i]-1] = reversecorrect[i];
    }
    /*printf("try order: ");
    for(int i = 0; i < N; i++){
      printf("%d ", tryorder[i]);
    }
    puts("");*/
    findLIS();
    //important: find max(ans vector)
    int maxv = 0;
    for(int i = 0; i < N; i++)
      maxv = max(maxv, ans[i]);
    printf("%d\n", maxv);
  }
}
