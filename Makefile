TARGET = lib/libgiganum.so
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
CFLAGS=-Iinclude

default: clean $(TARGET) run-tests

clean:
	rm -f obj/*.o
	rm -f lib/*
	rm -f test/lib/*

run-tests:
	make -C ./test

$(TARGET): $(OBJ)
	mkdir -p lib
	cc -shared -o $@ $? $(LDFLAGS)

obj/%.o: src/%.c
	mkdir -p obj
	cc -c -fPIC $< -o $@ $(CFLAGS)
