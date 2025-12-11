#include <stdio.h>
#include <string.h>

char g[54][54];
int T, N;
char s[54];
int h[54];
int height;
int length;

/*
  
graph example:    
|             _
|  _/\_/\    /
| /      \__/
+---------------

no trailing space
*/

void make_graph(){
  memset(g, ' ', sizeof(g));
  for(int i = 0; i < height; i++){
    g[i][0] = '|';
    g[i][length] = '\0';
  }
  for(int i = 0; i < length; i++)
    g[height-1][i] = '-';
  g[height-1][0] = '+';
}

void fill_in(){
  for(int i = N-1; i >= 0; i--)
    g[height-2-h[i]][i+2] = s[i];

  for(int j = 0; j < height; j++){
    int l = length-1;
    while(g[j][l] == ' '){
      l--;
    }
    g[j][l+1] = '\0';
  }
      

}
void print(){
  for(int i = 0; i < length; i++){//first line
    if(g[0][i] == '_'){
      puts(g[0]);
      break;
    }
  }
  for(int i = 1; i < height; i++)
    puts(g[i]);
  puts("");
}

int main(){
  scanf("%d", &T);
  gets(s);
  for(int t = 1; t <= T; t++){
    gets(s);
    int maxn = 0;
    int minn = 0;
    int nown = 0;
    N = strlen(s);
    for(int i = 0; i < N; i++){
      
      if(s[i] == 'R'){
	nown++;
	s[i] = '/';
	if(nown > maxn)
	  maxn = nown;
	      h[i] = nown-1;
      } else if(s[i] == 'F'){
	nown--;
	s[i] = '\\';
	if(minn > nown)
	  minn = nown;
	      h[i] = nown;
      } else {
	      h[i] = nown;
	s[i] = '_';
      }

    }
    for(int i = 0; i < N; i++)
      h[i] -= minn;
    height = maxn-minn+2;
    length = N + 3;
    make_graph();
    fill_in();
    printf("Case #%d:\n", t);
    print();
    
  }
  return 0;
}