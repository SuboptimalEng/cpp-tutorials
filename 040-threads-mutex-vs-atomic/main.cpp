#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::atomic<int> counter(0);

// std::mutex mtx;
// int counter = 0;

void increment() {
  for (size_t i = 0; i < 10000; i++) {
    // mtx.lock();
    counter++;
    // mtx.unlock();
    // counter.fetch_add(1);
  }
}

int main() {
  // auto start = std::chrono::high_resolution_clock::now();
  std::thread t1(increment);
  std::thread t2(increment);
  // std::thread t3(increment);
  // std::thread t4(increment);
  t1.join();
  t2.join();
  // t3.join();
  // t4.join();
  // auto end = std::chrono::high_resolution_clock::now();
  // std::chrono::duration<double, std::milli> elapsed = end - start;

  cout << "counter: " << counter << endl;
  // cout << "function took: " << elapsed.count() << " ms" << endl;
  // cout << "counter: " << counter.load() << endl;
  return 0;
}

// // Check if it's lock free at on CPU at compile time, because sometimes, it's
// // uses a mutex behind the scenes.
// struct Point {
//   int x;
//   int y;
// };
// // Check at compile-time if a type is natively lock-free on your target CPU
// static_assert(std::atomic<Point>::is_always_lock_free);
