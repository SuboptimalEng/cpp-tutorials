// #include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex counter_mtx;
int counter = 0;

void increment_counter() {
  counter_mtx.lock();
  for (size_t i = 0; i < 1000000; i++) {
    counter++;
  }
  counter_mtx.unlock();
}

int main() {
  // cout << "start count: " << counter << endl;
  // std::thread t1(increment_counter);
  // std::thread t2(increment_counter);
  // t1.join();
  // t2.join();
  // cout << "end count: " << counter << endl;

  cout << "start count: " << counter << endl;
  auto start = std::chrono::high_resolution_clock::now();
  std::thread t1(increment_counter);
  std::thread t2(increment_counter);
  t1.join();
  t2.join();
  auto end = std::chrono::high_resolution_clock::now();
  cout << "end count: " << counter << endl;
  std::chrono::duration<double, std::milli> elapsed = end - start;
  cout << "Function took: " << elapsed.count() << " ms" << endl;

  return 0;
}
