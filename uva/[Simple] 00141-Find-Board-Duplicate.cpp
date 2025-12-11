#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#define MAXN 50

int N;
struct Block{
	bool b[MAXN][MAXN];
	int nowchess;
};
struct cmp{
	bool operator() (const struct Block& l, const struct Block& r) const  
	{
		if(l.nowchess != r.nowchess){
			return l.nowchess > r.nowchess;
		} else{
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++){
					if(l.b[i][j] == r.b[i][j]){
						continue;
					} else {
						return l.b[i][j];
					}
				}
			return false;
		}
	}
};
typedef struct Block block;

std::set<block, cmp> S;
/*
	nowb[r][c]--;
	nowb[c][N-1-r]--;
	nowb[N-1-c][r]--;
	nowb[N-1-r][N-1-c]--;
*/

int main(){
	int r, c;	char flag[4]; int win; int nowchess;
	bool board[MAXN][MAXN];
	block empty;
	empty.nowchess = 0;
	memset(empty.b, false, sizeof(empty.b));
		
	while(scanf("%d", &N) == 1 && N){
		win = 0;
		nowchess = 0;
		S.clear();
		S.insert(empty);
		
		memset(board, false, sizeof(board));
		for(int n = 0; n < 2*N; n++){
			scanf("%d %d %s", &r, &c, flag);
			if(win)
				continue;
			r--; c--;
			if(strcmp(flag, "+") == 0){
				board[r][c] = true;
				nowchess++;
			} else {
				board[r][c] = false;
				nowchess--;
			}
			//check ori
			block temp;
			temp.nowchess = nowchess;
			memcpy(temp.b, board, sizeof(board));
			if(S.find(temp) != S.end()){
				win = n;
				continue;
			}
			//check turn 1
			block temp1;
			temp1.nowchess = nowchess;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N ;j++)
					temp1.b[j][N-1-i] = board[i][j];
			if(S.find(temp1) != S.end()){
				win = n;
				continue;
			}	
			//check turn 2
			block temp2;
			temp2.nowchess = nowchess;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N ;j++)
					temp2.b[N-1-j][i] = board[i][j];
			if(S.find(temp2) != S.end()){
				win = n;
				continue;
			}	
			//check turn 3
			block temp3;
			temp3.nowchess = nowchess;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N ;j++)
					temp3.b[N-1-i][N-1-j] = board[i][j];
			if(S.find(temp3) != S.end()){
				win = n;
				continue;
			}
			S.insert(temp);S.insert(temp1);S.insert(temp2);S.insert(temp3);
		}
		if(!win)
			puts("Draw");
		else
			printf("Player %d wins on move %d\n", ((win+1)%2)+1, win+1);
	}
	return 0;
}