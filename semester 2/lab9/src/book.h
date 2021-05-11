#ifndef LAB9_BOOK_H
#define LAB9_BOOK_H

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::regex_match;
using std::regex;
using std::stoi;


enum Cover { HARD, SOFT};

class PublishingHouse{
    string version;
    string name;
public:
    PublishingHouse();
    PublishingHouse(string version, string name);
    PublishingHouse(const PublishingHouse &temp);
    //virtual ~PublishingHouse() {};
    virtual ~PublishingHouse();
    string getVersion();
    string getName();
    void setVersion( const string Version);
    void setName( const string Name);
    void printpb();
};

class Book{
    bool digital_version;
    string title;
    int pages;
    PublishingHouse publishingHouse;
    enum Cover cover;
public:
    Book();
    Book(bool digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover) ;
    Book(Book const &temp);
    //virtual ~Book() {};
    virtual ~Book();
    bool get_digital_version();
    string get_title();
    int get_pages();
    PublishingHouse get_publishingHouse();
    enum Cover get_cover();
    void set_digital_version(const bool digital_version);
    void set_title(const string title);
    void set_pages(const int pages);
    void set_publishingHouse(PublishingHouse *temp_publishingHouse);
    void set_cover(const enum Cover cover);
    void print();
    Book& object_book(string s);
    string toString();
};

bool operator<(const Book& first, const Book& second);

bool operator>(const Book& first, const Book& second);

ostream & operator<<(ostream &out, const Book& book);

istream & operator>>(istream &in, const Book& book);


#endif

