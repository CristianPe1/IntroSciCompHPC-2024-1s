GCC = g++ 
FLAGS = -O3 -std=c++17 -fopenmp

TARGET = $(patsubst %.cpp, %, $(wildcard *.cpp))

PARAMS = 100 500 1000
# PARAMS = 100 500 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 
NREPS = 2
TREADHS = 1 2 4 8 

all: Compile 

Compile: 
	$(GCC) $(FLAGS) $(TARGET).cpp
	./commands.sh


PHONY: clean
clean:
	rm -f *.x *.txt *.out