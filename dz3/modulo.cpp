#include "modulo.h"

#include <string>

using namespace std;

Modulo::Modulo() {
  value = 0;
}

Modulo::Modulo(int value) {
  this->value = normalize(value);
}

int Modulo::normalize(int value) {
  int result = value % MOD;
  if (result < 0) {
    result += MOD;
  }
  return result;
}

Modulo operator+(const Modulo& a, const Modulo& b) {
  return Modulo(a.value + b.value);
}

Modulo operator-(const Modulo& a, const Modulo& b) {
  return Modulo(a.value - b.value);
}

Modulo operator*(const Modulo& a, const Modulo& b) {
  return Modulo(a.value * b.value);
}

bool operator==(const Modulo& a, const Modulo& b) {
  return a.value == b.value;
}

bool operator!=(const Modulo& a, const Modulo& b) {
  return a.value != b.value;
}

bool operator<(const Modulo& a, const Modulo& b) {
  return a.value < b.value;
}

bool operator<=(const Modulo& a, const Modulo& b) {
  return a.value <= b.value;
}

bool operator>(const Modulo& a, const Modulo& b) {
  return a.value > b.value;
}

bool operator>=(const Modulo& a, const Modulo& b) {
  return a.value >= b.value;
}

Modulo::operator int() const {
  return value;
}

Modulo::operator bool() const {
  return value != 0;
}

Modulo::operator string() const {
  return to_string(value);
}
