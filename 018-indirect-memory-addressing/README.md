## TL;DR

- What does `0x8(%rbp)` mean in `movl   $0x1, -0x8(%rbp)`?

## Video Overview

- Go over C++ code
- What is the parenthesis operation do?
- `%rbp` represents the current function's stack frame
- Indirect memory addressing in assembly

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

## Sample Assembly Code

```bash
main`main:
    0x100000f60 <+0>:  pushq  %rbp
    0x100000f61 <+1>:  movq   %rsp, %rbp
    0x100000f64 <+4>:  subq   $0x20, %rsp
    0x100000f68 <+8>:  movl   $0x0, -0x4(%rbp)
->  0x100000f6f <+15>: movl   $0x1, -0x8(%rbp)
    0x100000f76 <+22>: movl   $0x2, -0xc(%rbp)
    0x100000f7d <+29>: movl   $0x3, -0x10(%rbp)
    0x100000f84 <+36>: movl   $0x4, -0x14(%rbp)
    0x100000f8b <+43>: movl   -0x8(%rbp), %edi
    0x100000f8e <+46>: movl   -0xc(%rbp), %esi
    0x100000f91 <+49>: movl   -0x10(%rbp), %edx
    0x100000f94 <+52>: movl   -0x14(%rbp), %ecx
    0x100000f97 <+55>: callq  0x100000f20    ; sum_4 at main.cpp:3
    0x100000f9c <+60>: movl   %eax, -0x18(%rbp)
    0x100000f9f <+63>: xorl   %eax, %eax
    0x100000fa1 <+65>: addq   $0x20, %rsp
    0x100000fa5 <+69>: popq   %rbp
    0x100000fa6 <+70>: retq
```

## Titles

- What is Indirect Memory Addressing? | C++ Tutorial
- x86 Assembly Memory Offsets Explained | C++ Tutorial

- How does C++ store variable data on the stack frame?
- C++ Deep Dive: Indirect Memory Addressing Explained
- C++ Deep Dive: Indirect Memory Addressing from Stack Base Pointer
- How to Read x86 Assembly Memory Offsets? | C++ Tutorial for Beginners
- Assembly Tutorial: What Does -0x8(%rbp) Mean?

## Description

In this C++ tutorial, we go over the parenthesis operation in assembly, which is known as indirect memory addressing. We also learn about the RBP stack frame and access its values using various LLDB debugger commands.

## References

- ChatGPT and Gemini
