all:
	clang++ -std=c++17 -g -O0 main.cpp -o main

run:
	clang++ -std=c++17 -g -O0 main.cpp -o main && ./main

debug:
	clang++ -std=c++17 -g -O0 main.cpp -o main && lldb ./main

clean:
	rm -rf main *.dSYM *.s
