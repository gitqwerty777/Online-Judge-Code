#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXINT 2147483647
using namespace std;

int ucount = 0;
vector<int> ugly;
int Check_Ugly(){
  for(int i = 1; i < MAXINT; i++){
    int temp = i;
    while(temp % 2 == 0){
      temp /= 2;
    }
    while(temp % 3 == 0){
      temp /= 3;
    }
    while(temp % 5 == 0){
      temp /= 5;
    }
    if(temp == 1){
      ugly.push_back(i);
      ucount++;
      if(ucount == 1500){
	      return i;
      }
    }
  }
}

int main(){
  //  printf("%d\n", Check_Ugly());
  puts("The 1500'th ugly number is 859963392.");
  return 0;
}