#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  char in[16] = "";
  char out[8];
  const char noans[] = "?";
    int n = 0;
    int a, b, c; char op;
    int ans;
    while(gets(in) != NULL){
      sscanf(in, "%d%c%d=%s", &a, &op, &b, out);
      //      printf("%d %c %d = %s\n", a, op, b, out);
      if(strcmp(out, noans) == 0)
	continue;
      if(op == '+')
	ans = a + b;
      else
	ans = a - b;
      if(atoi(out) == ans)
	n++;
    }
    printf("%d\n", n);//need change line
  return 0;
}