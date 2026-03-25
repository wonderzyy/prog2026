#include "matrix.h"

#include <stdexcept>

using namespace std;

Matrix::Matrix() {
  rows = 0;
  cols = 0;
  data = nullptr;
}

Matrix::Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw invalid_argument("Wrong matrix size");
  }

  this->rows = rows;
  this->cols = cols;
  data = new int*[rows];

  for (int i = 0; i < rows; i++) {
    data[i] = new int[cols];
    for (int j = 0; j < cols; j++) {
      data[i][j] = 0;
    }
  }
}

Matrix::Matrix(const Matrix& other) {
  rows = other.rows;
  cols = other.cols;

  if (other.data == nullptr) {
    data = nullptr;
  } else {
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new int[cols];
      for (int j = 0; j < cols; j++) {
        data[i][j] = other.data[i][j];
      }
    }
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < rows; i++) {
    delete[] data[i];
  }
  delete[] data;
}

Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    for (int i = 0; i < rows; i++) {
      delete[] data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;

    if (other.data == nullptr) {
      data = nullptr;
    } else {
      data = new int*[rows];
      for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
          data[i][j] = other.data[i][j];
        }
      }
    }
  }

  return *this;
}

int Matrix::getRows() const {
  return rows;
}

int Matrix::getCols() const {
  return cols;
}

int Matrix::get(int row, int col) const {
  return at(row, col);
}

void Matrix::set(int row, int col, int value) {
  at(row, col) = value;
}

int& Matrix::at(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw out_of_range("Wrong index");
  }

  return data[row][col];
}

const int& Matrix::at(int row, int col) const {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw out_of_range("Wrong index");
  }

  return data[row][col];
}
