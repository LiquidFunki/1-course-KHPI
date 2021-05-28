#include "list.h"

void List::setsize(const int size) {
    this->size = size;
}

List::List() : books(NULL), size(0){}

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