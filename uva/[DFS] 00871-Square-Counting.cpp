#include <stdio.h>
#include <string.h>

char s[28][28];
int row, col;

void find_max_fill(int r, int c, int *count){
	if(r < 0 || c < 0 || r >= row || c >= col || s[r][c] != '1')
		return;
	else{
		s[r][c] = '0';
		(*count)++;
		find_max_fill(r-1, c-1, count);
		find_max_fill(r-1, c, count);
		find_max_fill(r-1, c+1, count);
		find_max_fill(r, c-1, count);
		find_max_fill(r, c+1, count);
		find_max_fill(r+1, c-1, count);
		find_max_fill(r+1, c, count);
		find_max_fill(r+1, c+1, count);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	gets(s[0]);
	gets(s[0]);
	bool first = true;
	while(gets(s[0]) && s[0][0] != '\0'){
		if(first)
			first = false;
		else
			puts("");
		col = strlen(s[0]);
		row = 1;
		while(gets(s[row]) && s[row][0] != '\0'){
			row++;
		}
		int count = 0, max = 0;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				if(s[i][j] == '1'){
					count = 0;
					find_max_fill(i, j, &count);
					if(max < count)
						max = count;
				}
		printf("%d\n", max);
	}
	return 0;
}