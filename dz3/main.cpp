#include <iostream>
#include <string>

#include "modulo.h"
#include "point.h"

using namespace std;

int main() {
  Modulo a = 2049;
  Modulo b = -30;
  Modulo c = a + 10;
  Modulo d = 500 + b;
  Modulo e = a * b - 77;

  cout << "Modulo:\n";
  cout << "a = " << (string)a << '\n';
  cout << "b = " << (string)b << '\n';
  cout << "a + 10 = " << (string)c << '\n';
  cout << "500 + b = " << (string)d << '\n';
  cout << "a * b - 77 = " << (string)e << '\n';
  cout << "a == 1: " << (a == 1) << '\n';
  cout << "500 > b: " << (500 > b) << '\n';
  cout << "(bool)b = " << (bool)b << '\n';
  cout << "(int)e = " << (int)e << "\n\n";

  cout << "Points:\n";
  cout << "Enter first point\n";
  Point p1 = input_point();
  cout << "Enter second point\n";
  Point p2 = input_point();

  cout << "p1 = " << (string)p1 << '\n';
  cout << "p2 = " << (string)p2 << '\n';
  cout << "distance = " << (p1 - p2) << '\n';

  return 0;
}
