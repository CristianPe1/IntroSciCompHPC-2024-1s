CC = gcc
CXXFLAGS =-O3 -std=c++17
TARGET = flags

all: $(TARGET).x

$(TARGET).x: $(TARGET).cpp
	$(CC) $(CXXFLAGS) $^ -o $@


.PHONY: clean

clean:
	rm -f *.x *.gp *.pdf *.txt *.gif


# Regla para ejecutar el programa con nsize = 32
run: $(TARGET)
	./$(TARGET) $(nsize)


