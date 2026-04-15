## Video Overview

- What data type to use for timestamps?
  - int?
  - int32_t?
  - uint64_t?
  - int64_t?

- Why not `int32_t`?
  - Overflow in January 19th, 2038
    - Similar to `y2k` (dates went from `99` to `00`)
    - Cost $300B - 600B to update legacy systems
  - `int64_t` provides a range of 292 billion years

- Why used `signed` instead of `unsigned`?
  - Prevent underflow
    - Handles negative nums from clock jitter (Time A - Time B)
    - Crashes when unsigned integer wraps around to `18.4` quintillion)
  - Historical dates
    - Unsigned types are strictly limited to the future.
    - Represent time before the Unix Epoch (January 1, 1970)

## Titles

- The 2038 Bug: Why int64_t is the Only Safe Choice in C++
- Why Time is Always Signed: The 292 Billion Year Answer
- The C++ Interview Question That Tricked Me (Data Types)

- Modern C++: Picking the Right Type Every Time
- How a Single unsigned int Can Crash Your Code
- size_t vs int: Avoiding the Silent C++ Gotcha
- Never Use uint64_t for Timestamps (Here’s Why)
- Level Up Your C++: The Art of Integer Selection

## References

- ChatGPT and Gemini
