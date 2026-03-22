## Notes on Assembly

Some helpful info on x86 assembly.

## Compiler Commands

```bash
# Show %rsp movement even when it is <120 bytes
clang++ -mno-red-zone -std=c++17 -g main.cpp -o main
```

## LLDB Commands

### Init array info in \_\_data section

```bash

# curr addr + instruction len + assembly value
# 0x100000f3d + 7 + 0x4c

# find memory address of location
p/x (0x100000f3d+0x4c+7)
# (long) 0x0000000100000f90

# Printing values inside rax
(lldb) p/x $rax
# (unsigned long) 0x0000000b00000005 -> 11, 5
(lldb) p/d ((int*)&$rax)[0]
# (int) 5
(lldb) p/d ((int*)&$rax)[1]
# (int) 11
(lldb) register read $rax -f int32
#  rax = {5 11}

# display 5 values at mem location
x/5xd (0x100000f3d+0x4c+7)
# 0x100000f90: 12
# 0x100000f94: 23
# 0x100000f98: 34
# 0x100000f9c: 45
# 0x100000fa0: 56
```

### Basic assembly commands

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
# Set up stack
    0x100000f60 <+0>:  pushq  %rbp
    0x100000f61 <+1>:  movq   %rsp, %rbp
    0x100000f64 <+4>:  subq   $0x20, %rsp
# Add variables to stack
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
# Clean up stack
    0x100000fa1 <+65>: addq   $0x20, %rsp
    0x100000fa5 <+69>: popq   %rbp
    0x100000fa6 <+70>: retq
```
