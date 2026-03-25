#pragma once

#include <ctime>

using namespace std;

class Oven {
 public:
  Oven(double meltRateKgPerSecond, double capacityM3);

  bool tryAddBar(double weightKg);

  double meltedKg();
  double currentKg();
  int rejectedCount() const;
  double rejectedKg() const;

 private:
  double meltRateKgPerSecond;
  double capacityM3;

  double melted = 0;
  double current = 0;
  int rejectedBars = 0;
  double rejectedWeight = 0;

  time_t lastTime;

  void update();
};
