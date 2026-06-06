#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;

void producer() {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  {
    std::lock_guard<std::mutex> lock(mtx);
    data_queue.push(10);
    cout << "Producer pushed 10 into the queue." << endl;
  }
  cv.notify_one();
}

// std::unique_lock

void consumer() {
  std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
  cout << "Consumer has started..." << endl;
  cv.wait(lock, [] { return !data_queue.empty(); });

  int data = data_queue.front();
  data_queue.pop();

  cout << "Consumer pulled from the queue: " << data << endl;
}

int main() {
  std::thread t2(consumer);
  std::thread t1(producer);

  t1.join();
  t2.join();
  return 0;
}
