#include "bar.h"

#include <stdexcept>

using namespace std;

Bar::Bar(int x, int y, int z) {
  if (x < 1 || x > 100 || y < 1 || y > 100 || z < 1 || z > 100) {
    throw invalid_argument("Wrong bar sizes");
  }

  this->x = x;
  this->y = y;
  this->z = z;
}

void Bar::rotateOX() {
  int t = y;
  y = z;
  z = t;
}

void Bar::rotateOY() {
  int t = x;
  x = z;
  z = t;
}

void Bar::rotateOZ() {
  int t = x;
  x = y;
  y = t;
}

int Bar::getX() const {
  return x;
}

int Bar::getY() const {
  return y;
}

int Bar::getZ() const {
  return z;
}
