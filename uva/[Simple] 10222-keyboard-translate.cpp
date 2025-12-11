#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char key[] = {"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};// two '\'??

int main(){
	char c;
	char *in;
	int size = strlen(key);
	while((c = getchar()) != EOF){
		if(c == '\n')
			puts("");
		else if(c == ' ')
			putchar(c);
		else if(c == '`')
			putchar('.');
		else if(c == '1')
			putchar('/');
		else{
			c = tolower(c);
			for(int i = 2; i < size ;i++){
				if(c == key[i]){
					putchar(key[i-2]);
					break;
				}
			}
		}
	}
	return 0;
}
