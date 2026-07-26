#include <iostream>

// -Wall code
int getValue() {
  int temp = 100;  // Warning: unused variable
                   // Missing return statement
}

int main() {
  int x;  // Warning: used uninitialized
  std::cout << "Hello: " << x << "\n";
  getValue();
  return 0;
}

// -Wextra code
// void printMessage(int count) {  // Warning: unused parameter
//   std::cout << "Hello\n";
// }

// int main() {
//   unsigned int size = 10;
//   if (size < 0) {  // Warning: comparison always false
//     std::cout << "Negative\n";
//   }
//   if (size > 5)
//     ;  // Warning: empty if body
//   printMessage(5);
//   return 0;
// }
