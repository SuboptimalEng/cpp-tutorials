#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx;
int counter = 0;

void increment() {
  for (size_t i = 0; i < 10000; i++) {
    // mtx.lock();
    counter++;
    // mtx.unlock();
  }
}

int main() {
  // example 1 - multiple lines of assembly
  // std::thread t1(increment);
  // std::thread t2(increment);
  // t1.join();
  // t2.join();
  // cout << "counter: " << counter << endl;

  // example 2 - 1 line of assembly
  for (int i = 0; i < 10000; i++) {
    counter = 0;
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    if (counter < 20000) {
      cout << "counter: " << counter << endl;
    }
  }
  return 0;
}
