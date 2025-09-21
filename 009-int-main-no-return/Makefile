# generate c++17 ast, llvm ir, assembly, and debuggable main executable
all:
	clang++ -std=c++17 -Xclang -ast-dump -fsyntax-only main.cpp > main.ast && \
	clang++ -std=c++17 -S -emit-llvm main.cpp -o main.ll && \
	clang++ -std=c++17 -S main.cpp -o main.s && \
	clang++ -std=c++17 -g main.cpp -o main

clean:
	rm -rf main.dSYM main main.ast main.ll main.s