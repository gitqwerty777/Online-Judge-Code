#include <stdio.h>
#include <string.h>
int t[10]; // 0~9

int main(){
  int T, N;
  scanf("%d", &T);
  int in, sum, countsum;
  
  while(scanf("%d", &N) == 1){
    memset(t, 0, sizeof(t));
    sum = 0; countsum = 0;
    for(int i = 0;i < N; i++){
      scanf("%d", &in);
      countsum += in/10;
      sum += in;
      t[in%10]++;
    }
    //分級：0~4, 5~14, 15~24...
    //x4 + x1, x3 + x2 = x5
    //若為x9 + x6(兩個都>5), 總價不變
    //所以x5~9不動，x1~4儘量加至 >x5
    //愈少數相加愈好
    //14, 23, 113, 122, 1112, 11111
    //9 + 9 + 9 + 9 + 9 = 45
    //1 + 1 + 1 + 1 + 1 = 5
    // 9 * 15 = 135
    // 15 -> 14
    //8 + 8 = 16
    //1 + 1 = 2
    //41 -> 42 -> 43 -> 44 -> 32 -> 31 -> 33 -> 21 -> 22 -> 11
    for(int i = 4;i>= 1;i--){
      for(int j = min(5-i, i); i >= j; j--){
	if(i == j){
	  int onefive = (5/i) + ((5%i)?1:0);
	  int five = t[i]/onefive;
	  t[i] -= five * onefive;
	} else if(i + j >= 5){
	  int five = min(t[i], t[j]);
	  t[i] -= five; t[j] -= five;
	} else {// can make five
	    int five = ;
	}
	countsum += five;
	if(t[i])//there are rest t[i], use it!
	  j++;
	else
	  i--;
      }
    }
  }
  
  return 0;
}  
