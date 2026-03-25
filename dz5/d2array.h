#pragma once

#include <string>

using namespace std;

class D2Array {
 public:
  D2Array();
  D2Array(int rows, int cols);
  D2Array(const D2Array& other);
  ~D2Array();

  D2Array& operator=(const D2Array& other);

  int getRows() const;
  int getCols() const;

  int get(int row, int col) const;
  void set(int row, int col, int value);

  int& at(int row, int col);
  const int& at(int row, int col) const;

 private:
  int rows;
  int cols;
  int* data;
};
