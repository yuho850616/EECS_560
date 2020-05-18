lab8: main.o Executive.o Minheap.o Maxheap.o
		g++ -std=c++11 -g main.o Executive.o Minheap.o Maxheap.o -o lab8

main.o: main.cpp Minheap.h Minheap.cpp Maxheap.h Maxheap.cpp
		g++ -std=c++11 -g -c main.cpp

Minheap.o: Minheap.h Minheap.cpp
		g++ -std=c++11 -g -c Minheap.cpp

Maxheap.o: Maxheap.h Maxheap.cpp
				g++ -std=c++11 -g -c Maxheap.cpp

Executive.o: Executive.h Executive.cpp Minheap.h Minheap.cpp Maxheap.h Maxheap.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o lab8
