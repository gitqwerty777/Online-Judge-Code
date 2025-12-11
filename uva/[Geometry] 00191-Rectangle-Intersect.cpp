#include <stdio.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;
//using geometry.h
/*
  6
4 9 11 2 1 5 7 1
4 9 11 2 7 5 1 1
4 9 11 2 1 1 7 5
4 9 8 2 1 5 7 1
4 9 7 5 1 5 7 1
2 2 3 3 1 5 7 1
F
F
F
T
T
T
*/

double min(int num, ...){
  va_list args;
  double min = 2147483647;

  /* store values after num*/
  va_start(args, num);
  for(int i = 0; i < num; i++){
    double arg = va_arg(args, double);
    if(min > arg){
      min = arg;
    }
  }
  va_end(args);
  return min;
}

class Vector;
class Point{
public:
  Point();
  Point(double, double);
  Vector operator-(Point);
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
  friend double degree(Vector, Vector);
  friend bool isclockwise_vec(Vector a, Vector b){
    return a.cross(b) < 0;
  }
private:
  double x, y;
};

Vector Point::operator-(Point p){
    return Vector(this->x - p.x, this->y - p.y);
}

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
double degree(Vector v1, Vector v2){
  double l1 = v1.length();
  double l2 = v2.length();
  double cosin = v1.dot(v2) / l1 / l2;
  //  printf("l1 %lf, l2  %lf\n", l1, l2);
  return acos(cosin) * (180 / M_PI); //arg cosin
}
bool isclockwise(Point p1, Point p2, Point p3){//point is better
  return (p3.y - p1.y)*(p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p1.x) < 0;
}

double point_cross(Point p0, Point p1, Point p2){
  return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}
double point_dot(Point& o, Point& a, Point& b){
    return (a.x-o.x) * (b.x-o.x) - (a.y-o.y) * (b.y-o.y);
}

bool point_intersect(Point p, Point p1, Point p2)
{
  // 點與線段共線，而且點要在線段之間。
  return point_cross(p, p1, p2) == 0
    && point_dot(p, p1, p2) <= 0;

}
// 避免溢位
  double sign(double x)
  {
      return fabs(x) < 1e-9 ? 0 : (x > 0 ? +1 : -1);
  }
  bool intersect1D(int a1, int a2, int b1, int b2)
  {
      if (a1 > a2) swap(a1, a2);
      if (b1 > b2) swap(b1, b2);
      return max(a1, b1) <= min(a2, b2);
  }


class Line{
 public:
  bool isseg;
  Point p1, p2;//not the same
  void set(bool b, Point p11, Point p22){
    isseg = b; p1 = p11; p2 = p22; 
  }
  bool intersect(Line l){
    if(!this->isseg || !l.isseg){//one line and one line segment ?????check
      double a, b;
      if(this->isseg){
  a = (l.p1.y - l.p2.y) / (l.p1.x - l.p2.x);
  b = l.p1.y - a * l.p1.x;
  if((this->p1.x * a + b)*(this->p2.x * a + b) <= 0){//異側
    return true;
  } else {
    return false;
  }
      } else {
  a = (this->p1.y - this->p2.y) / (this->p1.x - this->p2.x);
  b = this->p1.y - a * this->p1.x;
  if((l.p1.x*a + b)*(l.p2.x*a+b) <= 0){
    return true;
  } else {
    return false;
  }
      }
    } else {//two line segments
      Point a1 = this->p1, a2 = this->p2, b1 = l.p1, b2 = l.p2;
/*
      double c1 = point_cross(a1, a2, b1);
      double c2 = point_cross(a1, a2, b2);
      double c3 = point_cross(b1, b2, a1);
      double c4 = point_cross(b1, b2, a2);
 
      // 端點不共線
      if (c1 * c2 < 0 && c3 * c4 < 0) return true;
      // 端點共線
      if (c1 == 0 && point_intersect(a1, a2, b1)) return true;
      if (c2 == 0 && point_intersect(a1, a2, b2)) return true;
      if (c3 == 0 && point_intersect(b1, b2, a1)) return true;
      if (c4 == 0 && point_intersect(b1, b2, a2)) return true;
      return false;
*/
    return intersect1D(a1.x, a2.x, b1.x, b2.x)
        && intersect1D(a1.y, a2.y, b1.y, b2.y)
        && sign(point_cross(a1, a2, b1)) * sign(point_cross(a1, a2, b2)) <= 0
        && sign(point_cross(b1, b2, a1)) * sign(point_cross(b1, b2, a2)) <= 0;
    }
  }
  double cross(Line l){
    Vector v1 = this->p2 - this->p1;
    Vector v2 = l.p2 - l.p1;
    return v1.cross(v2);
  }
};

double distance(Point p1, Point p2){
  return sqrt((p1.x - p2.x) * (p1.x-p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double distance(Point p, Line l){
  if(l.isseg){
    Vector v = l.p2-l.p1;
    Vector v1 = p - l.p1;
    Vector v2 = p - l.p2;
    if(v.dot(v1) <= 0) return v1.length();
    if(v.dot(v2) >= 0) return v2.length();
    //    printf("(%lf, %lf) to line(%lf, %lf), (%lf, %lf) = %lf\n", p.x, p.y, l.p1.x,l.p1.y, l.p2.x, l.p2.y, fabs(v.cross(v1) / double(v.length())));
    return fabs(v.cross(v1) / double(v.length()));//it's fabs!!
  } else {
    Vector v1 = p-l.p1;
    Vector v2 = l.p2-l.p1;
    //    v1.printline();
    //    v2.printline();
    return fabs(v1.cross(v2)) / v2.length();//面積除底
  }
}

double distance(Line l1, Line l2){
  if(l1.isseg && l2.isseg){
    if(l1.intersect(l2)){
      //      printf("intersect\n");
      return 0;
      }
    else{
      return min( 4,
      distance(l1.p1, l2),
      distance(l1.p2, l2),
      distance(l2.p1, l1),
      distance(l2.p2, l1)
      );
    }
  } else if(!l1.isseg && !l2.isseg){
    if(l1.cross(l2) != 0)
      return 0;
    else{
      //      printf("cross = %lf\n", l1.cross(l2));
        return distance(l1.p1, l2);//same as a point to a line
  
    }
    
  } else {// a segment and a line
    if(l1.intersect(l2)){// two types of intersect
      return 0;
    } else{
      if(l1.isseg){
  return min(2,
       distance(l1.p1, l2),
       distance(l1.p2, l2)
       );
      } else {
  return min(2,
       distance(l2.p1, l1),
       distance(l2.p2, l1)
       );
      }
    }
  }
}

bool ismiddle(double a, double b, double c){
  return (a > c && a < b) || (a > b && a < c);
}

bool check_inside(Line l, Point p1, Point p2){
  return ismiddle(l.p1.x, p1.x, p2.x) && ismiddle(l.p1.y, p1.y, p2.y);
}

int main(){
  int N;
  Line l;
  Point p1, p2, p3, p4;
  Line l1, l2, l3, l4;
  scanf("%d", &N);
  l.isseg = true;
  l1.isseg = true;
  l2.isseg = true;
  l3.isseg = true;
  l4.isseg = true;
  
  while(N--){
    scanf("%lf %lf %lf %lf", &l.p1.x, &l.p1.y, &l.p2.x, &l.p2.y);
    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
    //make 4 lines(rectangle)
    p3.x = p1.x; p3.y = p2.y;
    p4.x = p2.x; p4.y = p1.y;
    l1.p1 = p1; l1.p2 = p3;
    l2.p1 = p1; l2.p2 = p4;
    l3.p1 = p2; l3.p2 = p3;
    l4.p1 = p2; l4.p2 = p4;
    
    if(check_inside(l, p1, p2) || l.intersect(l1) || l.intersect(l2) || l.intersect(l3) || l.intersect(l4)){
      puts("T");
    } else {
      puts("F");
    }
  }
  return 0;
}