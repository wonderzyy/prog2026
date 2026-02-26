#include <iostream>
#include <string>

#include "cat.h"

using namespace std;

int main() {
  Cat cat;
  string command;

  while (true) {
    cat.print_state();
    cout << "Enter command (eat/sleep/run/stop): ";

    if (!(cin >> command)) {
      cout << "Input ended unexpectedly.\n";
      break;
    }

    if (command == "stop") {
      break;
    }

    if (command == "eat") {
      cat.eat();
    } else if (command == "sleep") {
      cat.sleep();
    } else if (command == "run") {
      cat.run();
    } else {
      cout << "Unknown command. Available commands: eat, sleep, run, stop.\n";
      continue;
    }
  }

  cat.print_state();
  cout << "Interactive control finished.\n";
  return 0;
}
