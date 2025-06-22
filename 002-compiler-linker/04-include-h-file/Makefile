# ===
# Compile main.cpp and link file separately (in 2 steps)
# ===

# Linking will fail until we fix the goodbye_world function.
main: helper-utils.o main.o
	clang++ helper-utils.o main.o -o main

# Compiling works
main.o: main.cpp
	clang++ -c main.cpp -o main.o

# Compiling works
helper-utils.o: helper-utils.cpp
	clang++ -c helper-utils.cpp -o helper-utils.o

clean:
	rm -f helper-utils.o main.o main