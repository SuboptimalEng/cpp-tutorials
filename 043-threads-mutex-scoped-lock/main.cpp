#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx1;
std::mutex mtx2;
int counter = 0;

// 💀 std::lock_guard
// 😒 std::lock
// 🤌 std::scoped_lock

void increment1() {
  for (size_t i = 0; i < 1000; i++) {
    std::scoped_lock lock(mtx1, mtx2);
    // std::lock(mtx1, mtx2);
    // std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    // std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    counter++;
    cout << "counter: " << counter << endl;
  }
}

void increment2() {
  for (size_t i = 0; i < 1000; i++) {
    std::scoped_lock lock(mtx1, mtx2);
    // std::lock(mtx1, mtx2);
    // std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    // std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    counter++;
    cout << "counter: " << counter << endl;
  }
}

int main() {
  std::thread t1(increment1);
  std::thread t2(increment2);
  t1.join();
  t2.join();
  cout << "=== finished counter: " << counter << endl;
  return 0;
}

// std::this_thread::sleep_for(std::chrono::milliseconds(50));
