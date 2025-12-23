#include <iostream>

class InlineClass {
 public:
  void printSum(int a, int b) {
    std::cout << "inline add -> " << a + b << std::endl;
    return;
  }
};
