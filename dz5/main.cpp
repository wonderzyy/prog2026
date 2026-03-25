#include <iostream>

#include "d2array.h"
#include "matrix.h"

using namespace std;

void printD2Array(const D2Array& a) {
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getCols(); j++) {
      cout << a.get(i, j) << ' ';
    }
    cout << '\n';
  }
}

void printMatrix(const Matrix& a) {
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getCols(); j++) {
      cout << a.get(i, j) << ' ';
    }
    cout << '\n';
  }
}

int main() {
  D2Array a(2, 2);
  a.set(0, 0, 1);
  a.set(0, 1, 2);
  a.set(1, 0, 3);
  a.set(1, 1, 4);

  cout << "D2Array:\n";
  cout << "rows = " << a.getRows() << ", cols = " << a.getCols() << '\n';
  printD2Array(a);

  Matrix b(2, 3);
  b.set(0, 0, 5);
  b.set(0, 1, 6);
  b.set(0, 2, 7);
  b.set(1, 0, 8);
  b.set(1, 1, 9);
  b.set(1, 2, 10);

  cout << "\nMatrix:\n";
  cout << "rows = " << b.getRows() << ", cols = " << b.getCols() << '\n';
  printMatrix(b);

  return 0;
}
