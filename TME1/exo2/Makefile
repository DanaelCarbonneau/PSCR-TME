

CC = g++
CFLAGS = -g -O0
TARGETS = main

all : $(TARGETS)

main : main.o myString.o 
	$(CC) *.o -o main

main.o : main.cpp myString.hh
	$(CC) -c $(CFLAGS) main.cpp

myString.o : myString.cpp myString.hh
	$(CC) -c $(CFLAGS) myString.cpp


clean : 
	rm -f $(TARGETS) *.o
