#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

char s[100];
struct word{
  word(){
    c = 0;
  }
  string s;
  int c;
  bool operator<(const word& w) const {
    return this->c < w.c;
  }
};

map<word, vector<word> > m;
vector<string> v;

int main(){
  while(gets(s)){
    if(strcmp(s, "#") == 0)
      break;
    
    char *p = strtok(s, " ");
    word w;
    for(int i = 0; i < strlen(p); i++)
      w.c += 1<<(tolower(p[i])-'a');
    w.s = string(p);
    m[w].push_back(w);
    
    while((p = strtok(NULL, " ")) != NULL){
      word w;
      for(int i = 0; i < strlen(p); i++)
	w.c += 1<<(tolower(p[i])-'a');
      w.s = string(p);
      m[w].push_back(w);
    }
  }
  //iterate all element in map
  for (auto it = m.begin(); it != m.end(); ++it)
    if(it->second.size() == 1)
      v.push_back(it->second[0].s);

  std::sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
    printf("%s\n", v[i].c_str());
}
