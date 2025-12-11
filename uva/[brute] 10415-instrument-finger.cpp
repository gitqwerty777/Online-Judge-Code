#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FINGERNUM 10

int fin[FINGERNUM + 1];
bool note[14][FINGERNUM + 1] = {
	// 0      1      2      3      4      5      6      7      8      9      10
	{false, false, true,  true,  false, false, false,  false, false, false, false},//a
	{false, false, true,  false, false, false, false,  false, false, false, false},//b
	{false, false, true,  true,  true, false, false,  true,  true,  true,  true},//c
	{false, false, true,  true,  true, false, false,  true,  true,  true, false},//d
	{false, false, true,  true,  true, false, false,  true,  true, false, false},//e
	{false, false, true,  true,  true, false, false,  true, false, false, false},//f
	{false, false, true,  true,  true, false, false,  false, false, false, false},//g
	{false, true,  true,  true,  false, false, false,  false, false, false, false},//A
	{false, true,  true,  false, false, false, false,  false, false, false, false},//B
	{false, false, false, true,  false, false, false,  false, false, false, false},//C
	{false, true,  true,  true,  true, false, false,  true,  true,  true, false},//D
	{false, true,  true,  true,  true, false, false,  true,  true, false, false},//E
	{false, true,  true,  true,  true, false, false,  true, false, false, false},//F
	{false, true,  true,  true,  true, false, false, false, false, false, false}//G
};

int getindex(char c){
	if(c >= 'a'){
		return c - 'a';
	} else {
		return c - 'A' + 7;
	}
}

int main(){
	char c;
	int n;
	int prei = -1, nowi;
	scanf("%d", &n);
	c = getchar();// \n
	while(n--){
		prei = -1;
		memset(fin, 0, sizeof(fin));
		while((c = getchar()) != '\n'){
			nowi = getindex(c);
			if(prei == -1){
				for(int i = 1; i < FINGERNUM + 1; i++){
					if(note[nowi][i])
						fin[i]++;
				}
			} else {
				for(int i = 1; i < FINGERNUM + 1; i++){
					if(note[nowi][i] && !note[prei][i])
						fin[i]++;
				}
			}
			prei = nowi;
		}
	    for(int i = 1; i < FINGERNUM + 1; i++){
			if(i == 1)
				printf("%d", fin[i]);
			else
				printf(" %d", fin[i]);
		}
		puts("");
	}
	return 0;
}
