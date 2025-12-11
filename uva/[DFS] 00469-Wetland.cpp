#include <stdio.h>
#include <stdlib.h>
#include <vector>

//http://online-judge.uva.es/board/viewtopic.php?f=5&t=2426
//blank -> wlwlwl -> number -> blank ... -> eof

int row, col;
std::vector< std::vector<int> > arr;
std::vector<int> ans;

void find_water(int r, int c, int* count, int* nowansi){
	if(r < 0 || c < 0 || r >= row || c >= col || arr[r][c] != 'W'){
		return;
	}
	(*count)++;
	//printf("in func count %d\n", *count);
	arr[r][c] = -(*nowansi);//ok
	find_water(r-1, c-1, count, nowansi);
	find_water(r-1, c, count, nowansi);
	find_water(r-1, c+1, count, nowansi);
	find_water(r, c-1, count, nowansi);
	find_water(r, c+1, count, nowansi);
	find_water(r+1, c-1, count, nowansi);
	find_water(r+1, c, count, nowansi);
	find_water(r+1, c+1, count, nowansi);
}

int main(){
	int T;	int anscount;
	char s[104] = "";
	std::vector<int> temp;
	gets(s);
	sscanf(s, "%d", &T);
	gets(s);//first blank line
	while(T){
		while(gets(s) && (s[0] == 'W' || s[0] == 'L')){
			int nowi = 0;
			temp.clear();
			while(s[nowi] != '\0')
				temp.push_back(s[nowi++]);
			arr.push_back(temp);
		}
		if(s[0] != '\0'){
			row = arr.size();
			col = arr[0].size();
			int r, c, count = 0;
			ans.clear();
			anscount = 1;
			do{
				sscanf(s, "%d %d", &r, &c);
				r--; c--;
				//printf("r = %d c = %d arr[r][c] = %c\n", r, c, arr[r][c]);
				if(r >= row || r < 0 || c < 0 || c >= col){
					puts("0");
				} else if(arr[r][c] < 0){
					printf("%d\n", ans[-arr[r][c]-1]);
				} else {
					count = 0;
					find_water(r, c, &count, &anscount);
					ans.push_back(count);
					//printf("count = %d ans[%d] = %d\n", count, anscount-1, ans[anscount-1]);
					printf("%d\n", ans[anscount-1]);
					anscount++;
				}
			} while(gets(s) && s[0] != '\0');
		}
		if(--T)
			puts("");
		//finish
		arr.clear();
	}
	return 0;
}