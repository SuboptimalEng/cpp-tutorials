## Video Overview

- Pros
  - Space efficient
    - Uses 1 bit for element instead of 8 bits (or 1 byte)
    - 8x less RAM than bool or char on heap
  - Cache friendly
    - Can fit more data into the CPU cache, speeding up massive scans

- Cons
  - Not a true container (requires proxy)
    - Holds bits, not `bool`s
    - Can't do `bool*` or `bool&`
  - Broken `auto`
    - `auto a = v[0]` gives proxy object reference (not `bool`)
    - Can lead to use-after-free bugs
  - Slower access
    - Read/write requires CPU to perform bit-shifting math and masking
    - Slower than reading bytes directly
  - Thread safety
    - Writing to two diff indices `0`, and `1` is not thread safe (share same byte)

- Why is C++ like this?
  - In the 90s, RAM was incredibly expensive (AI as well in 2026?)
  - The committee wanted to show off that C++ could do "invisible optimizations."
  - Lots of debate around this...

- Unfortunately
  - This container has been confusing developers for 30 years
  - Use `std::vector<char>` if you want a real container

## Titles

- In C++, a vector of bools is a vector of bools... right?
- In C++, a vector of bools is a vector of bools, right?
- A vector of bools is a vector of bools... right? | C++ Deep Dive
- A vector of bools is a vector of bools, right? | C++ Deep Dive

## References

- ChatGPT and Gemini
