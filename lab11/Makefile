CC = gcc
C_OPTS = -g -std=gnu11 -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-value -Wunused-value -I./src

all: clean prep task1 task2

clean:
	rm -rf dist
prep:
	mkdir dist

task1: lab11_03.bin
task2: lab11_04.bin

lab11_03.bin: src/lab11_03.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
lab11_04.bin: src/lab11_04.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

doxygen:
	doxygen Doxyfile

format: #TODO

tidy: # TODO
