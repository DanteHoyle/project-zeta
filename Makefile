default: build/main.o build/gameState.o
	g++ build/main.o build/gameState.o -o build/zeta -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o

build/gameState.o: src/gameState.cpp
	g++ -c src/gameState.cpp -o build/gameState.o
