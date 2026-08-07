#include <iostream>
#include <mutex>

int getRandom() {
  return 9;
}

// Allocated in .bss memory section
static int count_storage = 0;
static bool count_guard = false;
static std::mutex count_mutex;

void MyFn() {
  // Fast path: bypass lock if already initialized
  if (!count_guard) {

    // Slow path: acquire thread-safe lock
    std::lock_guard<std::mutex> lock(count_mutex);

    if (!count_guard) {
      count_storage = getRandom();
      count_guard = true;
    }
  }

  count_storage++;
}

int main() {
  MyFn();
  MyFn();
  MyFn();
  return 0;
}
