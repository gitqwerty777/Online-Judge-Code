#include <stdio.h>

void print_upper_triangle(int& a){
	for(int i = 1;i < a; i++){
		for(int j = 0; j < i; j++){
			putchar('0'+i);
		}
		puts("");
	}
}

void print_line(int& a){
	for(int i = 0; i < a; i++)
		putchar('0'+a);
	puts("");
}

void print_lower_triangle(int& a){
	for(int i = a-1;i > 0; i--){
		for(int j = 0; j < i; j++){
			putchar('0'+i);
		}
		puts("");
	}
}

int main(){
	int N, A, F;
	scanf("%d", &N);
	
	while(N--){
		scanf("%d %d", &A, &F);
		for(int i = 0; i < F; i++){
			print_upper_triangle(A);
			print_line(A);
			print_lower_triangle(A);
			if(N != 0 || i != F-1)
				puts("");
		}
	}


	return 0;
}