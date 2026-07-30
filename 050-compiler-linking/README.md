## Video Overview

- Compiler phases (high-level)
  - Preprocessor -> copy-paste include file code
  - Assembler -> convert to assembly
  - Linker -> links them together... but wtf does that mean?

- Linker combines multiple object files (.o) into a single executable by doing two main things:
  - Merges separate assembly code blocks (.text sections) into one file.
  - Fills in the actual memory addresses for function calls (like main() calling a function in math.o) so the CPU knows where to jump.

- Edgecases: Order of obj files sent to linker matters when using
  - Static libraries
  - Two libraries have fns with same name
  - There exists circular deps between libraries
  - But that's outside the scope of this video :)

## Commands

```bash
# -o = name of output file
# -g = debug with lldb (useful later)
# -c = compile only and skip linker
clang++ -std=c++17 -g -c math.cpp -o math.o
clang++ -std=c++17 -g -c main.cpp -o main.o

# -d = disassemble
# -S = show source code alongside assembly
objdump -d -S math.o
objdump -d -S main.o

# linking main.o and math.o into main executable
clang++ main.o math.o -o main

# does the order matter?
clang++ math.o main.o -o main
```

## Titles

- What exactly does the C++ linker do?
- How does the C++ compiler's linker work?

## References

- [cppreference.com](https://cppreference.com/cpp)
- [learncpp.com](https://www.learncpp.com/)
- ChatGPT and Gemini
