lab9: main.o Minmaxheap.o Node.o
		g++ -std=c++11 -g main.o Minmaxheap.o Node.o -o lab9

main.o: main.cpp Node.h Node.cpp Minmaxheap.h Minmaxheap.cpp
		g++ -std=c++11 -g -c main.cpp

Minmaxheap.o: Minmaxheap.h Minmaxheap.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c Minmaxheap.cpp

Node.o: Node.cpp
		g++ -std=c++11 -g -c Node.cpp

clean:
		rm *.o lab9
