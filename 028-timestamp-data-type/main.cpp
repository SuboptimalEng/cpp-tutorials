#include <cassert>
#include <iostream>
#include <vector>

// does this work?
bool isSortedV1(const std::vector<int>& v) {
  // std::cout << "size -> " << v.size() << std::endl;
  // std::cout << "size minus one -> " << v.size() - 1 << std::endl;
  // std::cout << std::endl;
  for (size_t i = 0; i < vec.size() - 1; i++) {
    if (v[i + 1] < v[i]) {
      return false;
    }
  }
  return true;
}

// fix using i + 1 < v.size()
bool isSortedV2(const std::vector<int>& v) {
  // v -> size_max
  // i + 1 < size_max
  // i can be at most size_max - 2
  // i + 1 can be size_max - 1
  for (size_t i = 0; i + 1 < v.size(); i++) {
    if (v[i + 1] < v[i]) {
      return false;
    }
  }
  return true;
}

// best approach to avoid confusion (if possible)
bool isSortedV3(const std::vector<int>& v) {
  for (size_t i = 1; i < v.size(); i++) {
    if (v[i] < v[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cout << std::endl;

  std::vector<int> v1{10, 20, 30};
  std::vector<int> v2{10};
  std::vector<int> v3{};

  // assert(isSortedV1(v1));
  // assert(isSortedV1(v2));
  // assert(isSortedV1(v3));

  assert(isSortedV2(v1));
  assert(isSortedV2(v2));
  assert(isSortedV2(v3));

  assert(isSortedV3(v1));
  assert(isSortedV3(v2));
  assert(isSortedV3(v3));

  return 0;
}
