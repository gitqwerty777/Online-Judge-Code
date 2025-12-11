#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct hotel{
  hotel(int price, int day){
    p = price;
    b.resize(day);
  }
  int p;
  vector<int> b;
};

int N, B, H, W;
vector<hotel> hotels;

bool cmpPrice(const hotel& a, const hotel&b){
  return a.p < b.p;
}

int ans;
int getMinBudget(){
  ans = 0;
  std::sort(hotels.begin(), hotels.end(), cmpPrice);
  for(int h = 0; h < H; h++){
    if(hotels[h].p * N > B)
	return -1;
    for(int w = 0; w < W; w++){
      if(hotels[h].b[w] >= N)
	return hotels[h].p*N;
    }
  }
  return -1;
}

int main(){
  int p;
  while(scanf("%d%d%d%d", &N, &B, &H, &W) == 4){
    hotels.clear();
    for(int i = 0; i < H; i++){
      scanf("%d", &p);
      hotel h(p, W);
      for(int j = 0; j < W; j++)
	scanf("%d", &h.b[j]);
      hotels.push_back(h);
    }
    int ans;
    if((ans = getMinBudget()) != -1)
      printf("%d\n", ans);
    else
      puts("stay home");
    
  }
}
