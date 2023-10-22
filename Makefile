# Makefile

COMPILER = g++
FLAGS = -Wall -std=c++11 

all: main.o
	$(COMPILER) $(FLAGS) main.o -o main

main.o: main.cpp
	$(COMPILER) $(FLAGS) -c main.cpp

clean:
	rm -rf *.o main

run:
	./main

