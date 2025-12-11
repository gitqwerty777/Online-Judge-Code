#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ps. 在前方空四格

char unit[][10] = {" lakh", " hajar", " shata", ""};
int unitnum [] = {100000, 1000, 100, 1};
int unitlen [] = {100, 100, 10, 100};//unitnum[i] / unitnum[i+1]

void print_Number(char* a, const char* suffix){
	int n = atoi(a);
	if(n != 0){
		int tok;
		for(int i = 0; i < 4; i++){
			tok = (n / unitnum[i]) % unitlen[i];
			if(tok > 0)
				printf(" %d%s", tok, unit[i]);
		}
	}
	printf("%s", suffix);
}

// 1 + 7 + 7
//One section length is 7 

int main(){
	char s[20], s1[20], s2[20];
	int count = 1;
	long long in;
	memset(s, '\0', 20);	memset(s1, '\0', 20);	memset(s2, '\0', 20);
	while(scanf("%lld", &in) != EOF){
		printf("%4d.", count++);
		if(in == 0){
			puts(" 0");
			continue;
		}
		sprintf(s, "%lld", in);
		int l = strlen(s);
		if(l > 14){
			strncpy(s2, s, 1);
			print_Number(s2, " kuti");//7
			strncpy(s1, s+1, 7);
			print_Number(s1, " kuti");//7
			print_Number(s+7+1, "");//7
		} else if (l > 7){
			strncpy(s1, s, l-7);
			print_Number(s1, " kuti");//7
			print_Number(s+l-7, "");//7
		} else {
			print_Number(s, "");	
		}
		puts("");
		memset(s, '\0', 20);	memset(s1, '\0', 20);	memset(s2, '\0', 20);
	}
	return 0;
}