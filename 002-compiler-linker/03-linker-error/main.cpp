#include <iostream>

void goodbye_world() {
  std::cout << "Goodbye world!" << std::endl;
}

int main() {
  std::cout << "Hello world!" << std::endl;
  goodbye_world();
  return 0;
}