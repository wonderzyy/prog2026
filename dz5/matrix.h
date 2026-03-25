#pragma once

#include <string>

using namespace std;

class Matrix {
 public:
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  ~Matrix();

  Matrix& operator=(const Matrix& other);

  int getRows() const;
  int getCols() const;

  int get(int row, int col) const;
  void set(int row, int col, int value);

  int& at(int row, int col);
  const int& at(int row, int col) const;

 private:
  int rows;
  int cols;
  int** data;
};
