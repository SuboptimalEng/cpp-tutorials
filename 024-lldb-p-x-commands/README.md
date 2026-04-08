## Video Overview

- 2 of the most common commands you will use when debugging with lldb
  - `p` (print)
  - `x` (examine)

- `p` (everything high-level)
  - locals: `p a`
  - expressions: `p a + b`
  - registers: `register read eax` -> `p $eax`

- formatting
  - hex: `p/x a + b`
  - decimal: `p/d a`

- `x` (examine raw memory)
  - instructions: `x/i $rip`
  - relative addressing: `x $rbp-0x10`
  - with format: `x/wd $rbp-0x10`
  - multiple values: `x/3wd $rbp-0x10`

## Titles

- The Only 2 LLDB Commands You Need To Debug C++: Print vs Examine
- The Only 2 Commands You Need To Debug C++: Print vs Examine
- What’s the 80/20 Rule for Debugging C++ in LLDB?

- The 80/20 Rule to Debug C++ in LLDB
- The 80/20 Rule for Debugging C++ in LLDB
- Debug C++ 80% Faster with These 2 LLDB Commands
- The Only 2 Commands You Need To Debug C++: Print (p) vs Examine (x)
- The Only 2 LLDB Commands You Need To Debug C++: Print (p) vs Examine (x)
- C++ LLDB Debugging Basics: Print vs Examine Memory

## References

- ChatGPT and Gemini
