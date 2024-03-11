TARGET = lib/libgiganum.so
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
CFLAGS=-Iinclude

default: clean $(TARGET)

clean:
	rm -f obj/*.o
	rm -f lib/*
	rm -f test/lib/*

$(TARGET): $(OBJ)
	mkdir -p lib
	cc -shared -o $@ $? $(LDFLAGS)
	cp $(TARGET) test/$(TARGET)

obj/%.o: src/%.c
	mkdir -p obj
	cc -c -fPIC $< -o $@ $(CFLAGS)
