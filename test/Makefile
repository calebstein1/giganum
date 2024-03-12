TARGET = bin/giganum_test
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
CFLAGS=-I../include
LDFLAGS=-L../lib -lgiganum

default: clean $(TARGET) run-test

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ)
	mkdir -p bin
	cc -o $@ $? $(LDFLAGS)

obj/%.o: src/%.c
	mkdir -p obj
	cc -c $< -o $@ $(CFLAGS)

run-test:
	@echo "***RUNNING TESTS***\n"
	LD_LIBRARY_PATH=../lib bin/giganum_test
	@echo "\n***TESTS COMPLETED***"
