## Video Overview

- Go over basic LLDB commands for beginners

## LLDB Commands

```bash
# breakpoint
b main
b add
br list  # list breakpoints
br del 1 # delete bp 1

# start/re-run executable
run

# assembly (vim ~/.lldbinit)
disassemble --pc

# stack
bt

# step through code/assembly
s  # step
si # step instruction
n  # next
ni # next instruction

# print variables
p a
p 1
p 1 + 1

# reading registers
register read
register read rax
p $rax              # shortcut

# examine memory
x $rbp
x/d $rbp-0x4
x/4wx $rsp    # hex words
x/4wd $rsp    # decimal
x/8xb $rsp    # bytes

# instruction pointer
p $rip # register instruction pointer
p $rsp # register stack pointer
p $rbp # register base pointer

# misc
help x
help p
quit
```

## Titles

- LLDB Assembly Debugging Basics: Step, Inspect, and Understand Memory
- Mastering LLDB: p, x, and Stepping Through Assembly (Beginner Guide)
- From C++ to Assembly in LLDB: Registers, Memory, and Step-by-Step Debugging

## References

- ChatGPT and Gemini
