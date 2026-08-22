// #include <iostream>

// #include <string>

// int main() {
//   std::string s = "hello world!";
//   std::cout << s << std::endl;
//   return 0;
// }

// =====================
// examples
// =====================

// #include <array>
// #include <iostream>
// #include <string>
#include <vector>

int main() {
  // refactor code to use output
  std::string s = "hello world";
  std::vector<std::string> my_vec{s};

  // std::array<std::string, 2> my_arr{s, s};
  // for (const std::string& elem : my_arr) {
  //   std::cout << elem << std::endl;
  // }

  return 0;
}
