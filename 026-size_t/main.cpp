#include <iostream>
#include <vector>

int main() {
  std::cout << std::endl;

  std::vector<int> v{10, 20, 30};

  // modern approach
  for (int x : v) {
    std::cout << x << std::endl;
  }

  // using int
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }

  // how large is int vs size anyway?
  std::cout << "INT_MIN: " << INT_MIN << std::endl;
  std::cout << "INT_MAX: " << INT_MAX << std::endl;
  std::cout << "SIZE_MAX: " << SIZE_MAX << std::endl;

  // using size_t
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }

  // concerns with size_t
  // for (size_t i = 3; i >= 0; i--) {
  //   std::cout << i << std::endl;
  // }

  // how to fix concerns with size_t?
  for (size_t i = 3; i-- > 0;) {
    std::cout << i << std::endl;
  }

  // iterate backwards, int vs size_t
  // subtle bug, maybe next time :P
  for (int i = v.size() - 1; i >= 0; i--) {
    std::cout << v[i] << std::endl;
  }
  std::cout << std::endl;
  for (size_t i = v.size(); i-- > 0;) {
    std::cout << v[i] << std::endl;
  }

  std::cout << std::endl;
  return 0;
}
