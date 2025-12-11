#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

//input and output of this problem is ugly...

int T;
bool hasAns;
bool limit[30][30];

char chars[26];//real char
int charcount;
int ans[26];//answer index
bool used[26];

bool checkLimit(int& d, int &nowi){
  if(d == 0)
    return true;
  for(int i = 0; i < charcount; i++)
    if(used[i] && limit[i][nowi])
      return false;
  return true;
}

void findAns(int d){
  if(d == charcount){
    hasAns = true;
      putchar(chars[ans[0]]);
    for(int i = 1; i < charcount; i++){
      putchar(' ');
      putchar(chars[ans[i]]);
    }
    puts("");
  } else {
    bool isfirst = (d==0);
    for(int i = 0; i < charcount; i++){
      if(checkLimit(d, i) && !used[i]){
	//choose i-th char
	used[i] = true;
	ans[d] = i;
	findAns(d+1);
	used[i] = false;
      }
    }
  }
}

int main(){
  scanf("%d\n\n", &T);
  bool first = true;
  char s[10000];
  while(T--){
    gets(s);
    if(strcmp(s, "") == 0){
      T++;
      continue;
    }
    if(!first)
      puts("");
    else
      first = false;
    memset(chars, '\0', sizeof(chars));
    charcount = 0;
    char *p = strtok(s, " ");
    char reversechar[128];
    while(p != NULL){
      reversechar[*p] = charcount;
      chars[charcount++] = *p;
      p = strtok(NULL, " ");
    }
    //
    for(int i = 0; i < charcount; i++)
      for(int j = 0; j < charcount; j++)
	limit[i][j] = false;
    gets(s);
    p = strtok(s, " ");
    while(p != NULL){
      char a = p[0]; char b = p[2];
      limit[reversechar[b]][reversechar[a]] = true;
      p = strtok(NULL, " ");
    }
    //
    hasAns = false;
    findAns(0);
    if(!hasAns)
      puts("NO");
  }
}
