#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <vector>

/*2darray -> '&' to keep pointer     */

int num[26];
struct Node{
	int r, c;
};
typedef struct Node node;
struct cmp{
	bool operator()(node a, node b){
		if(a.c == b.c){
			return a.r < b.r;
		} else 
			return a.c > b.c;
	}
} Cmp; 
std::queue<node> q;
std::vector<node> ans;

void get2D(int R, int C, char**& arr){
	arr = (char **)malloc(R*sizeof(char*));
	for(int i = 0; i < R; i++){
		arr[i] = (char*)malloc(C*sizeof(char));
		//memset(arr[i], '\0', sizeof(arr[i]));//???
	}
}

int main(){
	int T, R, C;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		while(!q.empty()){
			q.pop();
		}
		scanf("%d %d", &R, &C);
		char **arr;
		get2D(R, C, arr);
		//printf("get2d ok\n");
		for(int i = 0; i < R; i++)
			scanf("%s", arr[i]);
		//printf("scanf ok\n");
		/*for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++)
				printf("%c", arr[i][j]-'a');
			printf("\n");
		}*/
		memset(num, 0, sizeof(num));
		int count = 0;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++){
				if(arr[i][j] == '\0'){
					continue;
				} else {
					char c = arr[i][j];
					num[c-'a']++;
					node n;	n.r = i; n.c = j;
					q.push(n);
					while(!q.empty()){
						node tempn;
						if(q.front().r+1 < R && arr[q.front().r+1][q.front().c] == c){
							tempn.r = q.front().r+1;
							tempn.c = q.front().c;
							arr[tempn.r][tempn.c] = '\0';
							q.push(tempn);
						}
						if(q.front().c+1 < C && arr[q.front().r][q.front().c+1] == c){
							tempn.r = q.front().r;
							tempn.c = q.front().c+1;
							arr[tempn.r][tempn.c] = '\0';
							q.push(tempn);
						}
						if(q.front().r-1 >= 0 && arr[q.front().r-1][q.front().c] == c){
							tempn.r = q.front().r-1;
							tempn.c = q.front().c;
							arr[tempn.r][tempn.c] = '\0';
							q.push(tempn);
						}
						if(q.front().c-1 >= 0 && arr[q.front().r][q.front().c-1] == c){
							tempn.r = q.front().r;
							tempn.c = q.front().c-1;
							arr[tempn.r][tempn.c] = '\0';
							q.push(tempn);
						}
						q.pop();
					}
				}
			}
		//print
		ans.clear();
		printf("World #%d\n", t+1);
		for(int i = 0;i < 26; i++){
			if(num[i]){
				node tempn;
				tempn.r = i; tempn.c = num[i];
				ans.push_back(tempn);
			}
		}
		std::sort(ans.begin(), ans.end(), Cmp);
		for(int i = 0;i < ans.size(); i++){
			printf("%c: %d\n", ans[i].r+'a', ans[i].c);
		}
		for(int i = 0; i < R; i++){
			free(arr[i]);
		}
		free(arr);
	}
	return 0;
}