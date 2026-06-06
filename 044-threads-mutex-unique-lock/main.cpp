#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx1;
int counter = 0;

// std::unique_lock

void increment() {
  for (size_t i = 0; i < 10; i++) {
    // std::lock_guard<std::mutex> lock1(mtx1);
    std::unique_lock<std::mutex> ulock1(mtx1);
    counter++;
    cout << "Thread[" << std::this_thread::get_id() << "] counter: " << counter << endl;
    ulock1.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main() {
  std::thread t1(increment);
  std::thread t2(increment);
  t1.join();
  t2.join();
  cout << "=== finished counter: " << counter << endl;
  return 0;
}

// std::unique_lock<std::mutex> ulock1(mtx1, std::defer_lock);
// ulock1.lock();
// ulock1.unlock();

// std::this_thread::sleep_for(std::chrono::milliseconds(50));
