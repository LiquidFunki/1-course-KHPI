#ifndef LAB9_LIST_H
#define LAB9_LIST_H

#include "book.h"

class List{
    size_t size;
    Book **books;
public:
    ~List();
    List();
    List(const List &copy);
    void setsize(const int size1);

    void addBook(Book& book);
    void removeBook(int index);
    Book& getBook(int index) const;
    void showAll();
    Book& findRanokBook() const;
    void ReadFromFile(const string &path) ;
    void WriteToFile(const string &path);
    Book& object_book(string s);
    void SortByPages();
    Book& FindMaxPages();
    Book& operator[](const size_t index) const;
    size_t getsize() const;
    friend ifstream& operator>>(ifstream &in, List& list);
    friend istream& operator>>(istream &in, List& list);
};

ostream & operator<<(ostream &out ,const List& list);

ofstream & operator<<(ofstream &out ,const List& list);

//First inheritor
class FictionBookList {
    FictionBook **FictionBooks;
    size_t size;
public:
    FictionBookList();
    FictionBookList(const FictionBookList& copy);
    virtual ~FictionBookList();
    void setsize(const int size);

    void addBook(FictionBook& Book);
    FictionBook& getFictionBook(int index) const;
    FictionBook& findRanokBook();
    FictionBook& findOnlineDetective();
    FictionBook& findMaxPages();
    void SortByPages();
    virtual void showAll() const;
};

//Second inheritor
class ScienceBookList {
    ScienceBook **ScienceBooks;
    size_t size;
public:
    ScienceBookList();
    ScienceBookList(const ScienceBookList& copy);
    virtual ~ScienceBookList();
    void setsize(const int size);

    void addBook(ScienceBook& Book);
    ScienceBook& getSicenceBook(int index) const;
    ScienceBook& findRanokBook();
    ScienceBook& findMaxPages();
    void SortByPages();
    virtual void showAll() const;
};
#endif
