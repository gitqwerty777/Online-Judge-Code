#include <cstdio>
#include <cstring>


int T;
char s[5] = " .xW";
int arr[10];
int cell[45];
int newcell[45];
const int days = 50, cells = 40, dnas = 10;

void printCell(){
  for(int i = 1; i <= cells; i++)
    printf("%c", s[cell[i]]);
  puts("");
}

void GrowCell(){
  for(int i = 1; i <= cells; i++)
    newcell[i] = arr[cell[i-1] + cell[i] + cell[i+1]];
  for(int i = 1; i <= cells; i++)
    cell[i] = newcell[i];
}

int main(){
  scanf("%d", &T);
  bool first = true;
  while(T--){
    if(first)
      first = false;
    else
      puts("");
    for(int i = 0; i < dnas; i++)
      scanf("%d", &arr[i]);
    memset(cell, 0, sizeof(cell));
    cell[20] = 1;//1~40
    printCell();
    for(int i = 1; i < days; i++){
      GrowCell();
      printCell();
    }
  }
}
