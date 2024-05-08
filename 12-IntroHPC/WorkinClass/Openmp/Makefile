GCC = g++ 
FLAGS = -O3 -std=c++17 -Wall -g -fopenmp
CACHEGRIND = valgrind --tool=cachegrind
MEMCHECK = valgrind --tool=memcheck
VALGRIND = --leak-check=full --track-origins=yes--leak-check=full --track-origins=yes

TARGET =$(patsubst %.cpp, %, $(wildcard *.cpp))

PARAMS = 2000
# PARAMS = 100 500 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 
NREPS = 8
TREADHS = 1 2 4 8 

all: Compile 

Compile: 
	$(GCC) $(FLAGS) $(TARGET).cpp -o $(TARGET).x
	./commands.sh

cachegrind:$(TARGET).x
	$(CACHEGRIND) ./$^ ${PARAMS} ${NREPS} 2> /dev/null 1> input-profiling.txt
	cg_annotate --auto=yes cachegrind.out.* > cachegrind-report.txt
	
memcheck:$(TARGET).x
	$(MEMCHECK) ./$^ ${PARAMS} ${NREPS} 2> /dev/null 1> input-profiling.txt
	cg_annotate --auto=yes cachegrind.out.* > cachegrind-report.txt

gprof:$(TARGET).x 
	./$^ ${PARAMS} ${NREPS} 2> /dev/null 1> input-profiling.txt
	gprof $^ > gprof-report.txt

PHONY: clean
clean:
	rm -f *.x *.txt *.out