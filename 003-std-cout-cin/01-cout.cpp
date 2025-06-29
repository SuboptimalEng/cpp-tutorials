#include <iostream>

int main() {
  bool default_bool = true;
  char default_char = 'h';
  int default_int = 10;
  double default_double = 123.123;
  std::string default_string = "hello world!";

  std::cout << "\nprinting default output...\n\n";
  std::cout << "bool: " << default_bool << "\n";
  std::cout << "bool: " << std::boolalpha << default_bool << "\n";
  std::cout << "char: " << default_char << "\n";
  std::cout << "int: " << default_int << "\n";
  std::cout << "double: " << default_double << "\n";
  std::cout << "string: " << default_string << "\n";
  std::cout << "\n";

  return 0;
}
