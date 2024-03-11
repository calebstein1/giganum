TARGET = bin/giganum_test
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
CFLAGS=-Iinclude
LDFLAGS=-Llib -lgiganum

default: clean $(TARGET) run-test

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ)
	mkdir -p bin
	cc -o $@ $? $(LDFLAGS)

obj/%.o: src/%.c
	cp ../include/giganum.h ./include/
	mkdir -p obj
	cc -c $< -o $@ $(CFLAGS)

run-test:
	LD_LIBRARY_PATH=lib bin/giganum_test