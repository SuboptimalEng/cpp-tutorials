## Video Overview

- What is `xorl %eax, %eax` in assembly do?
- `%eax` meaning
  - 32-bit register
  - Used for return values in x86-64 (int return)
- What does `xorl %eax, %eax` do?
  - Sets `%eax` to 0
  - Because x ^ x = 0
- Why not `movl $0x0, %eax`?
  - Uses fewer bytes (compare to `movl`)
  - `xorl` is faster (CPU optimized zeroing idiom)

## Titles

- Todo

## References

- ChatGPT and Gemini
