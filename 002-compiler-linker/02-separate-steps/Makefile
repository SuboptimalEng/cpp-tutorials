# ===
# Compile main.cpp and link file separately (in 2 steps)
# ===

# This tells the compiler to link the code and create executable.
main:
	clang++ main.o -o main

# -c flag tells compiler to only compile the code.
main.o:
	clang++ -c main.cpp -o main.o

# Clean all files from directory.
clean:
	rm -f main.o main
