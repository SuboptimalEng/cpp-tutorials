# UB - Uninitialized Local Variable

## TL;DR

- In the C++ on Sea keynote, Herb Sutter showed some code with undefined behavior in C++
- Turns out that C++ can have UB when reading a local variable that is uninitalized
- I was confused by this and decided to investigate further by looking into the assembly code
- The point of this investigation is to learn what's happening under the hood in the compiler
- (Note that this issue will be fixed by default in C++ 26 which is great!)

## Video Overview

- Start by recreating the C++ code from Herb's slide
- Go over the C++ code and explain what we expect to happen vs what actually happens
- Run the code to ensure the undefined behavior (as expected :P)
- Turn on `ftrivial-auto-var-init=zero` flag and confirm that UB is NOT there anymore
  - This flag basically ensures that
  - These flags are default to true in C++ 26
  - So we can expect them to be gone with no code changes in the future
- Investigate the assembly for UB code
- Investigate the assembly diff for non-UB code

## Helpful LLDB Commands

- General lldb commands that are useful

```bash
# the following hook will allow you to see assembly + code every time
# you step into or go to next line
target stop-hook add
disassemble
DONE

# step into
si

# next instruction
ni

# print hex as character
p (char)0x68
p (char)0x69
```

- Useful lldb commands specifically for this code snippet

```bash
# examine 7 bytes, at rbp (notice the $ sign)
x/7xb $rbp

# need to inspect 7 bytes at rbp starting at rbp-7
x/7xb $rbp-0x7 # 0x7ff7bfefea89: 0x73 0x65 0x63 0x72 0x65 0x74 0x00
x/7cb $rbp-0x7 # 0x7ff7bfefea89: secret\0
x/4cb $rbp-0x7 # 0x7ff7bfefea89: secr
x/1cb $rbp-0x2 # 0x7ff7bfefea8e: 't'
x/s $rbp-0x7 # 0x7ff7bfefea89: "secret"
```

## Sample Assembly Code

```bash
main`f1:
    0x100001250 <+0>:  pushq  %rbp
    0x100001251 <+1>:  movq   %rsp, %rbp
    0x100001254 <+4>:  movl   0xcee(%rip), %eax ; "secret"
    0x10000125a <+10>: movl   %eax, -0x7(%rbp)
    0x10000125d <+13>: movw   0xce8(%rip), %ax ; "et"
    0x100001264 <+20>: movw   %ax, -0x3(%rbp)
    0x100001268 <+24>: movb   0xce0(%rip), %al ; ""
    0x10000126e <+30>: movb   %al, -0x1(%rbp)
    0x100001271 <+33>: popq   %rbp
->  0x100001272 <+34>: retq
# Process 4758 stopped
```

## Titles

- How C++ 26 Fixes Undefined Behavior for Unintialized Local Variables
- How C++ Prevents Undefined Behavior for Uninitialized Local Variables

## References

- Herb Sutter's Keynote at C++ on Sea - https://www.youtube.com/watch?v=kKbT0Vg3ISw
- Herb Sutter's Website - https://herbsutter.com/
- ChatGPT and Gemini (if these count)
