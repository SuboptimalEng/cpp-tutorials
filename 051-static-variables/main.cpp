#include <iostream>

// Static variables are not considered best practice
// But there are seen in programming classes heh, or if you use constants like `std::numbers::pi`.

// How does C++ handle static variables in the compiler/assembly?
// 2 cases (comp-time vs run-time)
// - [this video] static var determined at compile-time
//   - static int count = 9;
//   - variable not stored on fn stack frame
//   - allocated on fixed mem addr (e.g. data section, unlike local variables)
//   - variable used across fn calls
// - [maybe another video?] static var determined at runtime
//   - static int count = getRandomNum();
//   - pre-C++ 11, this was NOT thread-safe!
//   - C++ adds locking + possible boolean check (into assembly behind-the-scenes)

// In this video, we will go over what they are, and more
// importantly, how C++ constructs + handles them!

void MyFn() {
  int localVar = 8;
  localVar++;
  static int count = 8;
  count++;
  // std::cout << "local var: " << localVar << std::endl;
  // std::cout << "static var: " << count << std::endl;
}

int main() {
  MyFn();
  MyFn();
  MyFn();
  // std::cout << "---------" << std::endl;
  // std::cout << "---------" << std::endl;
  // std::cout << "---------" << std::endl;
  return 0;
}
