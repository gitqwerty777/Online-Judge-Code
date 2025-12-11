#include <stdio.h>
#include <vector>
using namespace std;

#define VEC1N 1000000000
class BigNumber{
	public:
        BigNumber(string s);		
		BigNumber(vector<int>&);
		BigNumber operator+(BigNumber&);
        void print_number();//print in a line
	private:
        string ori;
		int deg;//位數
		vector<string> vec1; //used in +, -
		void init(string);
		void make_vector(vector<int>&, int);
};
typedef BigNumber intxx;

BigNumber::BigNumber(vector<int> &vec){//type 1 = vec1, 2 = *, 3 = / 
     string s;
     int lo = vec.size();
          s.push_back(vec[lo-1]);
          for(int i = lo-2; i >= 0; i--){
               int way = 9; int temp = vec[i];
               if(vec[i] == 0)
                    s.push_back("00000000");
               else{
                    while(temp != 0){
                         temp /= 10;
                         way--;
                    }
                    while(way-- != 0)
                         s.push_back("0");
               }
               s.push_back(string(vec[i]));
          }
     this->init(s);
}


void BigNumber::print_number(){
	puts(this->ori);
}
void BigNumber::init(string s){
     if(s[0] == '-'){
          neg = true;
          s.erase(0, 1);
     } else {
          neg = false;
     }
     this->ori = s;
     this->deg = s.size();
     this->make_vector1();
     return;
}
BigNumber::BigNumber(){
	this->init("");
}
BigNumber::BigNumber(string s){
	this->init(s);
}

BigNumber BigNumber::operator+(BigNumber &added){//int + big??
     int loa = this->vec1.size();
     int lob = added.vec1.size();
     int lo = (loa>lob)?loa:lob;
     
     vector<int> ans;
     int flow = 0;
     if(loa >= lob)
          for(i = 0; i < lo; i++){//use some pointer to replace
               if(i < lob)
                    ans.push_back(this->vec1[i] + added.vec1[i] + flow);
               else
                    ans.push_back(this->vec1[i] + flow);
               
               if(ans[i] >= VEC1N){
                    ans[i] -= VEC1N;
                    flow = 1;
               }
               else
                   flow = 0;
          }
     else if(lob > loa)
          for(i = 0; i < lo; i++){
                if(i < loa)
                      ans.push_back(this->vec1[i] + added.vec1[i] + flow);
                else
                      ans.push_back(added.vec1[i] + flow);
               
                if(ans[i] >= VEC1N){
                      ans[i] -= VEC1N;
                      flow = 1;
                }
                else
                      flow = 0;
          }

     if(flow)//增加一位
          ans.push_back(1);
     return BigNumber(ans);
}

void BigNumber::make_vector(vector<int>& vec, int maxdeg){//use stringstream instead of atof
	vec.clear();
	string temp, ori = this->ori;
	int i = 0, count = this->deg;
	do{
		count -= maxdeg;
		if(count > 0)
			temp.assign(ori, count, maxdeg);
	    else
			temp.assign(ori, 0, count + maxdeg);//end of string
		vec.push_back(atof(temp.c_str()));
		i++;
	}while(count > 0);//check
}


int main(){
	

	return 0;
}