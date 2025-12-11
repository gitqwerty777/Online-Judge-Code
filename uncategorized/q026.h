#include <stdio.h>

int changeline = 0;
int N;
int first = 1;//first num in a line

int input(){
  char cha;
  unsigned int x=0,flag=1;   
  while(cha=getchar())   
    if(cha!=' '&&cha!='\n') break;
  if(cha!='-')
    x=x*10+cha-48;  
  else
	flag = -1;   
  while(cha=getchar()){   
    if(cha==' '||cha=='\n') break;
	else if(cha == '\n') changeline = 1;//only check one time(after number)
    x=x*10+cha-48;
  }
  N--;
  return x*flag;
}

int main(){
	int in;
	int min = 2147483647;
	long minans = 43000000000;
	long temp;
	scanf("%d", &N);
	while(N && in = input()){
		if(first){
			min = in;
		} else if(minans > (temp = in - min)){
			minans = temp;
		}
		if(min > in){
			min = in;
		}
		if(changeline){
			first = 1;
			changeline = 0;
		}
	}
	printf("%ld\n", minans);
	return 0;
}