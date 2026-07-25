#include <cassert>
#include <iostream>
#include <vector>

// -O0 vs -O3 optimizations intro
// why is it needed?
// example with simple for-loop
// example with large for-loop
// how it is used for release builds + optimization

int sum100() {
  int result = 0;
  for (int i = 0; i <= 100; ++i) {
    result += i;
  }
  return result;
}

int sumVector(std::vector<int>& v) {
  int result = 0;
  for (int i = 0; i <= v.size(); ++i) {
    result += v[i];
  }
  return result;
}

int main(int argc) {
  // int s1 = sum100();
  // std::cout << "sum 100: " << s1 << std::endl;

  // Dynamic size prevents constant folding (1000 elements)
  std::vector<int> v(argc > 100 ? 10 : 1000, 5);
  int s2 = sumVector(v);
  std::cout << "sum vector: " << s2 << std::endl;

  return 0;
}
