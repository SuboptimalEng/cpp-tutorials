all:
	clang++ -std=c++17 -g -O0 main.cpp -o main

debug:
	clang++ -std=c++17 -g -O0 main.cpp -o main && lldb ./main

run:
	clang++ -std=c++17 -g -O0 main.cpp -o main && ./main

clean:
	rm -rf main *.dSYM *.s
