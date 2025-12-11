#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char c;

	while((c = getchar()) != EOF){
		if(c == '\n')
			putchar(c);
		else
			putchar(c-7);
	}
	return 0;
}
