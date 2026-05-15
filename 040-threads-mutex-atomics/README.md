## Video Overview

- Previously, we talked about mutex + data races
- What exactly is a data race?
  - Read unoptimized assembly code
- Why do we have a data race on 1 line of assembly?
  - Read optimized assembly code
- Introduce atomic types which force lock on cpu/hardware level
  - Bus/cache lock
- TL;DR
  - Mutex = "software" lock
    - OS needs to schedule
    - 500 - 2,000 nanoseconds
  - Atomic = "hardware" lock
    - CPU does the work
    - 10 - 50 nanoseconds

## Titles

- What is a C++ Mutex and How Does it?

## References

- ChatGPT and Gemini
