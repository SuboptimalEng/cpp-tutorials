## Video Overview

- Interview “signal” matters
  - `assert` > `std::cout`

- What is `assert`?
  - `#include <cassert>`
  - `assert(add(2, 3) == 5);`
  - True → nothing
  - False → crash + line number

- How to disable assert?
  - Compile with `-DNDEBUG` or `#define NDEBUG`
  - Asserts removed (zero cost)

- Why it’s useful in interviews
  - Fewer chars!
  - Faster to debug - no manual checking (vs cout)
  - Shows correctness mindset (seniority)

## Titles

- How do you show "signal" in C++ coding interviews?
- C++ assert vs cout: Which Should You Use for Interviews?

- This C++ Code Change Makes You Look Like a Senior Engineer
- The Best Way to Add "Tests" for C++ Code in Interviews

## References

- ChatGPT and Gemini
