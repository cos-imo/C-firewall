CC=gcc
CFLAGS=-c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -Iinclude 
LDFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -Iinclude

BUILD_DIR=build
OUTPUT_DIR=output

ALL_OBJECTS= $(BUILD_DIR)/main.o $(BUILD_DIR)/connect.o
ALL_EXECUTABLES=$(OUTPUT_DIR)/main
ALL_TEST_EXECUTABLES= 

all: main

main: src/main.o 
	mkdir -p build
	gcc src/main.o -o $(BUILD_DIR)/main
	clean

src/main.o: src/main.c
	$(CC) $< -o $@

build/connect.o: src/connect.c include/connect.h
	$(CC) -Iinclude $< -o $@ -lpcap

clean: 
	rm -f *.o ./tests/*.o ./src/*.o ${ALL_OBJECTS} ${ALL_TEST_EXECUTABLES} ${ALL_EXECUTABLES}
