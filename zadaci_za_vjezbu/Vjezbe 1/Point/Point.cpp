#include "Point.hpp"

Point::Point() {}
Point::Point(double x, double y) : x_{x}, y_{y}{}
Point::Point(const Point& point) : x_{point.x_}, y_{point.y_}{}
Point::Point(Point&& point) : x_{point.x_}, y_{point.y_}{
  point.x_ = 0.0;
  point.y_ = 0.0;
}
Point& Point::operator=(const Point& point){
  x_ = point.x_;
  y_ = point.y_;
  return *this;
}
Point& Point::operator=(Point&& point){
  x_ = point.x_;
  point.x_ = 0.0;
  y_ = point.y_;
  point.y_ = 0.0;
  return *this;
}
Point Point::operator+(const Point& point) const {
  return Point{x_ + point.x_, y_ + point.y_}; 
}
Point Point::operator-(const Point& point) const {
  return Point{x_ - point.x_, y_ - point.y_}; 
}
Point Point::operator*(double scalar) const {
  return Point{x_*scalar, y_*scalar};
}

Point Point::operator/(double scalar) const {
  if(scalar==0.0) throw std::invalid_argument("Invalid argument");
  return Point{x_/scalar, y_/scalar};
}

Point& Point::operator+=(const Point& point){
  x_ += point.x_;
  y_ += point.y_;
  return *this;
}
Point& Point::operator-=(const Point& point){
  x_ -= point.x_;
  y_ -= point.y_;
  return *this;
}

Point& Point::operator*=(double scalar){
  x_*=scalar;
  y_*=scalar;
  return *this;
}
Point& Point::operator/=(double scalar){
  if(scalar==0.0) throw std::invalid_argument("Invalid argument");
  x_/=scalar;
  y_/=scalar;
  return *this;
}

bool Point::operator==(const Point& point) const {
  return x_==point.x_ && y_==point.y_;
}

bool Point::operator!=(const Point& point) const {
  return x_!=point.x_ || y_!=point.y_;
}

double Point::x() const {
  return x_;
}

double Point::y() const {
  return y_;
}

void Point::setX(double x){
  x_ = x;
}

void Point::setY(double y){
  y_ = y;
}

double Point::distance(const Point& point) const{
  return sqrt(pow(point.x_ - x_, 2) + pow(point.y_ - y_, 2));
}

std::ostream& operator<<(std::ostream& os, const Point& point){
  os << "Point(x=" << point.x() << ", y=" << point.y() << ")"<< std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Point& point){
  double x, y;
  is >> x >> y;
  point.setX(x);
  point.setY(y);
  return is;
}
