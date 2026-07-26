#include <iostream>

// -Wall code
int getValue() {
  int temp = 100;  // Warning: unused variable
                   // Missing return statement
}

// -Wextra code
void printMessage(int count) {  // Warning: unused parameter
  std::cout << "Hello from printMessage\n";
}

int main() {
  int x;  // Warning: used uninitialized
  std::cout << "Hello: " << x << "\n";
  getValue();
  printMessage(5);
  return 0;
}

// // -Wextra code
// void printMessage(int count) {  // Warning: unused parameter
//   std::cout << "Hello from printMessage\n";
// }
// int main() {
//   printMessage(5);
//   return 0;
// }
