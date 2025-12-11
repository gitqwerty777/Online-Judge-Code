#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>

struct Seat{
	char name[4];
	int index;
};
std::vector<struct Seat> s;

int BinarySearch(int v){
	//printf("find index = %d\n", v);
	int end = s.size()-1;
	int start = 0;
	int mid = (start + end)/2;
	while(start != mid && mid != end){
		//printf("start %d mid %d end %d\n", start, mid, end);
		if(s[mid].index < v){
			start = mid;
		} else if(s[mid].index > v) {
			end = mid;
		} else {
			return mid;
		}
		mid = (start + end)/2;
	}
	if(mid+1 < s.size() && std::abs(s[mid].index-v) > std::abs(v-s[mid+1].index))
		mid++;
	else if(mid-1 >= 0 && std::abs(s[mid].index-v) > std::abs(v-s[mid-1].index))//after accepted modified
		mid--;
	if(mid-1 >= 0 && std::abs(s[mid].index-v) == std::abs(v-s[mid-1].index))
		mid--;
	//printf("[%d] = %s\n", mid, s[mid].name);
	return mid;
}

int main(){
	int count = 0; char in[4]; s.clear();
	int N; scanf("%d", &N);
	struct Seat temps;
	while(count < N){
		scanf("%s", in);
		if(strcmp(in, "?") != 0){
			temps.index = count;
			strcpy(temps.name, in);
			s.push_back(temps);
			//printf("count %d = %s\n", count, temps.name);
		}
		count++;
	}
	int req, qnum;
	scanf("%d", &req);
	//printf("req = %d\n", req);
	for(int i = 0; i < req; i++){
		scanf("%d", &qnum);
		qnum--;
		int veci = BinarySearch(qnum);
		if(s[veci].index == qnum){
			puts(s[veci].name);
		} else if(veci+1 < s.size() && qnum-s[veci].index == s[veci+1].index-qnum){
			printf("middle of %s and %s\n", s[veci].name, s[veci+1].name);
		} else if(s[veci].index > qnum){//靠近右
			while(qnum < s[veci].index){
				fputs("left of ", stdout);//不換行
				qnum++;
			}
			puts(s[veci].name);
		} else if(s[veci].index < qnum){
			while(qnum > s[veci].index){
				fputs("right of ", stdout);//不換行
				qnum--;
			}
			puts(s[veci].name);
		}
	}
	return 0;
}