#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define NUM_OF_BOOKS 6

enum cover
{
    HARD,
    SOFT
};
typedef struct books
{
    int digital_version; // 1-yes 0-no
    char name[15];
    int pages;
    char publishing_house[15];
    enum cover cover;
}books;

char * insert_arr(char * arr1, char * arrCenter, size_t position);
char * delete_arr(char * arr, size_t start, size_t end);
struct books **InsertStruct (struct books **memory_for_books, struct books *insert, int index);
struct books **DeleteStruct (struct books **memory_for_books, int index);
void PrintInConsole(struct books **memory_for_books, int size);
void GenerateRandomPages(struct books **memory_for_books);