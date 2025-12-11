#include <stdio.h>
#include <string.h>
#include <algorithm>

char in[512];
char next[512];
int len;

bool check_order(){
  for(int i = 0; i < len; i++){
    if(in[i] > next[i])
      return false;
    else if(in[i] < next[i])
      return true;
  }
  return false;//the same
}

int main(){

  while(gets(in) != NULL){
    if(in[0] == '#')
      break;
    len = strlen(in);
    strcpy(next, in);
    std::next_permutation(next, next+len);
    if(!check_order()){
      puts("No Successor");
    } else {
      puts(next);
    }
  }
  return 0;
}