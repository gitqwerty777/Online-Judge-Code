#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
void gcd_Euclid(int a, int b, int* ans){
	int aa, bb;
	aa = a; bb = b;
	vector<int> yu;
	bool isyu = true;
	
	while(a && b){
		if(a > b){
			yu.push_back(a/b);
			a %= b;
		}
		else{
			yu.push_back(b/a);
			b %= a;
		}
	}
	if(b)
		ans[0] = b;
	else
		ans[0] = a;
		
	if(ans[0] != 1)
		return;
	
	yu.pop_back();//最後不需
	int lo = yu.size(); int count = 0;
	int euc[2] = {0};
	euc[0] = 1; euc[1] = -yu[lo-1];
	
	for(int i = lo-2; i >= 0; i--){
		euc[count%2] += euc[(count+1)%2] * (-yu[i]);
		count++;
	}
	
	if(aa * euc[0] + bb * euc[1] != 1){
		ans[1] = euc[1];
		ans[2] = euc[0];
	}else{
		ans[2] = euc[1];
		ans[1] = euc[0];
	}
	
	while(ans[1] < 0)
		ans[1] += bb;
	
	return;
}
int main(){
	int a, n;
	int ans[3] = {0};
	
	while(cin>>a>>n){
		gcd_Euclid(a, n, ans);
		if(ans[0] != 1)
			puts("No Inverse");
		else
			cout<<ans[1]<<endl;//?
	}

	return 0;
}