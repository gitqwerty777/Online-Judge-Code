#include <stdio.h>

char ans[1000004];

int main(){
  int T;
  int d;
  int a, b;
  char in[20];

  scanf("%d", &T);
  while(T--){
    scanf("%d", &d);
    int count = 0;
    bool carry = false;
    while(d--){
      scanf("%d %d", &a, &b);//stupid input method... why not two string...
      ans[count] = a + b + '0';
      int ccount = count;
      while(ans[ccount] > '9'){
        ans[ccount] -= 10;
        if(ccount == 0){
          carry = true;
          break;
        } else {
          ans[ccount-1]++;
        }
        ccount--;
      }
      count++;
    }
    ans[count] = '\0';
    if(carry){
      putchar('1');
    }
    puts(ans);
    if(T){
      puts("");
    }
  }
}