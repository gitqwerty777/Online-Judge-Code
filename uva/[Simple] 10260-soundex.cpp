#include <stdio.h>
#include <string.h>

int main(){
	char s[24];
	int trans[100];
	memset(trans, -1, sizeof(trans));
	trans['B'] = 1;trans['F'] = 1;trans['P'] = 1;trans['V'] = 1;
	trans['C'] = 2;trans['G'] = 2;trans['J'] = 2;trans['K'] = 2;
	trans['Q'] = 2;trans['S'] = 2;trans['X'] = 2;trans['Z'] = 2;
	trans['D'] = 3;trans['T'] = 3;
	trans['L'] = 4;
	trans['N'] = 5;trans['M'] = 5;
	trans['R'] = 6;
	bool first = true;
	while(scanf("%s", s) == 1){
		// if(first)
		// 	first = false;
		// else
		// 	puts("");
		int size = strlen(s);
		int pre = -2;
		for(int i = 0; i < size; i++){
			if((pre = trans[s[i]]) != -1){
				printf("%d", trans[s[i]]);
				while(i+1 < size && trans[s[i+1]] == pre){
					i++;
				}
			}
		}
		puts("");
	}
	return 0;
}
