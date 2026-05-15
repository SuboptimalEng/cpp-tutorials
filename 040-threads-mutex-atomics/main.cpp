#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

atomic<int> counter(0);

// std::mutex mtx;
// int counter = 0;

void increment() {
  for (size_t i = 0; i < 100000; i++) {
    // mtx.lock();
    // cout << "counter: " << counter << endl;
    counter++;
    // cout << "counter: " << counter << endl;
    // mtx.unlock();
  }
}

int main() {
  std::thread t1(increment);
  // std::thread t2(increment);
  t1.join();
  // t2.join();
  cout << "counter: " << counter.load() << endl;
  return 0;
}
