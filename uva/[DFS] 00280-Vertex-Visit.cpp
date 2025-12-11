#include <stdio.h>
#include <string.h>
#include <vector>

int N;
bool adj[104][104];
std::vector<int> v;

void Warshell(){
	for(int k = 0; k < N ;k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N ;j++)
				if(adj[i][k] && adj[k][j])
					adj[i][j] = true;
}

int main(){
	int in, start, connect;
	
	while(scanf("%d", &N) && N){
		memset(adj, false, sizeof(adj));
		while(scanf("%d", &start) && start)
			while(scanf("%d", &connect) && connect)
				adj[start-1][connect-1] = true;
		//warshell
		Warshell();
		//start dealing request
		int Q, reqnum;
		scanf("%d", &Q);
		for(int i = 0; i < Q; i++){
			scanf("%d", &reqnum);
			v.clear();
			for(int j = 0; j < N ;j++)
				if(!adj[reqnum-1][j])
					v.push_back(j+1);
			printf("%d", v.size());
			for(int j = 0; j < v.size(); j++)
				printf(" %d", v[j]);
			puts("");
		}
	}	
		return 0;
}
