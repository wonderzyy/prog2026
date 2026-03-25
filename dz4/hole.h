#pragma once

#include <string>

#include "bar.h"

using namespace std;

class Hole {
 public:
  Hole(int a, int b);

  string rotationSequence(const Bar& bar) const;

 private:
  int a;
  int b;

  bool fits(const Bar& bar) const;
};
