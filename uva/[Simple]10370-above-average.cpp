#include <stdio.h>

void Input(int* i){
	char c;  
    int x = 0, flag = 1;
    while(c=getchar())  
        if(c != ' ' && c != '\n')
			break;
    if(c !='-')
        x = x*10 + c -'0';
    else
		flag=-1;
    while(c = getchar()){  
        if(c == ' '|| c == '\n')
			break;
		x = x*10 + c - '0';  
    }
    (*i) = x*flag;
}

int g[1004];

int main(){
	int T, N;
	long long s;
	scanf("%d", &T);
	while(T--){
		Input(&N);
		s = 0;
		for(int i = 0; i < N; i++){
			Input(&g[i]);
			s += g[i];
		}
		int av = s / N;
		int count = 0;
		for(int i = 0; i < N; i++){
			if(g[i] > av)
				count++;
		}
		printf("%.03lf\%\n", (double(count) / N) * 100);
	}
	return 0;
}