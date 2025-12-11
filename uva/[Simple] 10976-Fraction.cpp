#include <stdio.h>
#include <vector>

struct ans{
  ans(int x, int y){
    a = x; b = y;
  }
  int a, b;
};

std::vector<std::vector<struct ans> > v;

void init_vector(){
  v.resize(10000);
}

void print_ans(int k, std::vector<struct ans> &vec){
  int s = vec.size();
  printf("%d\n", s);
  for(int i = 0; i < s; i++){
    printf("1/%d = 1/%d + 1/%d\n", k, v[k][i].b, v[k][i].a);
  }
}

void find_ans(int k){
  if(v[k].size() == 0){
    for(int i = k+1; i <= 2*k; i++){
      if((k*i) % (i-k) == 0){
	struct ans a(i, k*i/(i-k));
	v[k].push_back(a);
      }
    }
  }
  print_ans(k, v[k]);
}

int main(){
  int k;
  init_vector();
  while(scanf("%d", &k) == 1){
    find_ans(k);
  }
  
  return 0;
}