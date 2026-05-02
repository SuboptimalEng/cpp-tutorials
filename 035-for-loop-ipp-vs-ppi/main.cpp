#include <iostream>
#include <vector>

int main() {
  // for (int i = 0; i < 5; i++) {}
  // for (int i = 0; i < 5; ++i) {}
  // return 0;

  int i = 4;
  int a = i++;  // post-increment
  i = 4;
  int b = ++i;  // pre-increment
  i = 4;
  return 0;

  // what happens when value is not used?
  int i = 4;
  i++;
  ++i;
  return 0;

  // does it matter what you do in for-loops?
  // for (int i = 0; i < 1; i++) {}
  // int c = 4;
  // for (int i = 0; i < 1; ++i) {}
  // return 0;

  // pre-increment approach is preferred iterators
  // cognitive load(?), other languages?
  // std::vector<int> v{10, 20, 30};
  // for (auto it = v.begin(); it != v.end(); it++) {
  //   std::cout << *it << std::endl;
  // }
  // for (auto it = v.begin(); it != v.end(); ++it) {
  //   std::cout << *it << std::endl;
  // }
  // return 0;
}
