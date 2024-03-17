CC = g++
SHELL:=/bin/bash
TARGET = vector_main
OBJS = vector_test.o vector_ops.o

all: $(TARGET).x

%.o: %.cpp
	$(CC) -c $<

%.x: %.o vector_ops.o 
	$(CC) $^ -o $@  

vector_test.x: $(OBJS) 
	$(CC) $^ -o $@ -l Catch2Main -l Catch2

test: vector_test.x
	./vector_test.x



clean:
	rm -f *.o *.x *.out