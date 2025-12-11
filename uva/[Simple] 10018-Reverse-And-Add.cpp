#include <stdio.h>
#include <string.h>

int N;
char in[20];

bool check_sym(char* sum){
  int len = strlen(sum);
  for(int i = 0; i*2 <= len; i++){
    if(sum[i] != sum[len-i-1])
      return false;
  }
  return true;
}

void Reverse_And_Add(){
  char sum[20];
  strcpy(sum, in);
  
  int count = 0;
  while(!check_sym(sum)){
    int len = strlen(in);
    bool addnum = false;
    for(int i = 0; i < len; i++){
      sum[len-i-1] += in[i]-'0';
      if(sum[len-i-1] > '9'){
	sum[len-i-1] -= 10;
	if(len-i-1 == 0){
	  addnum = true;
	} else {
	  sum[len-i-2]++;
	}
      }
    }
    strcpy(in, sum);
    if(addnum){
      strcpy(sum+1, in);
      sum[0] = '1';
      strcpy(in, sum);
    }
    count++;
    //    printf("%d %s\n", count, sum);
  }
  printf("%d %s\n", count, sum);
}

int main(){
  scanf("%d", &N);
  while(N--){
    scanf("%s", in);
    Reverse_And_Add();
  }
  return 0;
}