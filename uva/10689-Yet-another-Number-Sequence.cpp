#include <cstdio>

int A, B, N, M, ans;
int m[] = {-1, 10, 100, 1000, 10000};//m[0] not used

int transform[2][2] = {{1, 1}, {1, 0}};

struct Matrix{
  BigNumber v[2][2];
  Matrix(){}
  Matrix(long long a, long long b, long long c, long long d){
    v[0][0] = a;
    v[0][1] = b;
    v[1][0] = c;
    v[1][1] = d;
  }
  Matrix operator*(Matrix &comp){
    Matrix newmatrix;
    newmatrix.v[0][0] = this->v[0][0]*comp.v[0][0] + this->v[0][1]*comp.v[1][0];
    newmatrix.v[0][1] = this->v[0][0]*comp.v[0][1] + this->v[0][1]*comp.v[1][1];
    newmatrix.v[1][0] = this->v[1][0]*comp.v[0][0] + this->v[1][1]*comp.v[1][0];
    newmatrix.v[1][1] = this->v[1][0]*comp.v[0][1] + this->v[1][1]*comp.v[1][1];
    //for this problem
    //for(int i = 0; i < 2; i++)
    //for(int j = 0; j < 2; j++)
    //newmatrix.v[i][j] %= m[M];
    this->print();
    puts("*");
    comp.print();
    puts("=");
    newmatrix.print();
    puts("");
    return newmatrix;
  }
  Matrix operator^(int n){
    Matrix newmatrix;
    Matrix base = (*this);
    while(n>0){
      if(n & 1)//n%2
	newmatrix = base * newmatrix;
      base = base * base;
      n >>= 1;
    }
    return newmatrix;
  }
  void print(){
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++)
	printf("%lld ", v[i][j]);
      puts("");
    }
  }
};

Matrix newm;
void getMod(){
  Matrix basem(1, 1, 1, 0);
  newm = basem ^ N;
}

int main(){
  int T;
  scanf("%d", &T);
  while(scanf("%d%d%d%d", &A, &B, &N, &M) == 4){
    getMod();
    printf("%s\n", (newm.v[0][0]*A + newm.v[0][1]*B) % m[M]);
  }
}
