#include <cstdio>
#include <list>

using namespace std;

int main(){
	list<int> l;
	l.clear();
	int N;
	int temp;
	int count = 0;
	list<int>::iterator mid, midpp, i;
	while(true){
		if(count != 0)
			puts("");
		if(scanf("%d", &temp) != 1){
			break;
		}
		int lcount = 0;
		for(i = l.begin(); i != l.end(); i++){
			if(*i > temp)
				break;
			lcount++;
		}
		if(i == l.end()){
			l.push_back(temp);
		} else {
			l.insert(i, temp);
		}
		if(lcount < (count+1)/2){
			mid--;
		}
		/*if(count != 0)
			printf("now mid = %d", *mid);
		printf("now list:");
		for(list<int>::iterator it = l.begin(); it != l.end(); it++){
			printf("%d ", *it);
		}
		printf("\n");*/
		if(count % 2 == 0){
			if(count == 0)
				mid = l.begin();
			else
				mid++;
			printf("%d", *mid);
		} else {
			midpp = mid;
			midpp++;
			printf("%d", (*mid + *(midpp))/2);
	        }
		count++;
	}
	return 0;
}
