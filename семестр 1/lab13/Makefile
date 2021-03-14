CC = gcc
C_OPTS = -g -std=gnu11 -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-value -Wunused-value -I./src

all: clean prep task1 task2

clean:
	rm -rf dist
prep:
	mkdir dist

task1: lab13_04.bin
task2: lab13_02.bin

lab13_04.bin: src/lab13_04.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
lab13_02.bin: src/lab13_02.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

doxygen:
	doxygen Doxyfile

format: #TODO

tidy: # TODO
