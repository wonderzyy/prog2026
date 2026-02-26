#include "library.h"

Library::Library(int initial_books) {
  if (initial_books < 0) {
    num_books = 0;
  } else if (initial_books > max_books) {
    num_books = max_books;
  } else {
    num_books = initial_books;
  }
}

bool Library::lend_book() {
  if (num_books > 0) {
    --num_books;
    return true;
  }
  return false;
}

bool Library::return_book() {
  if (num_books < max_books) {
    ++num_books;
    return true;
  }
  return false;
}
