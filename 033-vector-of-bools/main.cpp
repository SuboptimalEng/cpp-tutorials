#include <iostream>
#include <vector>

// using namespace std;
// vector<bool> b{};
// vector<bool> vs bool
// std::vector<bool> 🅱️🅾️🅾️{};
// std::vector<bool> b{};

int main() {
  // bool a = true;
  // std::vector<bool> b{true, false, true, true};
  // bool c = false;

  int c = 123;
  std::vector<int> d{1, 2, 3};
  auto d_0 = d[0];  // d_0 is an `int` and copy
  d_0 = 10;         // changing d_0 will not change d[0]

  bool a = true;
  std::vector<bool> b{true, false, true, true};
  auto b_0 = b[0];  // b_0 is std::vector<bool>::reference
  b_0 = false;      // changes b[0]
  bool b_1 = b[1];  // implicity cast proxy to bool
  // bool* b2 = b[1];
  // bool& b3 = b[1];
  b_1 = true;  // b_1 is a copy

  std::cout << "# of bytes for rand_num: " << sizeof(c) << std::endl;
  std::cout << "# of bytes for d[0]: " << sizeof(d_0) << std::endl;
  std::cout << "# of bytes for a: " << sizeof(a) << std::endl;
  std::cout << "# of bytes for b[0]: " << sizeof(b_0) << std::endl;
  std::cout << "reference b_0: " << b_0 << std::endl;
  std::cout << "changed b[0]: " << b[0] << std::endl;
  std::cout << "copy b_1: " << b_1 << std::endl;
  std::cout << "unchanged b[1]: " << b[1] << std::endl;

  return 0;
}
