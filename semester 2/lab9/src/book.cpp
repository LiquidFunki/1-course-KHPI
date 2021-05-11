#include "book.h"

//Publishing house

//PublishingHouse::PublishingHouse() : version(), name() { cout << "Default constructor" << endl; };
PublishingHouse::PublishingHouse() : version(), name() { };

//PublishingHouse::PublishingHouse(string version, string name) : version(version), name(name) { cout << "Parametric contructor" << endl; };
PublishingHouse::PublishingHouse(string version, string name) : version(version), name(name) { };

//PublishingHouse::PublishingHouse(const PublishingHouse &temp) : version(temp.version), name(temp.name) { cout << "Copy constructor" << endl; };
PublishingHouse::PublishingHouse(const PublishingHouse &temp) : version(temp.version), name(temp.name) { }

//PublishingHouse::~PublishingHouse() { cout << "default destructor" << endl; };
PublishingHouse::~PublishingHouse() { };

string PublishingHouse::getVersion(){ return this->version; };

string PublishingHouse::getName(){ return this->name; };

void PublishingHouse::setVersion(const string Version) { this->version = Version; };

void PublishingHouse::setName(const string Name) { this->name = Name; };

void PublishingHouse::printpb() {
    cout << version;
    cout << "     ";
    cout << name;
    };

//Book

//Book::Book() : digital_version(false), title(), pages(0), publishingHouse(), cover(HARD) { cout << "Default constructor" << endl; };
Book::Book() : digital_version(false), title(), pages(0), publishingHouse(), cover(HARD) { };

/**Book::Book(bool digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover) :
        digital_version(digital_version), title(title), pages(pages), publishingHouse(publishingHouse), cover(cover) { cout << "Parametric contructor" << endl; };*/
Book::Book(bool digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover) :
        digital_version(digital_version), title(title), pages(pages), publishingHouse(publishingHouse), cover(cover) { };

/**Book::Book(const Book &temp) : digital_version(temp.digital_version), title(temp.title), pages(temp.pages),
                               publishingHouse(temp.publishingHouse), cover(temp.cover) { cout << "Copy constructor" << endl; };*/
Book::Book(const Book &temp) : digital_version(temp.digital_version), title(temp.title), pages(temp.pages),
                               publishingHouse(temp.publishingHouse), cover(temp.cover) { };

//Book::~Book() { cout << "default destructor" << endl };
Book::~Book() { };

bool Book::get_digital_version(){ return this->digital_version; };

string Book::get_title(){ return this->title; };

int Book::get_pages(){ return this->pages; };

PublishingHouse Book::get_publishingHouse(){ return this->publishingHouse; };

Cover Book::get_cover(){ return cover; };

void Book::set_digital_version(const bool Digital_version) { this->digital_version = Digital_version; };

void Book::set_title(const string Title) { this->title = Title; };

void Book::set_pages(const int Pages) { this->pages = Pages; };

void Book::set_publishingHouse(PublishingHouse *temp_publishingHouse) {
    publishingHouse.setVersion(temp_publishingHouse->getVersion());
    publishingHouse.setName(temp_publishingHouse->getName());
};

void Book::set_cover(const enum Cover Cover) { this->cover = Cover; };

void Book::print() {
    cout << "     ";
    cout << digital_version;
    cout << "     ";
    cout << title;
    cout << "     ";
    cout << pages;
    cout << "     ";
    publishingHouse.printpb();
    cout << "     ";
    cout << cover << endl;
     }

Book& Book::object_book(string s){
    Book *new_book = new Book;
    string temp = s;
    int pos = 0;

    pos = temp.find(' ');
    string field1 = temp.substr(0, pos);
    int new_field1 = stoi(field1);
    new_book->digital_version = new_field1;
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field2 = temp.substr(0, pos);
    new_book->title = field2;
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field3 = temp.substr(0, pos);
    int new_field3 = stoi(field3);
    new_book->pages = new_field3;
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field4 = temp.substr(0, pos);
    temp.erase(0, pos+1);
    pos = temp.find(' ');
    string field5 = temp.substr(0, pos);
    temp.erase(0, pos+1);
    PublishingHouse *temp_house = new PublishingHouse(field4, field5);
    new_book->publishingHouse = *temp_house;

    pos = temp.find(' ');
    string field6 = temp.substr(0, pos);
    int  new_field6 = stoi(field6);
    if(new_field6 == 0) new_book->cover = HARD;
    if(new_field6 == 1) new_book->cover = SOFT;
    temp.erase(0, pos+1);

    return *new_book;
}

string Book::toString(){
    stringstream result;
    result << get_digital_version() << " " << get_title() << " " << get_pages() << " " << get_cover() << " "
           << get_publishingHouse().getVersion() << " " << get_publishingHouse().getName() << endl;
    return result.str();
}

Book& Book::operator=(const Book &book) {
        set_digital_version(book.get_digital_version());
        set_pages(book.get_pages());
        set_title(book.get_title());
        set_cover(book.get_cover());
        PublishingHouse pH(book.get_publishingHouse().getVersion(), book.get_publishingHouse().getName());
        setfirm (&pH);
    return *this;
}

bool operator==(const Book& first, const Book& second){
    bool  result = true;
    if (first.et_digital_version() == second.et_digital_version()
        && first.get_title() == second.get_title()
        && first.get_pages() == second.get_pages()
        && first.getpurpose() == second.getpurpose()
        && first.get_publishingHouse().getVersion() == second.get_publishingHouse().getVersion()
        && first.get_publishingHouse().getName() == second.get_publishingHouse().getName()){
        result &= true;
    }else{
        result &= false;
    }
    return result;
}

bool operator!=(const Backpack& first, const Backpack& second){
    return !(first == second);
}

ostream & operator<<(ostream &out, const Book& book){
    out << "     ";
    out << book.get_digital_version;
    out << "     ";
    out << book.get_title();
    out << "     ";
    out << book.get_pages();
    out << "     ";
    out << book.get_publishingHouse().getVersion();
    out << "     ";
    out << book.get_publishingHouse().getName();
    out << cover << endl;
}

istream & operator>>(istream &in, const Book& book){
    ^[0-1] [A-Z][a-zA-Z]+([.][A-Z][a-zA-Z]+)* [0-9]{1,4} [A-Z][a-zA-Z]* [A-Z][a-zA-Z]* [0-1]$
}