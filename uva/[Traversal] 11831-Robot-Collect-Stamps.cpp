#include <stdio.h>

char s[104][104];
char in[50004];
int R, C, N;
int ans;
int dir, ini_r, ini_c;

//N, E, S, W
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void calculate_stamp(){
  ans = 0;
  //printf("in = ");
  //puts(in);
  for(int i = 0; i < N; i++){
    switch(in[i]){
    case 'D':
      dir = (dir+1)%4;
      break;
    case 'E':
      dir = (dir+3)%4;
      break;
    case 'F':
      int newr = ini_r + dr[dir];
      int newc = ini_c + dc[dir];
      if(newr < 0 || newc < 0 || newr >= R || newc >= C || s[newr][newc] == '#')//no move, do nothing
	continue;
      else{
	if(s[newr][newc] == '*'){
	  ans++; s[newr][newc] = '.';
	}
	ini_r = newr;
	ini_c = newc;
      }
      break;
    }
  }
  
}

int main(){
  while(scanf("%d %d %d", &R, &C, &N) == 3 && R && C && N){
    gets(s[0]);
    for(int r = 0; r < R; r++){
      gets(s[r]);
      for(int c = 0; c < C; c++){
	if(s[r][c] != '.' && s[r][c] != '*' && s[r][c] != '#'){
	  switch(s[r][c]){
	  case 'N':
	    dir = 0;
	    break;
	  case 'L'://WTF is this ...
	    dir = 1;
	    break;
	  case 'S':
	    dir = 2;
	    break;
	  case 'O':
	    dir = 3;
	    break;
	  }
	  ini_r = r;
	  ini_c = c;
	}
      }
    }
    gets(in);
    calculate_stamp();
    printf("%d\n", ans);
  }
  return 0;
}
