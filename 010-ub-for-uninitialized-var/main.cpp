#include <iostream>
using namespace std;

void f1() {
  char a[7] = {'s', 'e', 'c', 'r', 'e', 't', '\0'};
}

void f2() {
  char a[7];
  a[0] = 'h';
  a[1] = 'i';
  std::cout << "Value of a is: " << a << std::endl;
}

int main() {
  f1();
  f2();
}