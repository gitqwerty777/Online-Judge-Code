#include <stdio.h>

struct line{
	double x, y;
};

inline double max(double a, double b){
	return (a>b)?a:b;
}

int main(){
	struct line l1[100], l2[100];
	int an, bn;
	double x, y;
	while(scanf("%d", &an) == 1){
		for(int i = 0; i < an; i++){
			scanf("%lf %lf", &l1[i].x, &l1[i].y);
		}
		scanf("%d", &bn);
		for(int i = 0; i < bn; i++){
			scanf("%lf %lf", &l2[i].x, &l2[i].y);
		}
		double minh = max(l1[0].x, l2[0].x);
		int i1 = 0, i2 = 0;
		while(i1 < an && i2 < bn){
			if(l1[i1].y < l2[i2].y){
				l2[i2].y -= l1[i1].y;
				if(max(l1[i1].x, l2[i2].x) < minh){
					minh = max(l1[i1].x, l2[i2].x);
				}
				i1++;
			}else if(l1[i1].y > l2[i2].y){
				l1[i1].y -= l2[i2].y;
				if(max(l1[i1].x, l2[i2].x) < minh){
					minh = max(l1[i1].x, l2[i2].x);
				}
				i2++;
			} else {
				if(max(l1[i1].x, l2[i2].x) < minh){
					minh = max(l1[i1].x, l2[i2].x);
				}
				i1++; i2++;
			}
		}
		printf("%.03lf\n", minh);
	}
	return 0;
}
