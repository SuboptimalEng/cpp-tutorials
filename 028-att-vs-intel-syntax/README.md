## Video Overview

- AT&T syntax (fewer people like this approach)
- Intel syntax (easier to read, compiler explorer)
- Add this to `vim ~/.lldbinit`
  - `settings set target.x86-disassembly-flavor intel`

- At&t
  - Order: src, dst
  - Registers: `%eax` (percent symbol)
  - Memory addressing: `$0x0, -0x8(%rbp)`
- Intel
  - Order: dst, src
  - Registers: `eax` (no percent symbol)
  - Memory addressing: `dword ptr [rbp - 0x8], 0x0`

<!-- ```cpp
// thumbnail 1
-0x8(%rbp) vs [rbp - 0x8]
// thumbnail 2
  💀 -0x8(%rbp)
  ️️❤️ [rbp - 0x8]
``` -->

## Titles

- The First Thing You Should Change in LLDB
- The First Thing You Should Change in LLDB (AT&T vs Intel Syntax)
- Stop Using the Default LLDB Syntax
- Stop Using the Default LLDB Syntax (AT&T vs Intel)
- Why Your Assembly Looks Weird (and How to Fix It)
- How to make LLDB show Intel syntax instead of AT&T and why?
- AT&T vs Intel Syntax: Which Assembly Flavor Do You Prefer?

## References

- ChatGPT and Gemini
