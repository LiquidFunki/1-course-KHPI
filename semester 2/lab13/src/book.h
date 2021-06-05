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

#define ARRAY_SIZE 255

enum Cover { HARD, SOFT };

class PublishingHouse{
    string version;
    string name;
public:
    PublishingHouse();
    PublishingHouse(string version, string name);
    PublishingHouse(const PublishingHouse &temp);
    virtual ~PublishingHouse();
    string getVersion() const;
    string getName() const;
    void setVersion( const string Version);
    void setName( const string Name);
    void printpb();
};

class Book{
    int digital_version;
    string title;
    int pages;
    PublishingHouse publishingHouse;
    Cover cover;
public:
    Book();
    Book(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover) ;
    Book(Book const &temp);
    virtual ~Book();
    int get_digital_version() const;
    string get_title() const;
    int get_pages() const;
    PublishingHouse get_publishingHouse() const;
    enum Cover get_cover() const;
    void set_digital_version(const bool digital_version);
    void set_title(const string title);
    void set_pages(const int pages);
    void set_publishingHouse(PublishingHouse *temp_publishingHouse);
    void set_cover(const enum Cover cover);

    void print1();
    Book& object_book(string s);
    string toString();
    Book& operator=(Book& book);
};
bool operator==(Book& first, Book& second);

bool operator!=(Book& first, Book& second);

ostream & operator<<(ostream &out, Book& book);

istream & operator>>(istream &in, Book& book);

//First inheritor
enum Direction{ REVIVAL, MODERN, POSTMODERN };

enum Genre{ ROMANCE, DETECTIVE, NOVEL, STORY };

class FictionBook : public Book {
    Direction direction;
    Genre genre;
public:
    FictionBook();
    FictionBook(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover, Direction direction, Genre genre);
    FictionBook(FictionBook& copy);
    virtual ~FictionBook();
    Direction get_direction() const;
    Genre get_genre() const;
    void set_direction(const Direction direction);
    void set_genre(const Genre genre);
    void print2();
};

//Second inheritor
enum Sphere{ CHEMISTRY, BIOLOGY, PHYSICS, IT };

class ScienceBook : public Book {
    Sphere sphere;
    bool certified;
public:
    ScienceBook();
    ScienceBook(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover, Sphere sphere, bool certified);
    ScienceBook(ScienceBook& copy);
    virtual  ~ScienceBook();
    Sphere get_sphere() const;
    bool get_certified() const;
    void set_sphere(const Sphere sphere);
    void set_certified(const bool certified);
    void print3();
};
bool operator>(const FictionBook& A, const FictionBook& B);

bool operator>(const ScienceBook& A, const ScienceBook& B);

bool operator>(const Book& A, const Book& B);

bool operator==(const FictionBook& A, const FictionBook& B);

bool operator==(const ScienceBook& A, const ScienceBook& B);

ostream & operator<<(ostream &out ,const Book& book);

ostream & operator<<(ostream &out ,const FictionBook& book);

ostream & operator<<(ostream &out ,const ScienceBook& book);

#endif

