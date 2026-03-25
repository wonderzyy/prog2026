#pragma once

#include <string>

using namespace std;

class Modulo {
 public:
  static const int MOD = 1024;

  Modulo();
  Modulo(int value);

  friend Modulo operator+(const Modulo& a, const Modulo& b);
  friend Modulo operator-(const Modulo& a, const Modulo& b);
  friend Modulo operator*(const Modulo& a, const Modulo& b);

  friend bool operator==(const Modulo& a, const Modulo& b);
  friend bool operator!=(const Modulo& a, const Modulo& b);
  friend bool operator<(const Modulo& a, const Modulo& b);
  friend bool operator<=(const Modulo& a, const Modulo& b);
  friend bool operator>(const Modulo& a, const Modulo& b);
  friend bool operator>=(const Modulo& a, const Modulo& b);

  explicit operator int() const;
  explicit operator bool() const;
  explicit operator string() const;

 private:
  int value;

  static int normalize(int value);
};
