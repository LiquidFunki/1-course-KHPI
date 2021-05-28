#include "list.h"

List::List() {}

List::List(const List &copy) :index(copy.index), books(copy.books){}

int List::getindex(){
    return this->index;
}

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

void List::showAll() const {
    for (int i = 0; i <= this->index; ++i) {
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



void List::InsertList(List &in) {
    in.index++;
    this->books.reserve(this->index + in.index + 1);
    auto iter = this->books.end();
    for (int i = 0; i < in.index; i++) {
        this->books.insert(iter + i, in.books[i]);
    }
    this->index += in.index;
}

