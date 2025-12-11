#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//240/244


class Point{
public:
  Point();
  Point(double, double);
  void set(double, double);
  double x, y;
friend bool isclockwise(Point, Point, Point);
};

Point::Point (){
  this->x = 0; this->y = 0;
}
Point::Point(double x, double y){
  this->set(x, y);
}
void Point::set(double x, double y){
  this->x = x; this->y = y;
}

class Vector {
public:
  Vector();
  Vector(double, double);
  void set(double, double);
  Vector operator-(Vector&);
  double sin(Vector);
  double distance(Vector);
  double length();
  double dot(Vector);
  double cross(Vector);
  void printline();
private:
  double x, y;
friend double cos(Vector, Vector);
};

Vector::Vector(){
  this->x = 0;
  this->y = 0;
}
Vector::Vector(double x, double y){
  this->set(x, y);
}
void Vector::set(double x, double y){
  this->x = x;
  this->y = y;
}
Vector Vector::operator-(Vector& v){
  return Vector(this->x - v.x, this->y - v.y);
}
double Vector::dot(Vector v){
  return this->x * v.x + this->y * v.y;
}
double Vector::cross(Vector v){
  return this->x * v.y - this->y * v.x;
}
double Vector::distance(Vector v){
  Vector v1 = *this - v;
  return sqrt(v1.x * v1.x + v1.y*v1.y);
}
void Vector::printline(){
  printf("x = %lf, y = %lf\n", this->x , this->y);
}
double Vector::length(){
  return sqrt(this->x * this->x + this->y * this->y);
}
double cos(Vector v1, Vector v2){
  double l1 = v1.length();
  double l2 = v2.length();
  double cosin = v1.dot(v2) / l1 / l2;
  //  printf("l1 %lf, l2  %lf\n", l1, l2);
  return acos(cosin) * (180 / M_PI); //arg cosin
}
bool isclockwise(Point p1, Point p2, Point p3){//point is better
  return (p3.y - p1.y)*(p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p1.x) < 0;
}

  int N;
  double maxd, mind;

void check_anglesum(double* deg){
  double sum = 0;
  for(int i = 0; i < N; i++){
    sum += deg[i];
  }
  if(int(abs(sum - (N-2) * 180)) < 1  && int(abs((360*N - sum) - (N-2)*180) < 1)){
    //    printf("NO way!\n");
    maxd = -1; mind = 360;
    for(int i = 0; i < N ;i++){
      deg[i] = 360 - deg[i];
      if(maxd < deg[i])
	maxd = deg[i];
      if(mind > deg[i])
	mind = deg[i];
    }
  }
}

int main(){

  int prex, prey, x, y;
  int orix, oriy; //first dot
  Vector v1, v2, oriv, lastv;
  Point p[20];
  Vector v[20];
  double deg[20];
  bool isclock[20];
  while(scanf("%d", &N) == 1 && N >= 3){
    maxd = -1; mind = 360;
    scanf("%d %d %d %d", &prex, &prey, &x, &y);
    p[0].set(prex, prey);
    p[1].set(x, y);
    v[1].set(x - prex, y - prey);
    for(int i = 2; i < N; i++){
	scanf("%d %d", &x, &y);
	p[i].set(x, y);
 	v[i].set(p[i].x - p[i-1].x, p[i].y - p[i-1].y);
	deg[i-1] = cos(v[i-1], v[i]);//deg()
	isclock[i-1] = isclockwise(p[i-2], p[i-1], p[i]);
	//printf("cosin = %lf\n", cosin);
    }
    //last one: ori point and last point
    isclock[0] = isclockwise(p[N-1], p[0], p[1]);
    isclock[N-1] = isclockwise(p[N-2], p[N-1], p[0]);
    v[0].set(p[0].x - p[N-1].x, p[0].y - p[N-1].y);
    deg[N-1] = cos(v[N-1], v[0]);
    deg[0] = cos(v[0], v[1]);
    
    //checkclockwise and give correct degree
    int clock = 0;
    for(int i = 0; i < N; i++){
      if(isclock[i])
	clock++;
      else
	clock--;
    }
    for(int i = 0; i < N; i++){
      if(clock > 0 && !isclock[i] || clock < 0 && isclock[i]){
	deg[i] += 180;
      } else {
	deg[i] = 180 - deg[i];
      }
      if(maxd < deg[i])
	maxd = deg[i];
      if(mind > deg[i])
	mind = deg[i];
    }
    check_anglesum(deg);
    printf("%.6lf %.6lf\n", mind, maxd);
  }
  return 0;
}