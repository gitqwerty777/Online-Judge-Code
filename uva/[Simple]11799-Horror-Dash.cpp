#include <stdio.h>

int T, N;
char s[500000];
int main(){
  scanf("%d\n", &T);
  int count = 1;
  int offset, n;
  while(T--){
    int max = 0;
    gets(s);
    char *ss= s;
    sscanf(ss, "%d%n", &N, &offset); ss += offset;
    while(sscanf(ss, "%d%n", &n, &offset) > 0){
      ss += offset;
      if(max < n)
	max = n;
    }
    printf("Case %d: %d\n", count++, max);
  }
  return 0;
}
