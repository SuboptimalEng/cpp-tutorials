#include <stdlib.h>
#include <iostream>

void PrintText(std::string s) {
  std::cout << "--- " << s << " ---" << std::endl;
}

void PrintVariables(int a, int b, int c) {
  std::cout << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;
  std::cout << std::endl;
}

void PrintResult(int result) {
  std::cout << "result -> " << result << std::endl;
}

int DoubleVarsAndAdd_v1(int a, int b, int c) {
  a = a * 2;
  b = b * 2;
  c = c * 2;
  return a + b + c;
}

// Should we rename this fn instead?
int DoubleVarsAndAdd_v2(int a, int b, int& c) {
  a = a * 2;
  b = b * 2;
  c = c * 2;
  return a + b + c;
}

int sum(int& a, int* b);

int sum(int& a, int* b) {
  return a + *b;
}

int DoubleVarsAndAdd_v3(int a, int b, int* c) {
  a = a * 2;
  b = b * 2;
  (*c) = (*c) * 2;
  return a + b + (*c);
}

int main() {
  // --- v1: Simple Example ---
  // int a = 1;
  // int b = 1;
  // int c = 1;
  // PrintText("Version 1");
  // PrintVariables(a, b, c);
  // int result_v1 = DoubleVarsAndAdd_v1(a, b, c);
  // PrintResult(result_v1);
  // PrintVariables(a, b, c);

  // --- v2: Pass by Reference ---
  // int a = 1;
  // int b = 1;
  // int c = 1;
  // PrintText("Version 2");
  // PrintVariables(a, b, c);
  // int result_v2 = DoubleVarsAndAdd_v2(a, b, c);
  // PrintResult(result_v2);
  // PrintVariables(a, b, c);

  // --- v3: Pass with Pointer ---
  int a = 1;
  int b = 1;
  int c = 1;
  PrintText("Version 3");
  PrintVariables(a, b, c);
  int result_v3 = DoubleVarsAndAdd_v3(a, b, &c);
  PrintResult(result_v3);
  PrintVariables(a, b, c);

  return 0;
}
