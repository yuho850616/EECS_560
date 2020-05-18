lab6: main.o
	g++ -g -std=c++11 -Wall main.o -o lab6

main.o: main.cpp OBST.h OBST.cpp Node.h Node.cpp BST.h BST.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o lab6
