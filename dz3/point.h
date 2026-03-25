#pragma once

#include <string>

using namespace std;

class Point {
 public:
  Point();
  Point(double x, double y);

  explicit operator string() const;

  friend double operator-(const Point& a, const Point& b);

 private:
  double x;
  double y;
};

Point input_point();
