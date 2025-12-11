#include <cstdio>
#include <vector>
using namespace std;

FILE* f;

struct ANS{
  ANS(long long a[]){
    for(int i = 0; i < 4; i++)
      v[i] = a[i];
    printf("%.02lf %.02lf %.02lf %.02lf\n", v[0]/100, v[1]/100, v[2]/100, v[3]/100);
  }
  void printAns(){
    fprintf(f, "%.02lf %.02lf %.02lf %.02lf\n", v[0]/100, v[1]/100, v[2]/100, v[3]/100);
  }
  double v[4];
};

long long ans[4];
vector<ANS> a;
void createAns(int d, long long sum, long long mul){
  if(d == 3){
    for(int i = ans[2]; i <= 2000; i++)
      if(mul*i == (sum+i)*1000000){
	ans[3] = i;
	a.push_back(ANS(ans));
      }

    return;
  } else {
    int starti = (d==0)?1:ans[d-1];
    for(int i = starti; i <= 2000; i++){
      ans[d] = i;
      createAns(d+1, sum+i, mul*i);
    }
  }
}

int main(){
  f = fopen("11236ans.txt", "w");
  createAns(0, 0, 1);
  for(int i = 0; i < a.size(); i++)
    a[i].printAns();
}
