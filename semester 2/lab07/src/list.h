#ifndef LAB7_LIST_H
#define LAB7_LIST_H

#include "book.h"

class List{
    size_t size;
    Book **books;
public:
    ~List();
    void setsize(const int size);

    void addBook(Book& book);
    void removeBook(int index);
    Book& getBook(int index) const;
    void showAll();
    Book& findRanokBook() const;
};

#endif