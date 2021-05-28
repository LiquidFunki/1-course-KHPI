#ifndef LAB9_LIST_H
#define LAB9_LIST_H

#include "book.h"

class List {
    vector<Book*> books;
    int index = -1;
public:
    List();

    int getindex();

    List(const List &copy);

    virtual ~List();

    void addBook(Book *book);

    vector<Book*> getBook();

    void showAll() const;

    void InsertList(List  &in);

    void DeleteElement(int index);

    void DeleteAll();
};

#endif
