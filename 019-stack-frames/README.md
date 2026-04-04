## TL;DR

- How does the C++ function stack work?
- What are `%rbp` and `%rsp`?

## Video Overview

- `%rbp` - register base pointer (starting point of stack for current fn)
- `%rsp` - register stack pointer (end point of stack for current fn)
- `clang++ -g -mno-red-zone main.cpp -o main`
  - `-mno-red-zone` to prevent `%rsp` compiler optimization

## Helpful LLDB Commands

```bash
(lldb) p/x $rbp
# (unsigned long) 0x00007ff7bfefec40

(lldb) x/x $rbp-0x8
# 0x7ff7bfefec38: 0x00000001

(lldb) x/4xd $rbp-0x14
# 0x7ff7bfefec2c: 4
# 0x7ff7bfefec30: 3
# 0x7ff7bfefec34: 2
# 0x7ff7bfefec38: 1
```

## Titles

- How do C++ stack frames work anyway?
- C++ Internals: How %rbp and %rsp Manage the Function Stack Frame
- C++ Stack Frame Setup and Teardown Explained
- How do stack frames work in C++?
- How does the Stack Frame work in C++?

- How is the stack frame initialized for fn calls in C++?
- What is the C++ Stack Frame and how does it work?
- C++ Deep Dive: Function Stack Frames
- What is a Stack Frame in C++?
- C++ Stack Frames Explained (rbp vs rsp in x86 assembly)

## References

- ChatGPT and Gemini
