#ifndef LAB19_DATA_H
#define LAB19_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

#define NUM_OF_BOOKS 6

enum cover
{
    HARD,
    SOFT
};
struct books
{
    int digital_version; // 1-yes 0-no
    char name[15];
    int pages;
    char publishing_house[15];
    enum cover book_cover;
};

void ReadFromFile(struct books **memory_for_books);

//void GenerateRandomPages(struct books **memory_for_books);

struct books* FindPublishingHouse(struct books **memory_for_books, int size);

void Sort(struct books **memory_for_books, char user_option[20], int size);

void PutInConsole(struct books **memory_for_books);

void PutInFile(struct books **memory_for_books);

bool testSortStructure();

#endif