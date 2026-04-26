#include <iostream>

int main() {
  // int a = 1;
  // int b = a;
  // std::cout << "before a: " << a << std::endl;
  // std::cout << "before b: " << b << std::endl;
  // b = 5;
  // std::cout << "after a: " << a << std::endl;
  // std::cout << "after b: " << b << std::endl;
  // std::cout << "addr a: " << &a << std::endl;
  // std::cout << "addr b: " << &b << std::endl;

  // `b` is an alias to `a`
  int a = 1;
  int& b = a;
  b = 5;
  // std::cout << "after a: " << a << std::endl;
  // std::cout << "after b: " << b << std::endl;
  // std::cout << "addr a: " << &a << std::endl;
  // std::cout << "addr b: " << &b << std::endl;

  // Compiler error: Must be init immediately.
  // Reference is an alias, so it must bind to valid object.
  // C++ language does not have concept of empty reference.
  // int a = 1;
  // int& b;  // cannot be null
  // b = a;

  // `c` will always be an alias to `b`, value inside of it can change
  // int a = 1;
  // int b = 2;
  // int& c = b;
  // c = a;  // c still refers to b

  return 0;
}
