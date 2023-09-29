CC = g++
CFLAGS = -g -O2
TARGETS = main

all : $(TARGETS)

main : main.o myString.o 
	$(CC) *.o -o main

main.o : main.cpp Hashtable.hpp
	$(CC) -c $(CFLAGS) main.cpp


clean : 
	rm -f $(TARGETS) *.o
