#include <iostream>

int main() {
  bool my_bool;
  char my_char;
  int my_int;
  double my_double;
  std::string my_string;

  std::cout << "\ntaking user input...\n\n";
  std::cout << "input bool: ";
  std::cin >> my_bool;
  // std::cin >> std::boolalpha >> my_bool;

  std::cout << "input char: ";
  std::cin >> my_char;

  std::cout << "input int: ";
  std::cin >> my_int;

  std::cout << "input double: ";
  std::cin >> my_double;

  std::cin.ignore();
  std::cout << "input string: ";
  // std::cin >> my_string;  // does this work for multiple words?
  std::getline(std::cin, my_string);

  std::cout << "\nprinting user input...\n\n";
  std::cout << "my_bool: " << my_bool << std::endl;
  std::cout << "my_char: " << my_char << std::endl;
  std::cout << "my_int: " << my_int << std::endl;
  std::cout << "my_double: " << my_double << std::endl;
  std::cout << "my_string: " << my_string << std::endl;
  std::cout << "\n";
  return 0;
}
