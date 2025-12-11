#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int arr[105][105];
int R, C;
//just list all possibilities
int wayc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int wayr[8] = {1, 1, 1, 0, 0, -1, -1, -1};

void Sweeping(){
  for(int i = 1; i <= R; i++)
    for(int j = 1; j <= C; j++)
      if(arr[i][j] == -1)
	for(int k = 0; k < 8; k++)
	  if(arr[i+wayr[k]][j+wayc[k]] >= 0)
	    arr[i+wayr[k]][j+wayc[k]]++;
}

int main(){
  char ch;
  int count = 1;
  while(scanf("%d %d", &R, &C) == 2 && R+C){
    if(count > 1){
      putchar('\n');
    }
    memset(arr, '\0', sizeof(char)*105*105);
    for(int i = 1; i <= R; i++){//special: 1 to R, use to make code easier
      for(int j = 1; j <= C; j++){
	while(scanf("%c", &ch) == 1 && ch != '*' && ch != '.'){
	  ;
	}
	arr[i][j] = (ch == '*')?-1:0;
      }
    }
    Sweeping();
    //printmine
    printf("Field #%d:\n", count++);
    for(int i = 1; i <= R; i++){
      for(int j = 1; j <= C; j++){
	if(arr[i][j] >= 0)
	  printf("%d", arr[i][j]);
	else{
	  putchar('*');
	}
      }
      putchar('\n');
    }
  }
  return 0;
}