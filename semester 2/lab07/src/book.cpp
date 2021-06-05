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

//Book::~Book() { cout << "default destructor" << endl; };
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