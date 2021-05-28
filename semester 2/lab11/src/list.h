#ifndef LAB9_LIST_H
#define LAB9_LIST_H

#include "book.h"

class List {
    Book *books[ARRAY_SIZE];
    int index = -1;
public:
    List();

    List(const List &copy);

    virtual ~List();

    void addBook(Book *book);

    Book* getBook(int index) const;

    void showAll() const;

    Book *findRanok();

    Book *findMaxPages();

    void SortByPages();

    FictionBook *findOnlineDetective();

    List &operator=(const List &copy);
};
#endif
