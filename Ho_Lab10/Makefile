lab10: main.o Executive.o Maxleftist.o Node.o
		g++ -std=c++11 -g main.o Executive.o Maxleftist.o Node.o -o lab10

main.o: main.cpp Maxleftist.h Maxleftist.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c main.cpp

Maxleftist.o: Maxleftist.h Maxleftist.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c Maxleftist.cpp Node.cpp

Executive.o: Executive.h Executive.cpp Maxleftist.h Maxleftist.cpp Node.h Node.cpp
		g++ -std=c++11 -g -c Executive.cpp

clean:
		rm *.o lab10
