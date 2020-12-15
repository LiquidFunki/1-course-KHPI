CC = gcc
C_OPTS = -g -std=gnu11 -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-value -Wunused-value -I./src

all: clean prep task1 task2 task3

clean:
	rm -rf dist
prep:
	mkdir dist

task1: lab05_05.bin
task2: lab06_06.bin
task3: lab07_01.bin

lab05_05.bin: src/lab05_05.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
lab06_06.bin: src/lab06_06.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
lab07_01.bin: src/lab07_01.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

doxygen:
	doxygen Doxyfile

format: #TODO

tidy: # TODO
