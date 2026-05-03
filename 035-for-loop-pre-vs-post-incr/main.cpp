#include <iostream>
#include <vector>

int main() {

  // 🐢 for (;; i++) {}
  // 🔥 for (;; ++i) {}
  for (int i = 0; i < 1; i++) {}
  for (int i = 0; i < 1; ++i) {}
  // return 0;

  // int i = 4;
  // int a = i++;  // post-increment
  // i = 4;
  // int b = ++i;  // pre-increment
  // i = 4;
  // return 0;

  // should you use i++ or ++i in a for-loop?
  // for (int i = 0; i < 1; i++) {}
  // int c = 4;
  // for (int i = 0; i < 1; ++i) {}
  // return 0;

  // pre-increment approach is preferred iterators
  // cognitive load(?), other languages?
  std::vector<int> v{10, 20, 30};
  for (auto it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
