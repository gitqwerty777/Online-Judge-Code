#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void make_vector_4(string a, int loa, vector<int> &av){
	string temp; int count = loa, i = 0;
	do{
		count -= 4;
		if(count > 0)
			temp.assign(a, count, 4);
		else
			temp.assign(a, 0, count + 4);
			
		av.push_back(atof(temp.c_str()));
		i++;
	}while(count > 0);//check 8 進
}

void print_ans(vector<int> &ans){
	int way, tempa, real;
	int lo = ans.size();
	
	real = lo-1;
	while(ans[real] == 0)
		real--;
	cout<<ans[real];
	for(int i = real-1; i >= 1; i--){
		way = 4; tempa = ans[i];
		if(ans[i] == 0)
			cout<<"000";
		else{
			while(tempa != 0){
				tempa /= 10;
				way--;}
			while(way-- != 0)
				cout<<"0";
		}
		cout<<ans[i];
	}
	cout<<endl;
}

void power(vector<int> &av, vector<int> bv){
	int loa = av.size(), lob = bv.size();	
	int i, j;
	
	vector<int> ans;
	ans.assign(loa + lob, 0);
	
	for(i = 1; i < loa; i++)
		for(j = 1; j < lob; j++){
			ans[i + j] += (av[i] * bv[j]);
		
			if(ans[i + j] >= 10000){
				ans[i + j + 1] += ans[i + j] / 10000;
				ans[i + j] %= 10000;
			}
		}
	
	int lo = ans.size();
	for(i = 0; i < lo; i++)
		if(ans[i] >= 10000){
			ans[i+1] += ans[i] / 10000;
			ans[i] %= 10000;
		}
	
	for(i = lo-1; i >= 0; i--){//ok??
		if(ans[i] == 0)
			ans.erase(ans.begin()+i);
		else
			break;
	}
	lo = ans.size();
	
	while(ans[0] == 0 && ans[1] == 0)
		ans.erase(ans.begin());
			
	av = ans;
}

int main(){
	int n;
	string a;
	
	cin>>a>>n;
	
	vector<int> av;
	av.push_back(0);
	make_vector_4(a, a.size(), av);
	
	int base = 1;
	vector<int> lastbase;
	vector<vector<int> >lastav;//記錄用
	
	lastbase.push_back(1);
	lastav.push_back(av);
	
	int lobase;
	while(base < n){
		if(base * 2 <= n){
			base *= 2;
			power(av, av);
			lastbase.push_back(base);
			lastav.push_back(av);
		}
		else{
			lobase = lastav.size();
			for(int i = lobase - 1; i >= 0; i--)
				if(lastbase[i] + base <= n){
					power(av, lastav[i]);
					base += lastbase[i];
					lastbase.push_back(base);
					lastav.push_back(av);
					break;
				}
		}
	}
		
	print_ans(av);
	
	return 0;
}