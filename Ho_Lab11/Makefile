lab11: main.o Executive.o Minheap.o Maxheap.o BST.o Node.o
		g++ -std=c++11 -g main.o Executive.o Minheap.o Maxheap.o BST.o Node.o -o lab11

Node.o: Node.cpp Node.h
		g++ -std=c++11 -g -c Node.cpp

BST.o: BST.cpp BST.h Node.cpp Node.h
		g++ -std=c++11 -g -c BST.cpp

Minheap.o: Minheap.cpp Minheap.h
		g++ -std=c++11 -g -c Minheap.cpp

Maxheap.o: Maxheap.cpp Maxheap.h
		g++ -std=c++11 -g -c Maxheap.cpp

Executive.o: Executive.cpp Executive.h
		g++ -std=c++11 -g -c Executive.cpp

main.o: main.cpp Executive.h
		g++ -std=c++11 -g -c main.cpp

clean:
		rm *.o lab11
