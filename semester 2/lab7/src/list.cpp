#include "list.h"

void List::setsize(const int size) {
    this->size = size;
}

List::~List(){
    for (int i = 0; i < this->size; ++i) {
        delete this->books[i];
    }
    delete[] books;
}

void List::addBook(Book& book) {
    Book **temp1 = new Book*[this->size + 2];
    for (int i = 0; i < this->size; ++i) {
        *(temp1 + i) = this->books[i];
    }
    *(temp1 + size) = &book;
    //delete[] this->books;
    this->books = temp1;
    this->size += 1;
}

void List::removeBook(int index) {
    Book **temp = new Book*[this->size - 1];

    memcpy(temp, books, sizeof(Book) * (index));
    memcpy(temp + index, books + index + 1, sizeof(Book) * (size - index));

    delete[] this->books;
    this->books = temp;
    this->size -= 1;
}


Book& List::getBook(int index) const {
    return *books[index];
}

void List::showAll() {
    for (int i = 0; i < size; ++i) {
        Book temp = getBook(i);
        temp.print();
    }
}

Book& List::findRanokBook() const {
    string publishing_house = "Ranok";
    for (int i = 0; i < this->size; ++i) {
        if(publishing_house == books[i]->get_publishingHouse().getName()){
            books[i]->print();
        }
    }
}