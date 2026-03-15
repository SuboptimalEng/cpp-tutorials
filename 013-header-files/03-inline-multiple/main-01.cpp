#include "InlineClass.hpp"

// // why is this slow?
// #include "MyHeader.h"

int main() {
  InlineClass adder;
  adder.printSum(1, 2);
  return 0;
}
