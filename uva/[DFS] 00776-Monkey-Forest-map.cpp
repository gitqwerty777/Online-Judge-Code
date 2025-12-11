#include <stdio.h>
#include <stdlib.h>
#include <vector>

std::vector<int> v;
std::vector<std::vector<int> > ans;
int col, row, count;

void fill_count(int r, int c, int* fill_num, int* value){
	if(r < 0 || r >= row || c < 0 || c >= col)
		return;
	if(ans[r][c] == 0 && v[r*col+c] == (*value)){
		ans[r][c] = (*fill_num);
		fill_count(r-1, c-1, fill_num, value);
		fill_count(r-1, c, fill_num, value);
		fill_count(r-1, c+1, fill_num, value);
		fill_count(r, c-1, fill_num, value);
		fill_count(r, c+1, fill_num, value);
		fill_count(r+1, c-1, fill_num, value);
		fill_count(r+1, c, fill_num, value); 
		fill_count(r+1, c+1, fill_num, value);
	}
}
int get_width(int n){
	int count = 1;
	while(n >= 10){
		n /= 10;
		count++;
	}
	return count;
}

int main(){
	int c;
	v.clear();	ans.clear();
	col = 0;	row = 0;	count = 0;
	while(scanf("%c", &c) != EOF){
		if(c == '%'){//finish
			col = v.size() / row;
			//printf("col = %d row = %d count = %d\n", col, row, count);
			ans.resize(row);
			for(int i = 0; i < row; i++)
				ans[i].resize(col);
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++)
					ans[i][j] = 0;
			//printf("calculate\n");
			//calculate
			count = 1;
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++)
					if(ans[i][j] == 0){
						//printf("v(%d, %d) = %c\n", i, j, v[i*col+j]);
						fill_count(i, j, &count, &v[i*col+j]);
						count++;
					}
			//printf("print\n");
			//print
			int* max_width = (int*)malloc(sizeof(int)*col);
			int maxnumincol;
			for(int j = 0; j < col; j++){
				maxnumincol = 0;
				for(int i = 0; i < row; i++){
					if(ans[i][j] > maxnumincol){
						maxnumincol = ans[i][j];
					}
				}
				max_width[j] = get_width(maxnumincol) + 1;
			}
			max_width[0]--;//no need ' '
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					printf("%*d", max_width[j], ans[i][j]);
				}
				puts("");
			}
			puts("%");
			free(max_width);
			//printf("clear\n");
			//clear
			v.clear();
			col = 0;row = 0;count = 0;
			//scanf '\n' after '%'
			if(scanf("%c", &c) == EOF){
				return 0;
			}
		} else {
			if(c == ' ')
				continue;
			if(c == '\n'){
				row++;
				continue;
			}
			v.push_back(c);
			//printf("\'%c\'", c);
		}
	}
	if(v.size()){
		col = v.size() / row;
	}
	//printf("col = %d row = %d count = %d\n", col, row, count);
	ans.resize(row);
	for(int i = 0; i < row; i++){
		ans[i].resize(col);
	}
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++){
			ans[i][j] = 0;
		}
	//calculate
	count = 1;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(ans[i][j] == 0){
				fill_count(i, j, &count, &v[i*col+j]);
				count++;
			}
	//print
	int* max_width = (int*)malloc(sizeof(int)*col);
	int maxnumincol;
	for(int j = 0; j < col; j++){
		maxnumincol = 0;
		for(int i = 0; i < row; i++){
			if(ans[i][j] > maxnumincol){
				maxnumincol = ans[i][j];
			}
		}
		max_width[j] = get_width(maxnumincol) + 1;
	}
	max_width[0]--;//no need ' '
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%*d", max_width[j], ans[i][j]);
		}
		puts("");
	}
	puts("%");
	free(max_width);
	return 0;
}