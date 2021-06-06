/**
 * @file list.cpp
 * @brief File that performs methods of list class
 *
 * @author Klyemnko Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include "list.h"

List::List() {}

List::List(const List &copy) :index(copy.index), books(copy.books){}


List::~List(){
    while(!books.empty()){
        books.pop_back();
    }
    books.clear();
    books.shrink_to_fit();
}

void List::DeleteAll() {
    while (!books.empty()) {
        books.pop_back();
    }
    books.clear();
    books.shrink_to_fit();
    index = -1;
}

void List::addBook(Book *book) {
    index += 1;
    if (index >= 255){ ////!
        return;
    }
    this->books.push_back(book->clone());
}

vector<Book*> List::getBook() {
    return this->books;
}

void List::setBook(vector<Book *> &book1) {
//    //DeleteAll();
//    while (!books.empty()) {
//        books.pop_back();
//    }
//    books.clear();
//    books.shrink_to_fit();
//    index = -1;
    this->books = book1;
    index = book1.size();
}

void List::showAll() const {
    for (int i = 0; i < books.size(); ++i) {
        books[i]->print();
        cout << endl;
    }
}

void List::DeleteElement(int index) {
    if (index > books.size()){
        index = books.size();
    }else if (index < 0){
        index = 0;
    }
    vector<Book*>::iterator pos = books.begin() + index;
    books.erase(pos);
    this->index--;
}


