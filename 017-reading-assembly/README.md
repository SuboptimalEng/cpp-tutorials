## TL;DR

- Understanding the basics of assembly code

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

```bash
# Create debuggable executable
clang++ -g main.cpp -o main

# Run lldb
lldb ./main

b main # Breakpoint
n # Next
ni # Next instruction
s # Step into
si # Step into instruction

p $edi # print value in edi
x/2d $rbp-0x8 # examine 2 ints in rbp


```

## Titles

- Intro to Assembly Code | C++ LLDB Tutorial
- How to Read C++ Assembly Code
- Step-by-Step x86-64 Assembly Guide
- C++ to Assembly Tutorial for Beginners

## Timestamps

- 00:00 Todo

## References

- ChatGPT and Gemini
