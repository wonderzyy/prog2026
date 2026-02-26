#include <iostream>
#include <string>
#include "library.h"

using namespace std;

int main() {
  Library library(10);
  string visits;
  int books = 10;

  cout << "Enter visits sequence (only 1 and 2): ";
  if (!(cin >> visits)) {
    cout << "No input provided.\n";
    return 0;
  }

  for (int i = 0; i < (int)visits.size(); ++i) {
    const char action = visits[i];
    bool success = false;

    if (action == '1') {
      success = library.lend_book();
      if (success) {
        --books;
      }
      cout << "Visit " << (i + 1) << ": lend book -> " << (success ? "success" : "failed") << '\n';
    } else if (action == '2') {
      success = library.return_book();
      if (success) {
        ++books;
      }
      cout << "Visit " << (i + 1) << ": return book -> " << (success ? "success" : "failed") << '\n';
    } else {
      cout << "Visit " << (i + 1)
                << ": invalid symbol '" << action << "' (ignored)\n";
    }
  }

  cout << "Library state: " << books << " of 10 books available.\n";
  return 0;
}
