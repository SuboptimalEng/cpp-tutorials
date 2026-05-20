#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::atomic<int> counter(0);

// std::mutex mtx;
// int counter = 0;

void increment() {
  for (size_t i = 0; i < 100000; i++) {
    // mtx.lock();
    counter++;
    // counter.fetch_add(1);
    // counter.fetch_add(1);
    // mtx.unlock();
  }
}

int main() {
  std::thread t1(increment);
  std::thread t2(increment);
  t1.join();
  t2.join();
  cout << "counter: " << counter << endl;
  // cout << "counter: " << counter.load() << endl;
  return 0;
}

// Check if it's lock free at on CPU at compile time, because sometimes, it's
// uses a mutex behind the scenes.
struct Point {
  int x;
  int y;
};

// Check at compile-time if a type is natively lock-free on your target CPU
static_assert(std::atomic<Point>::is_always_lock_free);
