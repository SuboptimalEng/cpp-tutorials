# ===
# Compile main.cpp and link file separately (in 2 steps)
# ===

# This will fail to link since goodbye_world is undefined!
# main:
# 	clang++ main.cpp -o main

# Let's do this in 2 separate steps
main: main.o
	clang++ main.o -o main

main.o:
	clang++ -c main.cpp -o main.o

clean:
	rm -f main main.o
