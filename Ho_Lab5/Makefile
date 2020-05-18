lab5: main.o Executive.o BST.o Node.o
		g++ -std=c++11 -g main.o Executive.o BST.o Node.o -o lab5

main.o: main.cpp Node.h Node.cpp BST.h BST.cpp
		g++ -std=c++11 -g -c main.cpp

BST.o: BST.h BST.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c BST.cpp

Node.o: Node.cpp
		g++ -std=c++11 -g -c Node.cpp

Executive.o: Executive.h Executive.cpp BST.h BST.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o lab5
