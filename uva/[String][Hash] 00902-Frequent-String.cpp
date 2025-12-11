#include <stdio.h>
#include <string.h>
#include <map>
std::map<long long, int> m;
long long power[11];

void make_power(){
  int base = 26;
  power[1] = 1;// no power[0]
  for(int i = 2; i <= 10; i++){
    power[i] = power[i-1] * base;
  }
}
int main(){
  int n;  char c; char s[11];
  make_power();
  while(scanf("%d", &n) == 1){
    m.clear();
    long long hash = 0;
    c = getchar();//space
    for(int i = 0; i < n; i++){
      s[i] = getchar();
      hash *= 26;
      hash += s[i] - 'a';
    }
    m[hash] = 1;
    int max = 1; long long maxv = hash;
    int prei = 0; int index = n;
    while((s[index] = getchar()) != EOF && s[index] != '\n'){
      hash -= (s[prei] - 'a') * power[n];
      hash *= 26;
      hash += s[index] - 'a';
      //      printf("nowi = %d, nowhash = %lld\n", i, hash);
      if(m.find(hash) == m.end()){
	m[hash] = 1;
      } else{
	m[hash]++;
      }
      if(m[hash] > max){
	max = m[hash];
	maxv = hash;
      }
      prei = (prei+1)%(n+1);
      index = (index+1)%(n+1);
    }
    //    printf("maxn = %d, maxv = %lld\n", max, maxv);
    char ans[11];
    memset(ans, '\0', sizeof(ans));
    for(int i = n-1; i >= 0; i-- ){
      ans[i] = maxv % 26 + 'a';
      maxv /= 26;
    }
    puts(ans);
  }
  return 0;
}