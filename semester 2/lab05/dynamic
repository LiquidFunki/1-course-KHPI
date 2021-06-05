#include "data.h"

#ifndef LAB19_LIST_H
#define LAB19_LIST_H

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
                __FILE__, __LINE__, ##__VA_ARGS__)

struct BookList
{
    int digital_version; // 1-yes 0-no
    char name[15];
    int pages;
    char publishing_house[15];
    enum cover book_cover;
    struct BookList* next;
    struct BookList* prev;
};

struct List
{
    struct BookList *head;
    struct BookList *tail;
};

struct List *NewList();

struct BookList *NewBookList(int dv, char n[10], int pg, char ph[15], int cvr);

void AddElementEnd(struct List *list, int dv, char n[10], int pg, char ph[15], int cvr);

void AddElementBegin(struct List *list, int dv, char n[10], int pg, char ph[15], int cvr);

void InsertElement(struct List *list, int pos, int dv, char n[10], int pg, char ph[15], int cvr, int key);

void DeleteElement(struct List *list, int pos, int key);

void ReadListFromFile(struct List* list);

void ShowList(struct List *list, int key);

void PrintListInFile(struct List *list);

void FindBook(struct List * list, int index, int key);

int compareDv(struct BookList* a, struct BookList* b);

int compareName(struct BookList* a, struct BookList* b);

int comparePages(struct BookList* a, struct BookList* b);

int comparePL(struct BookList* a, struct BookList* b);

int compareCover(struct BookList* a, struct BookList* b);

void SortListByCriterion(struct List *list, int(*compare)(struct BookList*, struct BookList*), int key);

void FreeList(struct List *list, int key);

#endif