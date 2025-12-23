all:
# 	clang++ -std=c++17 main-01.cpp InlineClass.cpp -o main-01 --save-temps
# 	clang++ -std=c++17 main-02.cpp InlineClass.cpp -o main-02 --save-temps
	clang++ -std=c++17 -S main-01.cpp
	clang++ -std=c++17 -S main-02.cpp
	clang++ -std=c++17 -S main-03.cpp
	clang++ -std=c++17 main-01.cpp -o main-01
	clang++ -std=c++17 main-02.cpp -o main-02
	clang++ -std=c++17 main-03.cpp -o main-03
# 	clang++ -std=c++17 -S main-02.cpp -o main
# 	clang++ -std=c++17 -S main-03.cpp -o main
# 	clang++ -std=c++17 main-01.cpp

clean:
	rm -rf main-01 main-02 main-03 *.dSYM *.o *.s *.bc *.ii
