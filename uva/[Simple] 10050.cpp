#include <stdio.h>
#include <string.h>
int p[104];

bool days[3654];
bool nday[3700];

void find_nday(){
  memset(nday, false, sizeof(nday));
  for(int i = 0; i*7+7 < 3700; i++){
    nday[i*7+6] = true;
    nday[i*7+7] = true;
  }
}

int main(){
  int T, D, P;
  scanf("%d", &T);
  find_nday();
  while(T--){
    scanf("%d %d", &D, &P);
    for(int i = 0; i < P; i++)
      scanf("%d", &p[i]);
    memset(days, false, sizeof(days));
    for(int i = 0; i < P; i++)
      for(int j = 1; p[i]*j <= D; j++)
	days[p[i]*j] = true;
    int ans = 0;
    for(int i = 1; i <= D; i++)
      if(days[i] && !nday[i])
	  ans++;
    printf("%d\n", ans);
  }
  return 0;
}