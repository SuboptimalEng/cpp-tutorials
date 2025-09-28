v1-broken:
	clang++ -std=c++17 -g -O0 main.cpp -o main

v2-fixed:
	clang++ -std=c++17 -ftrivial-auto-var-init=zero -g -O0 main.cpp -o main

clean:
	rm -rf main *.dSYM
