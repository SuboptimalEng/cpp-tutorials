/*

I was watching a video from Core Dumped where Jorge explained how the
compiler is a toolchain which performs multiple steps like the pre-
processor, creating assembly, creating object files, and linking them.

I wanted to see what that looked like, so here we are.

===========================================================================

Thanks, ChatGPT :)

clang++ -o main main.cpp add.cpp

main.cpp
   ↓          [Preprocessor: expands macros, includes headers]

main.ii       (.ii = preprocessed source)
   ↓          [Frontend: parses C++ into AST]

main.bc       (.bc = LLVM Bitcode, generated with -emit-llvm)
   ↓          [LLVM passes: optimization, transformation]

main.s        (.s = Assembly code, target-specific)
   ↓          [Assembler: turns .s into object file]

main.o        (.o = Object file)
   ↓          [Linker: combines object files into executable]

main          (executable)



===========================================================================

How to generate intermediary files individually?

// pre-processor
clang++ -E main.cpp -o main.ii

// llvm bitcode
clang++ -emit-llvm -c main.cpp -o main.bc

// assembly
clang++ -S main.cpp -o main.s

// object files
clang++ -c add.cpp -o add.o
clang++ -c main.cpp -o main.o

// final step
clang++ main.o add.o -o main

===========================================================================

How to generate intermediary files at once?

clang++ -save-temps -o main main.cpp add.cpp

 */

#include <iostream>
#include "add.h"

int main() {
  int c = add(1, 2);
  std::cout << "hello world!" << c << std::endl;
  return 0;
}
