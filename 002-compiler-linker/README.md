# TCPPL Question Reference

## X.3 A Tour of C++: The Basics

- [2] (∗1) What does a compiler do? What does a linker do?

## Answer

The compiler (clang, gcc, etc.) essentially converts .cpp files to .o
files. This basically converts plain C++ into machine code. But they are
not ready for use yet!

The linker needs to combine the .o files together and make an executable.

Note that the compiler is technically responsible for compiling the code
and also for linking it. The main takeaway is that they are run as 2
separate steps internally. And we can simulate this when testing.

Why do these exist in 2 phases?

- It's faster. We don't want to recompile 100s of C++ files if we
  only change the main.cpp file.
- Parallel! Each C++ file can be compiled individually.
