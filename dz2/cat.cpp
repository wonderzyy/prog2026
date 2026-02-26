#include "cat.h"
#include <iostream>

using namespace std;

Cat::Cat(int age_, double energy_) : age(age_), energy(energy_) {
  check_astral();
}

Cat::Cat(const Cat& other) {
  cout << "Copy constructor called\n";
  age = other.age;
  energy = other.energy;
  astral = other.astral;
}

Cat& Cat::operator=(const Cat& other) {
  cout << "Copy assignment operator called\n";
  age = other.age;
  energy = other.energy;
  astral = other.astral;
  return *this;
}

void Cat::sleep() noexcept {
  if (!check_astral()) {
    ++age;
    energy += 10;
  }
}

void Cat::run() noexcept {
  if (!check_astral()) {
    ++age;
    energy -= 20;
  }
}

void Cat::eat() noexcept {
  if (!check_astral()) {
    ++age;
    energy += 30;
  }
}

void Cat::print_state() {
  if (check_astral()) {
    cout << "Cat is in astral state\n";
  } else {
    cout << "Cat(age=" << age << ", energy=" << energy << ")\n";
  }
}

bool Cat::check_astral() noexcept {
  if (age > 10000 || energy < 0 || energy > max_energy) {
    astral = true;
  }
  return astral;
}
