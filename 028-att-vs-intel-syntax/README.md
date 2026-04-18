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

```cpp
-0x8(%rbp) vs [rbp - 0x8]
```

## Titles

- How to make LLDB show Intel syntax instead of AT&T for Assembly?

## References

- ChatGPT and Gemini
