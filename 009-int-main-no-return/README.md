# No `return 0;` in `int main()`

## Overview

- I would always write `return 0;` inside the `int main()` function because I thought it was required
- This may have been a force of habit from learning C in a computer architecture course in college
- Turns out that `return 0;` is optional (and not required in `int main()`)
- The following code (with no return statement in the main function) will compile and run correctly
- In order to investigate why, we need to understand the compiler. (In this case Clang.)

```cpp
int main() {
  int a = 123;
}
```

## Compiler Steps

The compiler steps:

1. C++ (source code)
2. AST (clang frontend)
3. IR (intermediate representation) -> happens in this stage
4. Assembly
5. Binary/Executable

The compiler steps in-depth (thanks ChatGPT):

1. C++ Source Code → your .cpp text file.
2. AST (Abstract Syntax Tree) → Clang frontend parses the source into a tree of functions, variables, statements, etc.
3. IR (LLVM Intermediate Representation) → platform-independent SSA-like code for optimizations.
4. Assembly → CPU-specific instructions (.s).
5. Binary / Executable → linked machine code you can run (a.out or your program).

## Why?

Why is `return 0;` optional in `int main()`?

- Many C compilers would `return 0;` by default
  - GCC, MSVC did this because OS expected return value
- It would be undefined behavior in C++ otherwise
  - This is one of biggest concerns for C++ in this day
  - So much so that US govt asking companies to use safe languages
- Was standardized in C++11
  - But C++ compilers basically did this before that

## References

- ChatGPT and Gemini (if these count)
