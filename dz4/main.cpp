#include <iomanip>
#include <iostream>

#include "bar.h"
#include "hole.h"
#include "oven.h"

using namespace std;

int main() {
  Bar bar(6, 4, 2);
  Hole hole(4, 6);

  string sequence = hole.rotationSequence(bar);
  cout << "Rotation sequence: " << sequence << '\n';

  Oven oven(5, 0.02);

  cout << "Add 100 kg: " << oven.tryAddBar(100) << '\n';
  cout << "Add 400 kg: " << oven.tryAddBar(400) << '\n';
  cout << "Add 1000 kg: " << oven.tryAddBar(1000) << '\n';

  cout << fixed << setprecision(3);
  cout << "Melted kg: " << oven.meltedKg() << '\n';
  cout << "Current kg: " << oven.currentKg() << '\n';
  cout << "Rejected count: " << oven.rejectedCount() << '\n';
  cout << "Rejected kg: " << oven.rejectedKg() << '\n';

  return 0;
}
