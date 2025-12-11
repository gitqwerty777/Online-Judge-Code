#include <stdio.h>
#define ROW 36
#define COL 84
char s[ROW][COL];
int nowr = 0, nowc;

void fill_maze(int r, int c){
	s[r][c] = '#';
	if(r-1 > 0 && s[r-1][c] == ' ') fill_maze(r-1, c);
	if(r+1 < nowr && s[r+1][c] == ' ') fill_maze(r+1, c);
	if(c-1 > 0 && s[r][c-1] == ' ') fill_maze(r, c-1);
	if(s[r][c+1] == ' ') fill_maze(r, c+1);
}

int main(){
	int starr, starc;
	bool isStar;
	int T;
	scanf("%d", &T);
	gets(s[0]);
	while(T && gets(s[nowr])){
		if(s[nowr][0] == '_'){
			fill_maze(starr, starc);
			for(int i = 0; i < nowr; i++)
				puts(s[i]);
			puts("_____");
			nowr = 0;
			isStar = false;
			T--;
			continue;
		}
		nowc = 0;
		while(!isStar && s[nowr][nowc]){
			if(s[nowr][nowc] == '*'){
				starr = nowr;
				starc = nowc;
				isStar = true;
			}
			nowc++;
		}
		nowr++;
	}
	return 0;
}
