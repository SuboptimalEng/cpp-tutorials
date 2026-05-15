#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx;
int counter = 0;

void increment() {
  // cout << "counter: " << counter << endl;
  for (size_t i = 0; i < 100000; i++) {
    mtx.lock();
    counter++;
    mtx.unlock();
  }
  // cout << "counter: " << counter << endl;
}

int main() {
  for (int i = 0; i < 10000; i++) {
    counter = 0;
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    if (counter < 200000) {
      cout << "counter: " << counter << endl;
    }
  }
  return 0;
}
