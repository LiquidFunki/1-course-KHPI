#include "list.h"

void List::setsize(const int size1) {
    this->size = size1;
}

List::List() : books(nullptr), size(0){}

List::List(const List &copy) : size(copy.size){
    books = new Book*[size];
    for(int i = 0; i < size; i++) books[i] = new Book(*copy.books[i]);
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
        temp.print1();
    }
}

Book& List::findRanokBook() const {
    string publishing_house = "Ranok";
    int index = 0;
    for (int i = 0; i < this->size; ++i) {
        if(publishing_house == books[i]->get_publishingHouse().getName()){
            books[i]->print1();
            index = i;
        }
    }
    return getBook(index);
}

void List::SortByPages() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (getBook(j).get_pages() < getBook(j + 1).get_pages()) {
                Book temp = getBook(j);
                books[j] = books[j + 1];
                books[j + 1] = &temp;
            }
        }
    }
    }

Book& List::FindMaxPages() {
    Book *temp = new Book;
    SortByPages();
        temp = &getBook(0);
        //temp->print1();
    return *temp;
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
    string obj;
    this->setsize(6);
    delete[] this->books;
    in >> *this;
}

void List::WriteToFile(const string &path) {

    ofstream out;
    out.open(path);

    out << *this;

    out.close();
}
size_t List::getsize() const{
    return this->size;
}
ifstream & operator>>(ifstream &in, List& list){
    int dg;
    int pages;
    string name;
    int cover;
    string version;
    string pb_name;

    delete [] list.books;
    list.books = new Book*[list.size];
    for(int i = 0; i < list.size; i++) list.books[i] = new Book;

    std::stringstream buffer;
    regex reg("^[0-1] [A-Z][a-zA-Z]* [0-9]{1,4} [0-1] [A-Za-z][a-zA-Z]* [A-Za-z][a-zA-Z]*$");
    for (int i = 0; i < list.getsize(); i++) {

        in >> dg;
        in >> name;
        in >> pages;
        in >> version;
        in >> pb_name;
        in >> cover;

        buffer << dg << " " << name << " " << pages << " " << cover << " " << pb_name << " " << version;
        if(regex_match(buffer.str(), reg)){
            list[i].set_digital_version(dg);
            list[i].set_title(name);
            list[i].set_pages(pages);
            if(cover == 0)  list[i].set_cover(HARD);
            else if(cover == 1)  list[i].set_cover(SOFT);
            PublishingHouse pH(version, pb_name);
            list[i].set_publishingHouse(&pH);
        }
        buffer.str("");
    }
    return in;
}

ostream & operator<<(ostream &out, const List& list){
    for(int i = 0; i < list.getsize(); i++){
        out<<list[i];
    }
    return out;
}

ofstream & operator<<(ofstream &out, const List& list){
    for(int i = 0; i < list.getsize(); i++){
        out<<list[i];
    }
    return out;
}

istream & operator>>(istream &in, List& list){
    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    list.setsize(size);
    list.books = new Book*[size];
    for (int i = 0; i < size; i++){
        list.books[i] = new Book;
    }
    for (int i = 0; i < size; i++){
        in >> list[i];
    }
    return in;
}

Book& List::operator[](const size_t index) const{
    if(index < size) return *books[index];
    else return *books[0];
}

//First inheritor
FictionBookList::FictionBookList() : FictionBooks(NULL), size(0){}

FictionBookList::FictionBookList(const FictionBookList& copy) : size(copy.size) {
    FictionBooks = new FictionBook*[size];
    for (int i = 0; i < size; ++i) {
        FictionBooks[i] = new FictionBook(*copy.FictionBooks[i]);
    }
}

FictionBookList:: ~FictionBookList() {
    for (int i = 0; i < size; ++i) {
        delete FictionBooks[i];
    }
    delete [] FictionBooks;
}

void FictionBookList::setsize(const int size) {
    this->size = size;
}

void FictionBookList::addBook(FictionBook &Book) {
    FictionBook **temp1 = new FictionBook*[this->size + 2];
    for (int i = 0; i < this->size; ++i) {
        *(temp1 + i) = this->FictionBooks[i];
    }
    *(temp1 + size) = &Book;
    delete[] this->FictionBooks;
    this->FictionBooks = temp1;
    this->size += 1;
}

void FictionBookList::showAll() const {
    for (int i = 0; i < size; ++i) {
        FictionBook temp = getFictionBook(i);
        temp.print2();
        cout << endl;
    }
}

FictionBook& FictionBookList::getFictionBook(int index) const {
    return *FictionBooks[index];
}

FictionBook& FictionBookList::findRanokBook() {
    string publishing_house = "Ranok";
    for (int i = 0; i < this->size; ++i) {
        //if(publishing_house == FictionBooks[i]->getFictionBook().get_publishingHouse().getName()){
        if(publishing_house == getFictionBook(i).get_publishingHouse().getName())
            FictionBooks[i]->print2();
        }
    }


FictionBook& FictionBookList::findOnlineDetective(){
    FictionBook *temp = new FictionBook;
    for (int i = 0; i < size; ++i) {
        if (getFictionBook(i).get_genre() == DETECTIVE
        && getFictionBook(i).get_digital_version() == true){
            temp = &getFictionBook(i);
            temp->print2();
        }
    }
    return *temp;
}

void FictionBookList::SortByPages(){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (getFictionBook(j).get_pages() < getFictionBook(j + 1).get_pages()){
                FictionBook temp = getFictionBook(j);
                FictionBooks[j] = FictionBooks[j + 1];
                FictionBooks[j + 1] = &temp;
            }
        }
    }
    return;
}
FictionBook& FictionBookList::findMaxPages() {
    FictionBook *temp = new FictionBook;
    SortByPages();
    for (int i = 0; i < size;) {
        temp = &getFictionBook(i);
        break;
    }
    return *temp;
}

//Second inheritor
ScienceBookList::ScienceBookList() : ScienceBooks(NULL), size(0){}

ScienceBookList::ScienceBookList(const ScienceBookList& copy) : size(copy.size) {
    ScienceBooks = new ScienceBook*[size];
    for (int i = 0; i < size; ++i) {
        ScienceBooks[i] = new ScienceBook(*copy.ScienceBooks[i]);
    }
}

ScienceBookList:: ~ScienceBookList() {
    for (int i = 0; i < size; ++i) {
        delete ScienceBooks[i];
    }
    delete [] ScienceBooks;
}

void ScienceBookList::setsize(const int size) {
    this->size = size;
}

void ScienceBookList::addBook(ScienceBook &Book) {
    ScienceBook **temp1 = new ScienceBook*[this->size + 2];
    for (int i = 0; i < this->size; ++i) {
        *(temp1 + i) = this->ScienceBooks[i];
    }
    *(temp1 + size) = &Book;
    //delete[] this->books;
    this->ScienceBooks = temp1;
    this->size += 1;
}

void ScienceBookList::showAll() const {
    for (int i = 0; i < size; ++i) {
        ScienceBook temp = getSicenceBook(i);
        temp.print3();
        cout << endl;
    }
}

ScienceBook& ScienceBookList::getSicenceBook(int index) const {
    return *ScienceBooks[index];
}

ScienceBook& ScienceBookList::findRanokBook() {
    string publishing_house = "Ranok";
    for (int i = 0; i < this->size; ++i) {
        //if(publishing_house == FictionBooks[i]->getFictionBook().get_publishingHouse().getName()){
        if(publishing_house == getSicenceBook(i).get_publishingHouse().getName()) {
            ScienceBooks[i]->print3();
            return *ScienceBooks[i];
        }
    }
}


void ScienceBookList::SortByPages(){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (getSicenceBook(j).get_pages() < getSicenceBook(j + 1).get_pages()){
                ScienceBook temp = getSicenceBook(j);
                ScienceBooks[j] = ScienceBooks[j + 1];
                ScienceBooks[j + 1] = &temp;
            }
        }
    }
    return;
}
ScienceBook& ScienceBookList::findMaxPages() {
    ScienceBook *temp = new ScienceBook;
    SortByPages();
    for (int i = 0; i < size; ++i) {
        temp = &getSicenceBook(i);
        break;
    }
    return *temp;
}