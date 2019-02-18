LFLAGS = -Wall
CFLAGS = -c -Wall -std=c++14 -g -O0 -pedantic-errors

all: newer forkpid

newer: newer.o
	g++ $(LFLAGS) -o newer newer.o

newer.o: newer.cpp
	g++ $(CFLAGS) newer.cpp

forkpid: forkpid.o
	g++ $(LFLAGS) -o forkpid forkpid.o

forkpid.o: forkpid.cpp
	g++ $(CFLAGS) forkpid.cpp

clean:
	rm newer newer.o forkpid forkpid.o