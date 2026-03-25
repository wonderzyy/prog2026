#include "oven.h"

#include <stdexcept>

using namespace std;

const double GOLD_DENSITY = 19320.0;

Oven::Oven(double meltRateKgPerSecond, double capacityM3)
    : meltRateKgPerSecond(meltRateKgPerSecond), capacityM3(capacityM3) {
  if (meltRateKgPerSecond < 0) {
    throw invalid_argument("Wrong oven speed");
  }
  if (capacityM3 <= 0) {
    throw invalid_argument("Wrong oven volume");
  }

  lastTime = time(0);
}

bool Oven::tryAddBar(double weightKg) {
  if (weightKg <= 0) {
    throw invalid_argument("Wrong bar weight");
  }

  update();

  double freeVolume = capacityM3 - current / GOLD_DENSITY;
  double barVolume = weightKg / GOLD_DENSITY;

  if (barVolume <= freeVolume + 1e-9) {
    current += weightKg;
    return true;
  }

  rejectedBars++;
  rejectedWeight += weightKg;
  return false;
}

double Oven::meltedKg() {
  update();
  return melted;
}

double Oven::currentKg() {
  update();
  return current;
}

int Oven::rejectedCount() const {
  return rejectedBars;
}

double Oven::rejectedKg() const {
  return rejectedWeight;
}

void Oven::update() {
  time_t now = time(0);
  double seconds = difftime(now, lastTime);
  double canMelt = seconds * meltRateKgPerSecond;

  if (canMelt > current) {
    canMelt = current;
  }

  current -= canMelt;
  melted += canMelt;
  lastTime = now;
}
