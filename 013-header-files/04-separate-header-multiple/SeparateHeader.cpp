#include <iostream>

#include "SeparateHeader.hpp"

void SeparateHeader::printSum(int a, int b) {
  std::cout << "separate class -> " << a + b << std::endl;
}
