#include <stdio.h>
#include <string.h>
#include <cmath>

int main(){
	char s[1004];
	int odd, even;
	int index;
	while(gets(s) && s[0] != '0'){
		odd = 0;
		even = 0;
		index = 0;
		while(s[index]){
			if(index % 2){
				odd += s[index] - '0';
			} else {
				even += s[index] - '0';
			}
			index++;
		}
		fputs(s, stdout);
		if(int(std::abs(odd-even)) % 11 == 0){
			puts(" is a multiple of 11.");
		} else {
			puts(" is not a multiple of 11.");
		}
	}
	return 0;
}