#include <stdio.h>
#include <string.h>
#include <vector>

inline int min(int a, int b){
	return (a < b)? a: b;
}

struct Guess{
	char s[8];
	int A, B;
};
std::vector<struct Guess> g;

int numb[10];
int guessb[10];
bool TestAB(char test[], char guess[], int a, int b){
	memset(numb, 0, sizeof(numb));
	memset(guessb, 0, sizeof(guessb));
	int A = 0, B = 0;
	for(int i = 0; i < 4; i++)
		if(test[i] == guess[i]){
			A++;
		} else {
			numb[test[i]-'0']++;
			guessb[guess[i]-'0']++;
		}
	for(int i = 0; i < 10; i++)
		if(numb[i] && guessb[i])
			B += min(numb[i], guessb[i]);
	if(a == A && b == B){
		//printf("%s and %s guess%dA%dB => %dA%dB\n", test, guess, a, b, A, B);
		return true;
	} else {
		return false;
	}
}

char testinput[10000][8];
int main(){
	char s[8];
	int A, B;
	int N, T;
	for(int i = 0; i < 10000; i++){
		sprintf(testinput[i], "%04d", i);
	}
	struct Guess tempg;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &T);
		g.clear();
		for(int t = 0; t < T; t++){
			scanf("%s %d/%d", tempg.s, &tempg.A, &tempg.B);
			g.push_back(tempg);
		}
		int testin = 0;
		int possiblenum = 0; bool possible = true;
		char ans[8] = "";
		for(int i = 0; i < 10000; i++){
			possible = true;
			for(int t = 0; t < T; t++)
				if(!TestAB(testinput[i], g[t].s, g[t].A, g[t].B)){//sort A, Bbefore
					possible = false;
					break;
				}
			if(possible){
				possiblenum++;
				if(possiblenum > 1){
					break;
				} else {
					strcpy(ans, testinput[i]);
				}
			}
		}
		if(possiblenum > 1){
			puts("indeterminate");
		} else if(possiblenum){
			puts(ans);
		} else {
			puts("impossible");
		}
	}
	return 0;
}