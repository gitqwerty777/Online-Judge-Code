#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node{//rectangle
	double x1, x2, y1, y2;
};
struct Node n[100];
double x[200], y[200];

int main(){
	int count = 1;
	int N;
	double X, Y, R;
	while(scanf("%d", &N) == 1 && N != 0){
		//if(count != 1)
		//	puts("");
		for(int i = 0; i < N; i++){
			scanf("%lf %lf %lf", &X, &Y, &R);
			n[i].x1 = X - R;
			n[i].x2 = X + R;
			n[i].y1 = Y - R;
			n[i].y2 = Y + R;
			x[2*i] = n[i].x1;
			x[2*i+1] = n[i].x2;
			y[2*i] = n[i].y1;
			y[2*i+1] = n[i].y2;
		}
		sort(x, x + 2*N);
		sort(y, y + 2*N);
		double ans = 0;
		for(int i = 0; i < 2*N - 1; i ++)
			for(int j = 0; j < 2*N-1; j++)//select a rectangle(seperate by edge provided)
				for(int k = 0; k < N; k ++)
					if(n[k].x1 <= x[i] && n[k].x2 >= x[i+1] && n[k].y1 <= y[j] && n[k].y2 >= y[j+1]){//if this rectangle is in one of the rectangle, add it to answer
						ans += (x[i+1]-x[i])*(y[j+1]-y[j]);
						break;
					}
		printf("%d %.2lf\n", count++, ans);
	}
	return 0;
}
