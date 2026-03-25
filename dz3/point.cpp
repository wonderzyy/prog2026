#include "point.h"

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

Point::operator string() const {
  stringstream ss;
  ss << "(" << x << ", " << y << ")";
  return ss.str();
}

double operator-(const Point& a, const Point& b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

Point input_point() {
  double x, y;
  cout << "Enter point (x y): ";
  cin >> x >> y;
  return Point(x, y);
}
