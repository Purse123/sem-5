#include <iostream>
#include "hello.h"

extern "C" void display(void) {
  std::cout << "иди нахуй\n";
}
