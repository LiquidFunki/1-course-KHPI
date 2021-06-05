CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile

clean:
	rm -rf dist
prep:
	mkdir dist
compile:
	cp src/list.h ../dynamic
	$(CC) -c $(C_OPTS) -fPIC -I../Static_library/dist src/list.c -o dist/list.o
	$(CC) -dynamic dist/list.o ../Static_library/dist/libentity.a -o dist/liblist.so
	cp dist/liblist.so ../dynamic
