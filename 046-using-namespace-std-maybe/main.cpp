#include <functional>
#include <iostream>
#include <thread>

using namespace std;

void increment(int& counter) {
  for (int i = 0; i < 100; i++) {
    counter++;
  }
  cout << "from thread -> " << counter << endl;
}

int main() {
  int counter = 0;
  std::thread t1(increment, counter);
  // t1.join();
  t1.detach();
  cout << "from main -> " << counter << endl;
  return 0;
}
