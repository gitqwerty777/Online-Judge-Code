#include <stdio.h>

int state[251];//number which is saved is where the plate was

int platen, moven;

char stickname[][4] = {"A", "B", "C"};

void print_State(){
	for(int i = 0; i < 3; i++){
		printf("%s:", stickname[i]);
		for(int j = 0; j < platen; j++)
			if(state[j] == i+1)
				printf(" %d", state[j]);
		puts("");
	}
}

void move_Hanoi(int platen, int moveto){
	if(platen == 0)
		break;
	move_Hanoi(platen-1, platen+1-state[platen]-moveto);
	state[platen] = moveto;
	print_State();
	moven--;
	if(!moven)
		break;
	move_Hanoi(platen-1, moveto);
}

int main(){
	while(scanf("%d %d", &platen, &moven) == 2 && platen && moven){
		for(int i = 1; i <= platen; i++){
			state[i] = 1;
		}
		move_Hanoi(platen, 3);
	}

	return 0;
}