#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int cost, num;
typedef struct product{
  int c, f;
} product;

int arr[20000];
vector<product> v;
int ans;

bool checkCost(int c){
  if(c > 2000 && c <= cost + 200)
    return true;
  else if(c <= 2000 && c <= cost)
    return true;
  //  printf("cost = %d, c = %d\n", cost, c);
  return false;
}

void chooseProduct(int i, int c, int f){
  if(i == num){
    if(f > ans && checkCost(c))
      ans = f;
    return;
  } else {
    chooseProduct(i+1, c, f);
    chooseProduct(i+1, v[i].c + c, f + v[i].f);
  }
}

/*void findMaxValue(){
  ans = 0;
  chooseProduct(0, 0, 0);
}*/

void findMaxValue(){
  for(int i = 0; i <= cost+200; i++)
    arr[i] = -1;
  arr[0] = 0;
  for(int i = 0; i < num; i++)
    for(int j = cost+200; j -v[i].c >= 0; j--)
      if((arr[j-v[i].c] != -1))
	arr[j] = max(arr[j], arr[j-v[i].c] + v[i].f);
}

int main(){
  int c, f;
  while(scanf("%d %d", &cost, &num) == 2){
    v.clear();
    for(int i = 0; i < num; i++){
      scanf("%d %d", &c, &f);
      product p; p.c = c; p.f = f;
      v.push_back(p);
    }
    findMaxValue();
    int maxv = 0;
    for(int i = cost+200; i > 0 ; i--){
      //if(arr[i] != arr[i-1])
	//printf("least %d = %d\n", i, arr[i]);
      if(checkCost(i) && arr[i] > maxv)
	maxv = arr[i];
    }
    printf("%d\n", maxv);
  }
}
