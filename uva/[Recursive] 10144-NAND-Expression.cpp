#include <stdio.h>
//Need not to know the theorey, just find it's logic
//http://zh.wikipedia.org/wiki/%E8%B0%A2%E8%B4%B9%E5%B0%94%E7%AB%96%E7%BA%BF

inline void print_Half_Adder_Cout(){
	printf("((A0|B0)|(A0|B0))");
}

void print_Cout(int n){
	if(n <= 0){
		if(n == 0)
			print_Half_Adder_Cout();
		return;
	}
	printf("((A%d|B%d)|(", n, n);
	print_Cout(n-1);
	printf("|((A%d|A%d)|(B%d|B%d))))", n, n, n, n);
}

int main(){
	int N, in;
	scanf("%d", &N);
	
	while(N--){
		scanf("%d", &in);
		print_Cout(in-1);
		puts("");
		if(N)
			puts("");
	}
	return 0;
}