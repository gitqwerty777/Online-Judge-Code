#include <stdio.h>
#include <string.h>

char in[10004];
long long sum;
long long trans[257];//ascii?

int main(){
  int T, M, L;
  scanf("%d", &T);
  while(T--){
    //add space makes the change line character be scanned too!
    //clean way to code
    //Referenced by morris821028
    memset(trans, 0, sizeof(trans));
    scanf("%d", &M);
    gets(in);//dumb
    char c; long long p;
    for(int i = 0; i < M; i++){
      gets(in);
      //      printf("in=%s\n",in);
      sscanf(in+2, "%lld", &p);
      //      printf("-> %c = %lld, in[0] = %d\n", c, p, in[0]);
      trans[in[0]+128] = p;
    }
    scanf("%d\n", &L);
    sum = 0;
    while(L--){
      gets(in);
      //printf("in = %s\n", in);
      int len = strlen(in);
      for(int i = 0; i < len; i++){
	//printf("in = %c, $%lld\n", in[i], trans[in[i]]);
	sum += trans[in[i]+128];
      }
    }
    printf("%lld.%02lld$\n", sum/100, sum % 100);
  }
  return 0;
}
