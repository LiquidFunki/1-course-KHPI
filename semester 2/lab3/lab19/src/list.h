#include "data.h"

#ifndef LAB19_LIST_H
#define LAB19_LIST_H


struct BookList
{
    int digital_version; // 1-yes 0-no
    char name[15];
    int pages;
    char publishing_house[15];
    enum cover cover;
    struct BookList* next;
    struct books* prev;
};

struct List
{
    struct BookList *head;
    struct BookList *tail;
};