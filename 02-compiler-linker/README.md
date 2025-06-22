# TCPPL Question Reference

#### X.3 A Tour of C++: The Basics

- [2] (∗1) What does a compiler do? What does a linker do?

# Answer

The compiler essentially converts .cpp files to .o files. This basically
converts plain C++ files into machine code. But they are not ready for
use yet!

The linker needs to combine the .o files together and make an executable.

Why do these exist in 2 phases?

- It's faster. We don't want to recompile 100s of C++ files if we
  only change the main.cpp file.
- Parallel! Each C++ file can be compiled individually.

Funnily enough, the compiler compiles the code and links it too! Which was
surprising to me at first, but makes sense when you look at a make file.

```bash
# this compiles main.cpp into main.o and then creates the main executable
main:
  clang++ main.cpp -o main

clean:
  rm -f main
```
