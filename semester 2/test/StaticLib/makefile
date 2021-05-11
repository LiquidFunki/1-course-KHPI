CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile

clean:
	rm -rf dist
prep:
	mkdir dist
compile:
	cp src/entity.h ../shared
	$(CC) -c $(C_OPTS) src/entity.c -o ./dist/entity.o
	ar rcs ./dist/libentity.a ./dist/entity.o
	cp ./dist/libentity.a ../shared
