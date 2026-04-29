#include <iostream>
#include <vector>

int main() {
  // bool a = true;
  // std::vector<bool> b{true, false, true, true};
  // bool c = false;

  int c = 123;
  std::vector<int> d{1, 2, 3};
  auto d_0 = d[0];
  d_0 = 10;
  std::cout << "# of bytes for rand_num: " << sizeof(c) << std::endl;
  std::cout << "# of bytes for d[0]: " << sizeof(d_0) << std::endl;
  std::cout << "d[0]: " << d[0] << std::endl;

  bool a = true;
  std::vector<bool> b{true, false, true, true};
  // `f` is std::vector<bool>::reference
  auto b_0 = b[0];
  b_0 = false;
  // cast proxy to boolean to get actual size
  // also is a copy, not reference
  bool b_1 = b[1];
  b_1 = true;
  std::cout << "# of bytes for a: " << sizeof(a) << std::endl;
  std::cout << "# of bytes for b[0]: " << sizeof(b_0) << std::endl;
  std::cout << "# of bytes for b[1]: " << sizeof(b_1) << std::endl;
  std::cout << "b[0]: " << b[0] << std::endl;
  std::cout << "b_1: " << b_1 << std::endl;
  std::cout << "b[1]: " << b[1] << std::endl;

  return 0;
}
