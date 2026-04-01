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

- Why C++ compilers use xor eax, eax instead of mov eax, 0
- Why do C++ compilers use xor instead of mov to return zero?
- Why xor eax, eax is everywhere in compiled code
- Why does C++ assembly prefer xor over mov for zeroing?
- Why do compilers generate xor eax, eax in C++?
- Why is zeroing a register done with xor in C++?

## References

- ChatGPT and Gemini
