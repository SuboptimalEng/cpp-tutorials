# --- TITLE ---

## TL;DR

- How to set up and run the C++ debugger in VS Code

## Video Overview

- Go over C++ code
- Debugging basics
  - `clang++ -g main.cpp -o main`
  - `si` - step into instruction
  - `p $edi` - print value in edi
  - `x/2d $rbp-0x8` - examine 2 ints in rbp
- Reading assembly
  - `0x100000f60 <+0>...`
  - `movl   %edi, -0x8(%rbp)`
  - `addl   -0x8(%rbp), %eax`
  - `callq  0x100000ed0`

## Helpful LLDB Commands

## Sample Assembly Code

## Titles

- Intro to Debugging C++ in VS Code
- How to Debug C++ in VS Code

## Timestamps

- 00:00 Todo

## References

- Herb Sutter's Website - https://herbsutter.com/
- ChatGPT and Gemini
