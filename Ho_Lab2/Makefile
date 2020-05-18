lab2: main.o Executive.o LinkedList.o Node.o Hashtable.o
		g++ -std=c++11 -g main.o Executive.o LinkedList.o Node.o Hashtable.o -o lab2

main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp Hashtable.h Executive.h
		g++ -std=c++11 -g -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c LinkedList.cpp

Node.o: Node.cpp
		g++ -std=c++11 -g -c Node.cpp

Hashtable.o: Hashtable.cpp Hashtable.h LinkedList.h Node.h
		g++ -std=c++11 -g -c Hashtable.cpp

Executive.o: Executive.h Executive.cpp LinkedList.h LinkedList.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o lab2
