all:
# 	clang++ -std=c++17 main.cpp SeparateHeader.cpp -o main --save-temps
	clang++ -std=c++17 -S main.cpp SeparateHeader.cpp
	clang++ -std=c++17 main.cpp SeparateHeader.cpp -o main

clean:
	rm -rf main *.dSYM *.o *.s *.bc *.ii
