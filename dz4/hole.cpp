#include "hole.h"

#include <stdexcept>

using namespace std;

Hole::Hole(int a, int b) {
  if (a < 1 || b < 1) {
    throw invalid_argument("Wrong hole sizes");
  }

  this->a = a;
  this->b = b;
}

string Hole::rotationSequence(const Bar& bar) const {
  if (fits(bar)) {
    return ".";
  }

  string axes = "xyz";

  for (int i = 0; i < axes.size(); i++) {
    Bar t = bar;
    if (axes[i] == 'x') {
      t.rotateOX();
    } else if (axes[i] == 'y') {
      t.rotateOY();
    } else {
      t.rotateOZ();
    }

    if (fits(t)) {
      return string(1, axes[i]);
    }
  }

  for (int i = 0; i < axes.size(); i++) {
    for (int j = 0; j < axes.size(); j++) {
      Bar t = bar;

      if (axes[i] == 'x') {
        t.rotateOX();
      } else if (axes[i] == 'y') {
        t.rotateOY();
      } else {
        t.rotateOZ();
      }

      if (axes[j] == 'x') {
        t.rotateOX();
      } else if (axes[j] == 'y') {
        t.rotateOY();
      } else {
        t.rotateOZ();
      }

      if (fits(t)) {
        string ans = "";
        ans += axes[i];
        ans += axes[j];
        return ans;
      }
    }
  }

  return "";
}

bool Hole::fits(const Bar& bar) const {
  return bar.getX() <= a && bar.getY() <= b;
}
