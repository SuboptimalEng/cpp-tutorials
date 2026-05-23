#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx;
int counter = 0;

void increment() {
  for (size_t i = 0; i < 10000; i++) {
    std::lock_guard<std::mutex> lock(mtx);
    // mtx.lock();
    counter++;
    cout << "counter: " << counter << endl;
    // mtx.unlock();
  }
}

int main() {
  std::thread t1(increment);
  std::thread t2(increment);
  // std::jthread tj1(increment);
  t1.join();
  t2.join();
  cout << "=== finished counter: " << counter << endl;
  return 0;
}
