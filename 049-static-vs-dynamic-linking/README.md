## Video Overview

- What is static vs dynamic linking?

- Static
  - Build a library whose code gets copied into the final executable when linking.
  - File formats
    - MacOS - `.a`
    - Linux - `.a`
    - Windows - `.lib`

- Dynamic
  - Build a library that stays as a separate file, and the executable loads it at runtime.
  - File formats
    - MacOS - `.dylib`
    - Linux - `.so` (shared object)
    - Windows - `.dll`

- Static
  libMathLib.a
  |
  +----> App A (copy add())
  +----> App B (copy add())
  +----> App C (copy add())

- Dynamic
  App A ----\
  App B -----+----> libMathLib.dylib
  App C ----/

## Commands

```bash
cmake -S . -B build && cmake --build build
```

```bash
# lldb commands
image list
image lookup --name add
```

## Titles

- Static vs Dynamic Linking

## References

- [cppreference.com](https://cppreference.com/cpp)
- [learncpp.com](https://www.learncpp.com/)
- ChatGPT and Gemini
