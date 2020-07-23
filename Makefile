default: build/main.o
	g++ build/main.o -lsfml-graphics -lsfml-window -lsfml-system -o build/zeta

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o
