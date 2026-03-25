## Video Overview

- Intro to debugging C++ with LLDB

## Note

- This video is similar to `001-gdb-lldb-debugging`
- Wanted to remake the video since that video is old
- And I made it just as I was starting to learn C++

## LLDB Commands

```bash
# start/re-run executable
run

# lldb settings
# assembly (vim ~/.lldbinit)
disassemble --pc

# breakpoint
b main
b add
br list  # list breakpoints
br del 1 # delete bp 1


# step through code/assembly
n  # next line
s  # step into
ni # next instruction
si # step into instruction

# print variables
p a
p 1
p 1 + 1

# reading registers
register read
register read rax
p $rax              # shortcut

# examine memory
# Format: x/[count][format][size] address
# Formats: x (hex), d (decimal), c (char), i (instruction)
# Sizes: b (byte), h (half-word), w (word/4b), g (giant/8b)
x $rbp
x/d $rbp-0x4
x/4wx $rsp    # hex words
x/4wd $rsp    # decimal
x/8xb $rsp    # bytes

# misc
help p
quit
```

## Titles

- How to Debug C++ with LLDB | C++ Tutorial for Beginners
- LLDB Assembly Debugging Basics: Step, Inspect, and Understand Memory
- Mastering LLDB: p, x, and Stepping Through Assembly (Beginner Guide)
- From C++ to Assembly in LLDB: Registers, Memory, and Step-by-Step Debugging

## References

- ChatGPT and Gemini
