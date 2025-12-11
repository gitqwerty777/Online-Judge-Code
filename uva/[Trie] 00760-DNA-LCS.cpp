#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <assert.h>
#include <string>
#include <algorithm>

int ts[128];//ascii(acgt) -> trie's index
void make_trans(){
  ts['a'] = 0;
  ts['c'] = 1;
  ts['g'] = 2;
  ts['t'] = 3;
}

struct trie{
  trie(){
    n[0] = n[1] = n[2] = n[3] = NULL;//if not set null, it would be random??
    num = 0;
  }
  struct trie* n[4];//a c g t
  int num;
};
typedef struct trie tt;
tt node[100000];
int nodei = 0;

void make_trie(tt* t, char* s){
  int l = strlen(s);
  for(int i = 0; i < nodei; i++){
    for(int j = 0; j < 4; j++)
      node[i].n[j] = NULL;
    node[i].num = 0;
  }
  nodei = 0;
  for(int i = 0; i < l ;i++){
    tt* temp = t;
    for(int j = i; j < l; j++){//from s[0][i] to s[0][j], make trie
      int index = ts[s[j]];
      if(temp->n[index] == NULL)
	temp->n[index] = &node[nodei++];
      temp = temp->n[index];
      temp->num++;
    }
  }
}

inline int min(int a, int b){
  return (a>b)?b:a;
}

int anslen;
std::vector<int> v;
bool match(tt* t, char* s, char* s1){
  v.clear();
  int l = strlen(s);
  int l1 = strlen(s1);
  int maxl = min(l, l1);
  for(int i = maxl-1; i >= 0; i--){//common string length = i
    bool findans = false;
    for(int j = 0; i+j < l; j++){//start from j
      tt* temp = t;
      for(int k = j; k <= i+j; k++){
	int index = ts[s[k]];
	temp = temp->n[index];
	if(temp == NULL)
	  break;
      }
      if(temp != NULL && temp->num){//find one of the ans
	anslen = i;
	v.push_back(j);
	findans = true;
      }
    }
    if(findans)//find all answer with length i
      return true;
  }
  return false;
}

int main(){
  make_trans();
  char s[2][304];
  bool first = false;
  while(gets(s[0]) != NULL){
    if(first)
      puts("");
    else
      first = true;
    gets(s[1]);
    struct trie t;
    make_trie(&t, s[0]);
    if(!match(&t, s[1], s[0])){
      puts("No common sequence.");
    } else {
      std::vector<std::string> ans;
      ans.clear();
      for(int i = 0; i < v.size(); i++)
	ans.push_back(std::string(&s[1][v[i]], anslen+1));
      sort(ans.begin(), ans.end());
      for(int i = 0; i < ans.size(); i++){//delete the same ans
	if(i ==  ans.size()-1 || ans[i] != ans[i+1])
	  printf("%s\n", ans[i].c_str());
      }
    }
    gets(s[0]);//empty line
  }
  
  return 0;
}