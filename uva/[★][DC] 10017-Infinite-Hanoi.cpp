#include <stdio.h>
#define STICKSUM 6 // 1 + 2 + 3
int state[251];//where the i-th plate was
//Output is very annoying
int platen, moven;
char stickname[][4] = {"A", "B", "C"};

void print_State(){
  bool first;
  puts("");
  for(int i = 0; i < 3; i++){
    printf("%s=>", stickname[i]);
    first = true;
    for(int j = platen; j >= 1 ; j--){
      if(state[j] == i+1){
	if(first){
	  printf("  ");
	  first = false;
	}
	printf(" %d", j);
      }
    }
    puts("");
  }
}

void move_Hanoi(int platen, int moveto){
  if(platen == 0)
    return;
  //printf("move to %d\n", STICKSUM-state[platen]-moveto);
  move_Hanoi(platen-1, STICKSUM-state[platen]-moveto);
  if(moven == 0)
    return;
  state[platen] = moveto;
  print_State();
  moven--;
  move_Hanoi(platen-1, moveto);
}

int main(){
  int count = 1;
  while(scanf("%d %d", &platen, &moven) == 2 && platen + moven){
    for(int i = 1; i <= platen; i++)//no memset
      state[i] = 1;
    printf("Problem #%d\n", count++);
    print_State();
    move_Hanoi(platen, 3);
    puts("");
  }
  return 0;
}
