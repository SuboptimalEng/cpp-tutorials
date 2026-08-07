#include <iostream>

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

int getRandom() {
  return 9;
}

void MyFn() {
  static int count = getRandom();
  count++;
  // std::cout << "static: " << count << std::endl;
}

int main() {
  MyFn();
  MyFn();
  MyFn();
  return 0;
}
