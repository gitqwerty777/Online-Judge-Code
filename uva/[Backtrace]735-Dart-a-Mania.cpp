#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;

int P, C, S;
vector<int> s;//possible answer
int ssize;
//C++11

struct score{
  score(int a[]){
    s[0] = a[0]; s[1] = a[1]; s[2] = a[2];
  }
  int s[3];
};

int ans[3];
vector<score> a;
void makeAns(int d, int nows){
  if(d == 2){
    int ans2value = S - nows;
    ans[2] = find(s.begin(), s.end(), ans2value) - s.begin(); //get index
    if(ans[2] < ans[1] || ans[2] >= ssize)
      return;
    a.push_back(score(ans));
  } else {
    int starts = (d==0)?0:ans[d-1];
    for(int i = starts; i < ssize && nows + s[i] <= S; i++){
      ans[d] = i;
      makeAns(d+1, nows+s[i]);
    }
  }
}

void getPossibleNum(){
  P = 0; C = 0;
  makeAns(0, 0);
  C = a.size();
  for(int i = 0; i < a.size(); i++){
    int p = 0;
    if(a[i].s[0] == a[i].s[1])
      p++;
    if(a[i].s[1] == a[i].s[2])
      p++;
    if(a[i].s[0] == a[i].s[2])
      p++;
    if(p == 3)
      P += 1;
    else if(p == 1)
      P += 3;
    else
      P += 6;
  }
}

void getPossibleScore(){
  set<int, std::less<int> > myset;
  for(int i = 1; i <= 20; i++){
    myset.insert(i);
    myset.insert(i*2);
    myset.insert(i*3);
  }
  myset.insert(0);
  myset.insert(50);
  for(auto it = myset.begin(); it != myset.end(); it++){
    s.push_back(*it);
  }
  ssize = s.size();
}

int main(){
  getPossibleScore();
  while(scanf("%d", &S) == 1 && S > 0){
    a.clear();
    getPossibleNum();
    if(S <= 180 && P > 0){
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", S, C, S, P);} else {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", S);
    } 
    puts("**********************************************************************");
  }
  puts("END OF OUTPUT");
}
