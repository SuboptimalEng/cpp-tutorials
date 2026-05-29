## Video Overview

- What is a dead lock?
  - 2 threads are stuck waiting for lock held by another thread
- How to prevent dead lock?
  - Don't use multiple locks if possible
  - Use same order of lock/unlock (hard to remember)
    - Show this works with thread/sleep
- How to actually prevent dead lock?
  - Wait for unlocks with `std::lock lock(mtx1, mtx2);`

## Titles

- The 1 Line of C++ That Prevents Mutex Lock Leaks

- Stop Manually Locking and Unlocking Your Mutexes in C++
- The C++ Threading Mistake Senior Engineers See in Seconds

- Never Use .lock() in Modern C++ Multithreading
- The Anatomy of a C++ Lock Leak (and how to fix it)
- Why Manually Locking and Unlocking a C++ Mutex a Bad Idea

## References

- ChatGPT and Gemini
