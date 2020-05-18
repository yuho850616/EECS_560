lab7: main.o Executive.o TTT.o Node.o
		g++ -std=c++11 -g main.o Executive.o TTT.o Node.o -o lab7

main.o: main.cpp Node.h Node.cpp TTT.h TTT.cpp
		g++ -std=c++11 -g -c main.cpp

TTT.o: TTT.h TTT.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c TTT.cpp

Node.o: Node.cpp
		g++ -std=c++11 -g -c Node.cpp

Executive.o: Executive.h Executive.cpp TTT.h TTT.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o lab7
