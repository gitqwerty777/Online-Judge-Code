#include <stdio.h>
#include <map>
#include <ctype.h>
#include <string.h>
std::map<int,int> m;

void fib(){
  int a[3];
  a[0] = 1;
  a[1] = 2;
  m[1] = 0;
  m[2] = 1;
  int count = 2;
  for(int i = 2; ; i = (i+1)%3){
    a[i] = a[(i+1)%3] + a[(i+2)%3];
    if(a[i] < 0)
      break;
    m[a[i]] = count++;
  }
}

int main(){
  fib();
  int T, N;
  scanf("%d", &T);
  char ans[104]; char in[104]; int pos[104];
  while(T-- && scanf("%d", &N) == 1){
    for(int i = 0; i < N; i++)
      scanf("%d", &pos[i]);
    gets(in); gets(in);//first is '\n'
    int index = 0; int count = 0;
    memset(ans, ' ', sizeof(ans));
    while(count < N && in[index] != '\0'){
      if(!isupper(in[index])){
	index++;
	continue;
      }
      //      printf("ans[%d] = %c\n", m[pos[count]], in[index]);
      ans[m[pos[count++]]] = in[index++];
    }
    for(int i = 103; i >= 0; i--){
      if(ans[i] == ' ')
	continue;
      else{
	ans[i+1] = '\0';
	break;
      }
    }
    puts(ans);
    
  }
  return 0;
}