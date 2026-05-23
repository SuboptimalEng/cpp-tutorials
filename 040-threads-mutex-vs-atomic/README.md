## Video Overview

- Previously, we talked about mutex + data races
  - What exactly is a data race?
  - Why do we have a data race on 1 line of assembly?
- Introduce atomic types which force lock on cpu/hardware level
  - For programmer, it's 1 op, for CPU, it's still 3 ops!
  - Macro ops (assembly) vs Micro ops (CPU)
- How to use std::atomic?
  - Overloading is available
  - Go over various functions
    - `counter.fetch_add(1);`
- Complex data types
  - Can be used with built-in types and structs (but be careful)
  - Check with `std::atomic<Point>::is_always_lock_free`
- TL;DR
  - Mutex = "software" lock
    - OS needs to schedule
    - 500 - 2,000 nanoseconds
  - Atomic = "hardware" lock
    - CPU does the work
    - 10 - 50 nanoseconds

## Titles

- Why "Atomic Lock-Free" C++ Code Still Locks Your CPU
- Why a CPU Level Lock is 100x Faster Than an OS Mutex
- Why a C++ Mutex Lock Costs Your CPU 5,000 Clock Cycles
- C++ Mutex (OS) vs Atomics (CPU) Explained for Absolute Beginners

- C++ Mutex vs Atomic Explained
- What Actually Happens to a CPU During a std::atomic Operation

## References

- ChatGPT and Gemini
