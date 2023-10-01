CC = g++
CFLAGS = -g -O2
TARGETS = main main2

all : $(TARGETS)

main2 : main2.o 
	$(CC) main2.o -o main2

main2.o : main2.cpp
	$(CC) -c $(CFLAGS) main2.cpp

main : main.o 
	$(CC) main.o -o main

main.o : main.cpp Hashtable.hpp
	$(CC) -c $(CFLAGS) main.cpp


clean : 
	rm -f $(TARGETS) *.o
