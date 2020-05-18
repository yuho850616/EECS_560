lab12: main.o Executive.o Adjacency.o UnionFind.o
		g++ -std=c++11 -g main.o Executive.o Adjacency.o UnionFind.o -o lab12

main.o: main.cpp Adjacency.h Adjacency.cpp UnionFind.h UnionFind.cpp Maxheap.h
		g++ -std=c++11 -g -c main.cpp

Adjacency.o: Adjacency.h Adjacency.cpp UnionFind.h UnionFind.cpp Maxheap.h
		g++ -std=c++11 -g -c Adjacency.cpp

UnionFind.o: UnionFind.h UnionFind.cpp
		g++ -std=c++11 -g -c UnionFind.cpp

Executive.o: Executive.h Executive.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
	rm *.o lab12
