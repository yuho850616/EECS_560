lab3: main.o Executive.o Quadratic.o Doublehash.o
		g++ -std=c++11 -g main.o Executive.o Quadratic.o Doublehash.o -o lab3

main.o: main.cpp Quadratic.h Quadratic.cpp Doublehash.h Executive.h
		g++ -std=c++11 -g -c main.cpp

Quadratic.o: Quadratic.cpp
		g++ -std=c++11 -g -c Quadratic.cpp

Doublehash.o: Doublehash.cpp Doublehash.h Quadratic.h
		g++ -std=c++11 -g -c Doublehash.cpp

Executive.o: Executive.h Executive.cpp Doublehash.h Doublehash.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o lab3
