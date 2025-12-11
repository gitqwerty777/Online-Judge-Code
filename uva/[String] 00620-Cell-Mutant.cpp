#include <stdio.h>
#include <string.h>
char s[5000];
char ans[][12] = {"SIMPLE","FULLY-GROWN","MUTAGENIC","MUTANT"};

int main(){	
	int t,T;
	scanf("%d", &T);
	gets(s);
	
	int start, end, l, type;
	bool mut;
	for(int t = 0; t < T; t++){
		gets(s);
		l = strlen(s);
		start = 0;
		end = l-1;
		type = 0;
		mut = false;
		while(start <= end && !mut){
			if(start == end){
				if(s[start] != 'A')
					mut = true;
				break;
			} else if(s[end-1] == 'A' && s[end] == 'B'){
				end -= 2;
				if(!type)
					type = 1;
			} else if(s[start] == 'B' && s[end] == 'A' && start + 1 != end){
				start++; end--;
				if(!type)
					type = 2;
			} else {
				mut = true;
			}
		}
		if(mut)
			puts(ans[3]);
		else
			puts(ans[type]);
	}
	return 0;
}