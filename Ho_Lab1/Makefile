ex1: main.o Executive.o LinkedList.o Node.o
		g++ -std=c++11 -g main.o Executive.o LinkedList.o Node.o -o ex1

main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp
		g++ -std=c++11 -g -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c LinkedList.cpp

Node.o: Node.cpp
		g++ -std=c++11 -g -c Node.cpp

Executive.o: Executive.h Executive.cpp LinkedList.h LinkedList.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o ex1
