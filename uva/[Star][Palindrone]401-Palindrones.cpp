#include <stdio.h>
#include <string.h>

char s[200000];
char mir[256] = "";

void init(){
  mir['A'] = 'A';
  mir['E'] = '3';
  mir['H'] = 'H';
  mir['I'] = 'I';
  mir['J'] = 'L';
  mir['L'] = 'J';
  mir['M'] = 'M';
  mir['O'] = 'O';
  mir['S'] = '2';
  mir['T'] = 'T';
  mir['U'] = 'U';
  mir['V'] = 'V';
  mir['W'] = 'W';
  mir['X'] = 'X';
  mir['Y'] = 'Y';
  mir['Z'] = '5';
  //mir['0'] = '0';
  mir['1'] = '1';
  mir['2'] = 'S';
  mir['3'] = 'E';
  mir['5'] = 'Z';
  mir['8'] = '8';
}

char anschar[][100] = {"-- is not a palindrome.",
		       "-- is a regular palindrome.",
		       "-- is a mirrored string.",
		       "-- is a mirrored palindrome."};

int main(){
  init();
  while(gets(s)){
    bool ismir = true;
    bool ispal = true;
    int len = strlen(s);
    for(int i = 0; i < (len+1)/2 && ispal; i++)
      if(s[i] != s[len-1-i])
	ispal = false;

    for(int i = 0; i < (len+1)/2 && ismir; i++){
      //printf("%c->%c %c->%c\n", s[i], mir[s[i]], );
      if(mir[s[i]] != s[len-1-i] && mir[s[len-1-i]] != s[i]){
	//printf("erro:%c != %c\n", s[i], s[len-i-1]);
	ismir = false;
      }
    }
        
    int ansi;
    if(!ispal && !ismir)
      ansi = 0;
    else if(!ispal && ismir)
      ansi = 2;
    else if(ispal && !ismir)
      ansi = 1;
    else
      ansi = 3;
    printf("%s %s\n\n", s, anschar[ansi]);
  }
}

