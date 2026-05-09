#include <iostream>

#include <thread>

using namespace std;

void print_hello() {
  std::this_thread::sleep_for(std::chrono::seconds(2));
  cout << "hello from thread!" << endl;
}

// void slow_fn() {
//   std::this_thread::sleep_for(std::chrono::seconds(2));
//   cout << "slow fn completed!" << endl;
// }

// void add_five(int& val) {
//   std::this_thread::sleep_for(std::chrono::seconds(2));
//   val = val + 5;
// }

int main() {

  // std::thread t1(print_hello);

  // t1.join();
  // t1.detach();

  // Problem with auto-join
  // Thread might take long time
  // std::thread t2(slow_fn);

  // Problem with auto-detach
  // This thread might wake up after 'x' is destroyed
  // int x = 10;
  // std::thread t3(add_five, std::ref(x));

  // C++ 20 introduces jthread!
  std::jthread jt1(print_hello);

  return 0;
}
