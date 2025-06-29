#include <iostream>

// X.3 A Tour of C++: The Basics
// [5] (∗1) Write out a bool, a char, an int, a double, and a string.
// [6] (∗1) Read in a bool, a char, an int, a double, and a string.

int main() {
  bool default_bool = true;
  char default_char = 'h';
  int default_int = 10;
  double default_double = 123.123;
  std::string default_string = "hello world!";

  std::cout << "\nprinting default output...\n\n";
  std::cout << "bool: " << default_bool << "\n";
  std::cout << "char: " << default_char << "\n";
  std::cout << "int: " << default_int << "\n";
  std::cout << "double: " << default_double << "\n";
  std::cout << "string: " << default_string << "\n";

  bool my_bool;
  char my_char;

  std::cout << "\ntaking user input...\n\n";
  std::cout << "input bool: ";
  std::cin >> my_bool;
  // std::cin >> std::boolalpha >> my_bool;

  std::cout << "input char: ";
  std::cin >> my_char;

  std::cout << "\nprinting user input...\n\n";
  std::cout << "my_bool: " << my_bool << std::endl;
  std::cout << "my_char: " << my_char << std::endl;
  return 0;
}
