targets = main.bin test.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/list.c

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile:
	$(CC) -I../Static_library/dist/ src/main.c -llist -L../Static_library/dist/ -o dist/main.bin
	cp ../Dynamic_library/dist/liblist.so ./dist



main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
test.bin: test/test.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
test: clean prep compile
	./dist/test.bin
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO
