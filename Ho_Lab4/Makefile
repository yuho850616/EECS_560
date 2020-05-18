lab4: main.o Executive.o Quadratic.o Doublehash.o Hashtable.o LinkedList.o Node.o
		g++ -std=c++11 -g main.o Executive.o Doublehash.o Quadratic.o Hashtable.o LinkedList.o Node.o -o lab4

Node.o: Node.cpp Node.h
		g++ -std=c++11 -g -c Node.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Node.h Node.cpp
		g++ -std=c++11 -g -c LinkedList.cpp

Hashtable.o: Hashtable.cpp Hashtable.h
		g++ -std=c++11 -g -c Hashtable.cpp

Quadratic.o: Quadratic.cpp Quadratic.h
		g++ -std=c++11 -g -c Quadratic.cpp

Doublehash.o: Doublehash.cpp Doublehash.h
		g++ -std=c++11 -g -c Doublehash.cpp

Executive.o: Executive.cpp Executive.h
		g++ -std=c++11 -g -c Executive.cpp

main.o: main.cpp Executive.h
		g++ -std=c++11 -g -c main.cpp

clean:
		rm *.o lab4
