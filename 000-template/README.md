# UB - Uninitialized Local Variable

## TL;DR

- In the C++ on Sea keynote, Herb Sutter showed some code with undefined behavior in C++
- Turns out that C++ can have UB when reading a local variable that is uninitalized
- I was confused by this and decided to investigate further by looking into the assembly code
- The point of this investigation is to learn what's happening under the hood in the compiler
- (Note that this issue will be fixed by default in C++ 26 which is great!)

## Video Overview

- Start by recreating the C++ code from Herb's slide
- Go over the C++ code and explain what we expect to happen vs what actually happens
- Run the code to ensure the undefined behavior (as expected :P)
- Turn on `ftrivial-auto-var-init=zero` flag and confirm that UB is NOT there anymore
  - This flag basically ensures that
  - These flags are default to true in C++ 26
  - So we can expect them to be gone with no code changes in the future
- Investigate the assembly for UB code
- Investigate the assembly diff for non-UB code

## Helpful LLDB Commands

## Sample Assembly Code

## Titles

## References

- Herb Sutter's Keynote at C++ on Sea - https://www.youtube.com/watch?v=kKbT0Vg3ISw
- Herb Sutter's Website - https://herbsutter.com/
- ChatGPT and Gemini
