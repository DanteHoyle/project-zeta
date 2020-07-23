default: main.o
	g++ main.o -lsfml-graphics -lsfml-window -lsfml-system -o zeta

main.o: src/main.cpp
	g++ -c src/main.cpp -o main.o

clean:
	rm *.o