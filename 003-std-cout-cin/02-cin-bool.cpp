#include <iostream>

int main() {
  bool default_bool = true;

  std::cout << "\nprinting default output...\n\n";
  std::cout << "bool: " << default_bool << "\n";

  bool my_bool;
  char my_char;

  std::cout << "\ntaking user input...\n\n";
  std::cout << "input bool: ";
  std::cin >> my_bool;  // does this work?

  std::cout << "input char: ";
  std::cin >> my_char;

  std::cout << "\nprinting user input...\n\n";
  std::cout << "my_bool: " << my_bool << std::endl;
  std::cout << "my_char: " << my_char << std::endl;
  std::cout << "\n";

  return 0;
}
