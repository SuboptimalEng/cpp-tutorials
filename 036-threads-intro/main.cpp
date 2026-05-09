#include <iostream>

#include <thread>

using namespace std;

void print_hello() {
  cout << "hello from thread!" << endl;
}

void fn() {}

void add(int x, int y) {
  cout << x + y << endl;
}

int main() {
  // pthread, thread, jthread

  std::thread t1(print_hello);

  // std::thread t1(fn);
  // std::thread t2(fn);

  std::thread t2(add, 1, 2);

  cout << "in main" << endl;
  cout << "in main" << endl;
  cout << "in main" << endl;
  cout << "in main" << endl;
  cout << "in main" << endl;
  cout << "in main" << endl;
  cout << "in main" << endl;

  if (t1.joinable()) {
    t1.join();
  }
  if (t2.joinable()) {
    t2.join();
  }

  // t1.detach();  // not best practice, code smell

  return 0;
}
