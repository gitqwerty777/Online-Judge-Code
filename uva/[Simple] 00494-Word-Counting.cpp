#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char s[9999] = "";
	int count, nowi;
	while(gets(s)){
		count = 0;
		nowi = 0;
		while(s[nowi] != '\0'){
			if(isalpha(s[nowi])){
				count++;
				while(isalpha(s[nowi])){
					nowi++;
				}
			} else {
				nowi++;
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}