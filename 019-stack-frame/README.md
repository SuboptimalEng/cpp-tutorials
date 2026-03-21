## Video Overview

- Previously in `19-stack-frame`
  - How does the C++ function stack frame work?
  - `%rbp` - register base pointer (starting point of stack for current fn)
  - `%rsp` - register stack pointer (end point of stack for current fn)

- What is Red Zone?
  - Low-level compiler optimization to save a few CPU cycles
    - Avoids using `subq $0x14 %rsp`
  - Red Zone is 128 bytes (`0x80`) below `$rsp` that is auto accessible by leaf node functions
    - Fns that don't call other fns
  - Available for x86-64 on MacOS and Linux(?), but is absent on Windows

- So how do you disable the compiler optimization?
  - `-mno-red-zone` flag to prevent `%rsp` compiler optimization
  - By default, `%rsp` is already moved by `0x80` bytes!

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

- x86 Assembly Stack Frames Explained | C++ Tutorial
- How the C++ Stack Frame Works | x86 Assembly Explained
- C++ Internals: How %rbp and %rsp Manage the Function Stack Frame
- C++ Stack Frames Explained (rbp vs rsp in x86 assembly)
- What Are rbp and rsp? Understanding the C++ Function Stack
- The Anatomy of a C++ Function Call (%rbp & %rsp)
- Stop Guessing: How the C++ Stack Actually Works

## References

- ChatGPT and Gemini
