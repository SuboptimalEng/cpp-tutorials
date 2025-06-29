#include <iostream>

int main() {
  bool my_bool;
  char my_char;

  std::cout << "\ntaking user input...\n\n";
  std::cout << "input bool: ";
  std::cin >> std::boolalpha >> my_bool;  // does this work for true or false?

  std::cout << "input char: ";
  std::cin >> my_char;

  std::cout << "\nprinting user input...\n\n";
  std::cout << "my_bool: " << my_bool << std::endl;
  std::cout << "my_char: " << my_char << std::endl;
  std::cout << "\n";

  return 0;
}
