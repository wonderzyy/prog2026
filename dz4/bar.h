#pragma once

#include <string>

using namespace std;

class Bar {
 public:
  Bar(int x, int y, int z);

  void rotateOX();
  void rotateOY();
  void rotateOZ();

  int getX() const;
  int getY() const;
  int getZ() const;

 private:
  int x;
  int y;
  int z;
};
