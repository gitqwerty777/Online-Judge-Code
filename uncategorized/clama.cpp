#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
	int a[2], b[2], c[2];
	cin>>a[0]>>b[0]>>c[0]>>a[1]>>b[1]>>c[1];
	
	int d[3];
	d[0] = a[0]*b[1] - a[1]*b[0];
	d[1] = c[0]*b[1] - c[1]*b[0];
	d[2] = a[0]*c[1] - a[1]*c[0];
	
	if(d[0] == 0){
		if(d[1] == 0 && d[2] == 0)
			puts("Too many");
		else
			puts("No answer");}
	else{
		double x,y;
		x = double(d[1]) / d[0];
		y = double(d[2]) / d[0];
		cout<<"x="<<fixed<<setprecision(2)<<x<<endl;
		cout<<"y="<<fixed<<setprecision(2)<<y<<endl;
	}
	
	return 0;
}