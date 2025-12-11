#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

void getString(char s[]) {
  char ch;
  int i=0;
  while( (ch = getchar()) != '\n'   &&   ch != EOF ) {
    s[i] = ch;
    ++i;
  }
  s[i] = '\0';
}

int N, T=10;
char s[111];
int count = 1;
int main(){
  scanf("%d\n", &N);

  int maxv;
  vector<string> maxn;
  int v;

  while(N--){
    maxv = 0;
    maxn.clear();
    for(int i = 0; i< T; i++){
      scanf("%s %d", s, &v);
      /*string str = string(s);
      int space = str.find(" ");
      v = atoi(str.substr(space+1, str.size()).c_str());
      if(i == 0)
	maxv = v;
	str = str.substr(0, space);*/
      if(i == 0)
	maxv = v;
      string str = string(s);
      if(v >= maxv) 
	if(v == maxv)
	  maxn.push_back(str);
	else{
	  maxv = v;
	  maxn.clear();
	  maxn.push_back(str);
	}
    }
    printf("Case #%d:\n", count++);
    for(int i = 0; i < maxn.size(); i++)
	printf("%s\n", maxn[i].c_str());
    getString(s);
  }
}
