#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
#define maxnum 2000000001

int h[4] = {2, 3, 5, 7};
std::set<int> ans;
std::vector<int> humble;
std::vector<long long> pow[4];

void getPow(){
  long long p;
  for(int i = 0; i < 4; i++){
    p = 1;
    pow[i].push_back(p);
    while(1){
      p = p * h[i];
      if(p < maxnum)
	pow[i].push_back(p);
      else
	break;
    }
  }
}

void findHumble(int d, int v){
  if(d == 4){
    if(v <= maxnum)
      ans.insert(v);
  } else {
    for(int i = 0; i < pow[d].size(); i++){
      if(pow[d][i] * v > maxnum)
	return;
      findHumble(d+1, pow[d][i] * v);
    }
  }
}

void findHumbleNumbers(){
  getPow();
  findHumble(0, 1);
  humble.assign(ans.begin(), ans.end());
  std::sort(humble.begin(), humble.end());
  //printf("find %d humble\n", humble.size());
}

int N;
char suffix[][3] = {"st", "nd", "rd", "th"};
int main(){
  findHumbleNumbers();
  while(scanf("%d", &N) == 1 && N){
    int suffixi = 3;
    if(N % 10 == 1){
      if(N%100 != 11)//why waste my time...
	suffixi = 0;
    } else if(N % 10 == 2){
      if(N%100 != 12)
	suffixi = 1;
    } else if(N % 10 == 3){
      if(N%100 != 13)
	suffixi = 2;
    }
    printf("The %d%s humble number is %d.\n", N, suffix[suffixi], humble[N-1]);
  }
}


