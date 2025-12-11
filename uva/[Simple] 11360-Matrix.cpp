#include <stdio.h>
#include <string.h>

char arr[54][54];
int N;

void inc(){
  for(int i = 0; i < N ;i++)
    for(int j = 0; j < N; j++)
      arr[i][j]++;
}

void dec(){
  for(int i = 0; i < N ;i++)
    for(int j = 0; j < N; j++)
      arr[i][j]--;
}

void row(int a, int b){
  a--; b--;
  for(int i = 0; i < N ;i++){
    int tmp = arr[a][i];
    arr[a][i] = arr[b][i];
    arr[b][i] = tmp;
  }
}

void col(int a, int b){
  a--; b--;
  for(int i = 0; i < N ;i++){
    int tmp = arr[i][a];
    arr[i][a] = arr[i][b];
    arr[i][b] = tmp;
  }
}

void trans(){
  for(int i = 0; i < N; i++)
    for(int j = 0 ;j < i; j++){
      int tmp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = tmp;
    }
}

int main(){
  int T, Q;
  scanf("%d", &T);
  for(int t = 0; t < T; t++){
    scanf("%d", &N);
    char in[100];
    for(int i = 0; i < N; i++){
      gets(in);
      for(int j = 0; j < N; j++)
	scanf("%c", &arr[i][j]);
    }
    scanf("%d", &Q);
    int a, b;
    for(int i = 0; i < Q; i++){
      scanf("%s", in);
      //      printf("in = %s\n", in);
      if(strcmp("inc", in) == 0){
	inc();
      } else if(strcmp("dec", in) == 0){
	dec();
      } else if(strcmp("row", in) == 0){
	scanf("%d %d", &a, &b);
	row(a, b);
      } else if(strcmp("col", in) == 0){
	scanf("%d %d", &a, &b);
	col(a, b);
      } else if(strcmp("transpose", in) == 0){
	trans();
      } else{
	puts("...");
      }
    }
    printf("Case #%d\n", t+1);
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	while(arr[i][j] < '0')
	  arr[i][j] += 10;
	while(arr[i][j] > '9')
	  arr[i][j] -= 10;
	printf("%c", arr[i][j]);
      }
      puts("");
    }
    puts("");
  }
  return 0;
}
