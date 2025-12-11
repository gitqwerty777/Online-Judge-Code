#include <stdio.h>
#include <string.h>
#include <queue>
int arr[1000004];
int now[104];
std::queue<int> q;

int main(){
	arr[0] = 0; arr[1] = 1; arr[2] = 2; arr[3] = 3;
	int T, N, M, K;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		scanf("%d %d %d", &N, &M, &K);
		while(!q.empty())
			q.pop();
		int facn = 0, minlen = N+1;
		memset(now, 0, sizeof(now));
		int presum = arr[0] + arr[1] + arr[2];
		for(int i = 1; i <= N; i++){
			if(i >= 4){
				presum -= arr[i-4] - arr[i-1];
				arr[i] = ((presum) % M) + 1;
			}
			q.push(arr[i]);
			if(arr[i] > K){//not in K -> no matter, can't put in now[]
				continue;
			}
			if(now[arr[i]] == 0)
				facn++;
			now[arr[i]]++;
			if(now[arr[i]]){//this number exist in queue, pop the front without taking all of one number
				while(q.front() > K || now[q.front()] > 1){
					if(q.front() <= K)
						now[q.front()]--;
					q.pop();
				}
			}
			if(facn == K && q.size() < minlen){
				minlen = q.size();
			}
		}
		if(minlen == N+1){
			printf("Case %d: sequence nai\n", t+1);
		} else {
			printf("Case %d: %d\n", t+1, minlen);
		}
	}
	return 0;
}