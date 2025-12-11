#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//too many functions so it's slow
char s[84][84];	int T;

void fill_array(int r, int c, char ori, char rep){
	if(r >= T || r < 0 || c < 0 || c >= T || s[r][c] != ori){
		return;
	} else {
		//printf("s[%d][%d] = %c, now = %c\n", r, c, ori, rep);
		s[r][c] = rep;
		fill_array(r-1, c, ori, rep);
		fill_array(r, c-1, ori, rep);
		fill_array(r, c+1, ori, rep);
		fill_array(r+1, c, ori, rep);
	}
}

int Check_Win(int n){
	bool Wwin = false, Bwin = false;
	for(int i = 0; i < n ;i++)
		if(s[i][0] == 'W')
			fill_array(i, 0, 'W', 'X');
	for(int i = 0; i < n ;i++){
		if(s[i][n-1] == 'X')
			Wwin = true;//white win
		if(s[i][n-1] == 'W')
			fill_array(i, n-1, 'W', 'Y');
	}
	for(int i = 0; i < n ;i++)
		if(s[0][i] == 'B')
			fill_array(0, i, 'B', 'C');
	for(int i = 0; i < n ;i++){
		if(s[n-1][i] == 'C')
			Bwin = true;//white win
		if(s[n-1][i] == 'B')
			fill_array(n-1, i, 'B', 'D');
	}
	if(Wwin)
		return 1;
	else if(Bwin)
		return -1;
	else
		return 0;
}

int find_connect(int r, int c){
	bool w[2] = {false, false}, b[2] = {false, false};
	if(r == 0)
		b[0] = true;
	if(r == T-1)
		b[1] = true;
	if(c == 0)
		w[0] = true;
	if(c == T-1)
		w[1] = true;
	if(r-1 >= 0){
		switch(s[r-1][c]){
			case 'X': w[0] = true; break;
			case 'Y': w[1] = true; break;
			case 'C': b[0] = true; break;
			case 'D': b[1] = true; break;
		}
	}
	if(r+1 < T){
		switch(s[r+1][c]){
			case 'X': w[0] = true; break;
			case 'Y': w[1] = true; break;
			case 'C': b[0] = true; break;
			case 'D': b[1] = true; break;
		}
	}
	if(c-1 >= 0){
		switch(s[r][c-1]){
			case 'X': w[0] = true; break;
			case 'Y': w[1] = true; break;
			case 'C': b[0] = true; break;
			case 'D': b[1] = true; break;
		}
	}
	if(c+1 < T){
		switch(s[r][c+1]){
			case 'X': w[0] = true; break;
			case 'Y': w[1] = true; break;
			case 'C': b[0] = true; break;
			case 'D': b[1] = true; break;
		}
	}
	if(w[0] && w[1]){
		return 1;
	} else if(b[0] && b[1]){
		return -1;
	} else {
		return 0;
	}
}

int Check_OneMove_Win(int n){
	int con;
	bool Bwin = false, Wwin = false;
	for(int i = 0; i < n ;i++)
		for(int j = 0; j < n; j++)
			if(s[i][j] == 'U')
				if((con = find_connect(i, j)) != 0){
					if(con == 1){
						Wwin = true;
						break;
					} else {
						Bwin = true;
					}
				}
	if(Wwin)
		return 1;
	else if(Bwin)
		return -1;
	else 
		return 0;
}

int main(){
	while(true){
		scanf("%d", &T);
		if(T == 0){
			break;
		}
		gets(s[0]);
		gets(s[0]);
		for(int t = 0; t < T; t++){
			gets(s[t]);
		}
		int win;
		if((win = Check_Win(T)) != 0){
			if(win == 1){//¥Õ¥ý
				puts("White has a winning path.");
			} else {
				puts("Black has a winning path.");
			}
		} else if((win = Check_OneMove_Win(T)) != 0){
			if(win == 1)
				puts("White can win in one move.");
			else
				puts("Black can win in one move.");
		} else {
			puts("There is no winning path.");
		}
	}
	return 0;
}