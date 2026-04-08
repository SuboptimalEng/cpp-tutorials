// #define NDEBUG

#include <cassert>
#include <iostream>

int add(int a, int b) {
  return a + b;
}

int main() {
  int a = 1;
  int b = 2;

  // std::cout << (add(a, a) == 2) << std::endl;
  // std::cout << (add(b, b) == 4) << std::endl;
  // std::cout << (add(a, b) == 4) << std::endl;  // bad test, should fail

  assert(a == 1);

  assert(add(a, a) == 2);
  assert(add(b, b) == 4);
  assert(add(2, 3) == 5);
  // assert(add(a, b) == 4);  // bad test, should fail

  return 0;
}
