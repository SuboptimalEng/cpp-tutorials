# UB - Uninitialized Local Variable

## TL;DR

- How to count the number of bits set to 1 for a number using bit manipulation?

## LLDB Commands

```bash
# print binary
p/t 8

# print binary with less chars
p/t (uint8_t)8

# bit shift right >>
p/t (uint8_t)(8 >> 1)
p/t (uint8_t)(8 >> 2)
p/t (uint8_t)(8 >> 3)

# bitwise &
p/t (uint_t)(0 & 1)
p/t (uint_t)(1 & 1)
p/t (uint_t)(8 & 8)
p/t (uint_t)(8 & 1)
p/t (uint_t)(9 & 1)
```

## Titles

- How to Count Bits with Bit Manipulation | C++ Tutorial
- How to Count Bits with Bit Manipulation in C++ | C++ Tutorial
- Counting Bits in C++ with Bit Manipulation | C++ Tutorial
- Bit Manipulation Interview Question | C++ Tutorial
- Bit Manipulation is Easy | C++ Tutorial

## References

- ChatGPT and Gemini
