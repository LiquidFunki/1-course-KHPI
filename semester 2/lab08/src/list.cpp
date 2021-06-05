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

Book& List::object_book(string s){
    Book *new_book = new Book;
    string temp = s;
    int pos = 0;

    pos = temp.find(' ');
    string field1 = temp.substr(0, pos);
    int new_field1 = stoi(field1);
    new_book->set_digital_version(new_field1);
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field2 = temp.substr(0, pos);
    new_book->set_title(field2);
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field3 = temp.substr(0, pos);
    int new_field3 = stoi(field3);
    new_book->set_pages(new_field3);
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field4 = temp.substr(0, pos);
    temp.erase(0, pos+1);
    pos = temp.find(' ');
    string field5 = temp.substr(0, pos);
    temp.erase(0, pos+1);
    PublishingHouse *temp_house = new PublishingHouse(field4, field5);
    new_book->set_publishingHouse(temp_house);

    pos = temp.find(' ');
    string field6 = temp.substr(0, pos);
    int  new_field6 = stoi(field6);
    if(new_field6 == 0) new_book->set_cover(HARD);
    if(new_field6 == 1) new_book->set_cover(SOFT);
    temp.erase(0, pos+1);

    return *new_book;
}

void List::ReadFromFile(const string &path) {

    ifstream in;
    in.open(path);
    string object;
    this->setsize(6);
    this->books = new Book*[size];
    for( int i = 0; i < size; i++ ){
        books[i] = new Book;
    }
    int dv;
    string tt;
    int pg;
    string vs;
    string nm;
    int cvr;

    for(int i = 0; i < size; i++){
        if (in.is_open()){
            in >> dv;
            books[i]->set_digital_version(dv);
            in >> tt;
            books[i]->set_title(tt);
            in >> pg;
            books[i]->set_pages(pg);
            in >> vs;
            in >> nm;
            PublishingHouse pH(vs, nm);
            books[i]->set_publishingHouse(&pH);
            in >> cvr;
            switch(cvr){
                case 0:
                    books[i]->set_cover(HARD);
                case 1:
                    books[i]->set_cover(SOFT);
            }
        }
    }
    in.close();
}

void List::WriteToFile(const string &path) {

    ofstream out;
    out.open(path);

    for(int i = 0; i < size; i++){
        if(out.is_open()) out << this->getBook(i).toString();
    }
}