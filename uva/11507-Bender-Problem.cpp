#include <stdio.h>
#include <string.h>

char directionChar[][10] = {"+x", "-x", "+y", "-y", "+z", "-z"};
char s[10];

int main(){
  int N;
  while(scanf("%d\n", &N) == 1 && N){
    int dir = 0;
    for(int i = 0; i < N-1; i++){
      scanf("%s", s);
      if(!strcmp(s, "No"))
	continue;
      else if(!strcmp(s, "+z")) {
	if(dir == 0)        dir = 4;//+x->+z
	else if(dir == 1)   dir = 5;//-x->-z
	else if(dir == 4)   dir = 1;//+z->-x
	else if(dir == 5)   dir = 0;//-z->+x
      }
      else if(!strcmp(s, "-z")) {
	if(dir == 0)        dir = 5;//+x->-z
	else if(dir == 1)   dir = 4;//-x->+z
	else if(dir == 4)   dir = 0;//+z->+x
	else if(dir == 5)   dir = 1;//-z->-x
      }
      else if(!strcmp(s, "+y")) {
	if(dir == 0)        dir = 2;//+x->+y
	else if(dir == 1)   dir = 3;//-x->-y
	else if(dir == 2)   dir = 1;//+y->-x
	else if(dir == 3)   dir = 0;//-y->+x
      }
      else if(!strcmp(s, "-y")) {
	if(dir == 0)        dir = 3;//+x->-y
	else if(dir == 1)   dir = 2;//-x->+y
	else if(dir == 2)   dir = 0;//+y->+x
	else if(dir == 3)   dir = 1;//-y->-x
      }
    }
    printf("%s\n", directionChar[dir]);
  }
}
