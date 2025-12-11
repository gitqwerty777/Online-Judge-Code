#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

int main(){
	long long x,y,z,w, n, m;
	string in;
	char dumb;
	stringstream ss;
	long long eat[5] = {0};
	long long type, poiv;
	bool poison, die;
	
	getline(cin, in);
	ss.str(""); ss.clear();ss<<in;
	ss>>x;
	for(int i = 0; i < x; i++){
		ss.str("");ss.clear();
		getline(cin, in);
		
		ss<<in;
		ss>>eat[1]>>eat[2]>>eat[3]>>eat[4]>>n>>m;
		eat[3] = -eat[3];
		eat[4] = -eat[4];
		
		poiv = 0;
		poison = false;
		die = false;
		
		ss.str("");
		ss.clear();
		getline(cin, in);
		ss<<in;

		while(ss>>type){
			
			if(poison)
				m -= poiv;
			if(m <= 0){
				puts("bye~Rabbit");
				die = true;
				break;
			}
			
			m += eat[type];
				
			if(type == 4){
				poison = true;
				poiv += n;
			}
		}
		if(m > 0)
			cout<<m<<"g"<<endl;
		else if(!die)
			puts("bye~Rabbit");
	}
	
	return 0;
}