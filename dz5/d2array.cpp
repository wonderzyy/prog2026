#include "d2array.h"

#include <stdexcept>

using namespace std;

D2Array::D2Array() {
  rows = 0;
  cols = 0;
  data = nullptr;
}

D2Array::D2Array(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw invalid_argument("Wrong array size");
  }

  this->rows = rows;
  this->cols = cols;
  data = new int[rows * cols];

  for (int i = 0; i < rows * cols; i++) {
    data[i] = 0;
  }
}

D2Array::D2Array(const D2Array& other) {
  rows = other.rows;
  cols = other.cols;

  if (other.data == nullptr) {
    data = nullptr;
  } else {
    data = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
      data[i] = other.data[i];
    }
  }
}

D2Array::~D2Array() {
  delete[] data;
}

D2Array& D2Array::operator=(const D2Array& other) {
  if (this != &other) {
    delete[] data;

    rows = other.rows;
    cols = other.cols;

    if (other.data == nullptr) {
      data = nullptr;
    } else {
      data = new int[rows * cols];
      for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
      }
    }
  }

  return *this;
}

int D2Array::getRows() const {
  return rows;
}

int D2Array::getCols() const {
  return cols;
}

int D2Array::get(int row, int col) const {
  return at(row, col);
}

void D2Array::set(int row, int col, int value) {
  at(row, col) = value;
}

int& D2Array::at(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw out_of_range("Wrong index");
  }

  return data[row * cols + col];
}

const int& D2Array::at(int row, int col) const {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw out_of_range("Wrong index");
  }

  return data[row * cols + col];
}
