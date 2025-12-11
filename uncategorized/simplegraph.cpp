#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int isort(int a, int b){
	return a > b;
}

vector<int> deg;
int main(){
	int n;
	
	bool over; string dumb;
	while(scanf("%d", &n) && n != 0){
		int i, in;
		deg.resize(n);
		long long count = 0; over = false;
		
		//getline(cin, dumb);
		//cout<<n<<"vertex "<<dumb<<endl;
		//continue;
		for(i = 0; i < n; i++){
			scanf("%d", &deg[i]);
			if(deg[i] >= n || deg[i] < 0){
				over = true;
				getline(cin, dumb);
				//cout<<n<<"vertex "<<in<<" "<<dumb<<endl;
				break;
			}
			count += deg[i] % 2;
		}
		if(over || count % 2){
			puts("Not possible");
			continue;
		}
		
		sort(deg.begin(), deg.end(), isort);
		deg.insert(deg.begin(), 0);//deg[0] = 0(dumb)
		
		long long lsum = 0;
		vector<long long> rsum(n+2);
		rsum[1] = 0;
		
		int index = 1;		i = n;
		
		while(index <= n){
			lsum += deg[index];
			
			while(i > index && deg[i] <= index)
				rsum[index] += deg[i--];
			while(i < index)//????
				rsum[index] -= deg[++i];
			
			rsum[index+1] = rsum[index] + index*2;//k*(k-1) 
			rsum[index] += index * (i - index);
			//cout<<"rsum:["<<index<<"] = "<<rsum[index]<<endl;
			
			if(lsum > rsum[index]){
				over = true;	break;}
			index++;
		}

		if(over)
			puts("Not possible");
		else
			puts("Possible");
	}

	return 0;
}
