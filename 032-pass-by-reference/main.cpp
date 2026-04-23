#include <iostream>
#include <vector>

// ===
// avoid large copying of data
// ===

// bad - pass by value
void print_v1(std::vector<int> v) {}

// good (but not ideal for end users) - pass by reference
void print_v2(std::vector<int>& v) {}

// best - use const (notify compiler + end users)
void print_v3(const std::vector<int>& v) {}

// ===
// when you want to update the array
// ===

// incorrect - will create copy, not change original vector
void add_one_v1(std::vector<int> v) {}

// incorrect - compiler error when trying to mutate vector
void add_one_v2(const std::vector<int>& v) {}

// correct - pass by reference to mutate array
void add_one_v3(std::vector<int>& v) {}

// ===

void add_one(int x) {
  x++;
}

void add_one_by_ref(int& x) {
  x++;
}

int main() {
  // int a = 1;
  // add_one(a);
  // std::cout << "add_one a: " << a << std::endl;
  // add_one_by_ref(a);
  // std::cout << "add_one_by_ref a: " << a << std::endl;

  std::vector<int> v{1, 2, 3};
  // print_vec_v1(v);
  // print_vec_v1(v);
  // print_vec_v2(v);
  // print_vec_v3(v);

  return 0;
}
