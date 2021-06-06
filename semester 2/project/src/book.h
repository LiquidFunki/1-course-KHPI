#ifndef LAB9_BOOK_H
#define LAB9_BOOK_H

/**
 * @file book.h
 * @brief File with basic class
 *
 * @author Klymenko Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

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
using std::vector;
using std::map;
using std::set;
using std::find_if;
using std::copy;
using std::sort;
using std::back_inserter;
using std::stringstream;

/**
 * Enumeration of covers
 */
enum Cover { HARD, SOFT };

/**
 * "Publishing house" class
 */
class PublishingHouse{
    string version;
    string name;
public:
    /**
    * Default constructor
    */
    PublishingHouse();

    /**
    * Constructor with parameters
    */
    PublishingHouse(string version, string name);

    /**
    * Copy constructor
    */
    PublishingHouse(const PublishingHouse &temp);

    /**
    * Default destructor
    */
    virtual ~PublishingHouse();

    /**
     * Getter
     *
     * Returns version of the publishing house
     */
    string getVersion();

    /**
     * Getter
     *
     * Returns name of the publishing house
     */
    string getName();

    /**
     * Setter
     *
     * Sets version of the publishing house
     */
    void setVersion( const string Version);

    /**
     * Setter
     *
     * Sets name of the publishing house
     */
    void setName( const string Name);

    /**
     * Print method
     *
     * Displays object for the user
     */
    void printpb();
};

/**
 * Basic class interface "Book"
 */
class Book {
public:
    /**
    * Virtual print method
    */
    virtual void print() = 0;

    /**
    * Virtual clone method
    */
    virtual Book *clone() = 0;

    /**
    * Virtual destructor
    */
    virtual ~Book() {};

    /**
    * Virtual getter, that allows to get info about type of the object
    */
    virtual char GetType() = 0;
};

//First inheritor

/**
 * Enumeration of directions
 */
enum Direction{ REVIVAL, MODERN, POSTMODERN };

/**
 * Enumeration of genres
 */
enum Genre{ ROMANCE, DETECTIVE, NOVEL, STORY };

/**
 * Class inheritor "Fiction book" of basic interface class
 */
class FictionBook : public Book {
    int digital_version;
    string title;
    int pages;
    PublishingHouse publishingHouse;
    Cover cover;
    Direction direction;
    Genre genre;
public:
    /**
    * Default constructor
    */
    FictionBook();

    /**
    * Constructor with parameters
    */
    FictionBook(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover, Direction direction, Genre genre);

    /**
    * Default destructor
    */
    virtual ~FictionBook();

    /**
     * Getter
     *
     * Returns availability of the digital version of the fiction book
     */
    int get_digital_version() const;

    /**
     * Getter
     *
     * Returns title of the fiction books
     */
    string get_title() const;

    /**
     * Getter
     *
     * Returns count of pages of the fiction book
     */
    int get_pages() const;

    /**
     * Getter
     *
     * Returns publishing house of the fiction book
     */
    PublishingHouse get_pH() const;

    /**
     * Getter
     *
     * Returns cover of the fiction book
     */
    Cover get_cover() const;

    /**
     * Setter
     *
     * Sets availability of the digital version of the fiction book
     */
    void set_digital_version(const int digital_version);

    /**
     * Setter
     *
     * Sets title of the fiction book
     */
    void set_title(const string title);

    /**
     * Setter
     *
     * Sets count of pages of the fiction book
     */
    void set_pages(const int pages);

    /**
     * Setter
     *
     * Sets publishing house of the fiction book
     */
    void set_pH(PublishingHouse *ph);

    /**
     * Setter
     *
     * Sets cover of the fiction book
     */
    void set_cover(const Cover cover);

    /**
     * Getter
     *
     * Returns direction of the fiction book
     */
    Direction get_direction() const;

    /**
     * Getter
     *
     * Returns genre of the fiction book
     */
    Genre get_genre() const;

    /**
     * Setter
     *
     * Sets direction of the fiction book
     */
    void set_direction(const Direction direction);

    /**
     * Setter
     *
     * Sets genre of the fiction book
     */
    void set_genre(const Genre genre);

    /**
     * Print method
     *
     * Displays object for the user
     */
    void print() override;

    /**
     * Clone method
     *
     * Returns the pointer of the object
     */
    Book *clone() override;

    /**
     * Type detection method
     *
     * Returns the type of the object
     */
    char GetType() override;
};

/**
* Overload comparison operator == for Fiction Book object
*/
bool operator==(const FictionBook& A, const FictionBook&  B);

/**
* Overload of the output operator << for the Fiction Book object
*/
ostream & operator<<(ostream &out, const FictionBook& book);

/**
* Overload of the input operator >> for the Fiction Book object
*/
istream & operator>>(istream &in, FictionBook& book);

//Second inheritor

/**
 * Enumeration of spheres
 */
enum Sphere{ CHEMISTRY, BIOLOGY, PHYSICS, IT };

/**
 * Class inheritor "Science book" of basic interface class
 */
class ScienceBook : public Book {
    int digital_version;
    string title;
    int pages;
    PublishingHouse publishingHouse;
    Cover cover;
    Sphere sphere;
    bool certified;
public:
    /**
    * Default constructor
    */
    ScienceBook();

    /**
    * Constructor with parameters
    */
    ScienceBook(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover, Sphere sphere, bool certified);

    /**
    * Default destructor
    */
    virtual  ~ScienceBook();

    /**
     * Getter
     *
     * Returns availability of the digital version of the science book
     */
    int get_digital_version() const;

    /**
     * Getter
     *
     * Returns title of the science book
     */
    string get_title() const;

    /**
     * Getter
     *
     * Returns count of pages of the science book
     */
    int get_pages() const;

    /**
     * Getter
     *
     * Returns publishing house of the science book
     */
    PublishingHouse get_pH() const;

    /**
     * Getter
     *
     * Returns cover of the science book
     */
    Cover get_cover() const;

    /**
     * Setter
     *
     * Sets availability of the digital version of the science book
     */
    void set_digital_version(const int digital_version);

    /**
     * Setter
     *
     * Sets title of the science book
     */
    void set_title(const string title);

    /**
     * Setter
     *
     * Sets count of pages of the science book
     */
    void set_pages(const int pages);

    /**
     * Setter
     *
     * Sets publishing house of the science book
     */
    void set_pH(PublishingHouse *ph);

    /**
     * Setter
     *
     * Sets cover of the science book
     */
    void set_cover(const Cover cover);

    /**
     * Getter
     *
     * Returns sphere of the science book
     */
    Sphere get_sphere() const;

    /**
     * Getter
     *
     * Returns if science book is certified or not
     */
    bool get_certified() const;

    /**
     * Setter
     *
     * Sets sphere of the science book
     */
    void set_sphere(const Sphere sphere);

    /**
     * Setter
     *
     * Sets true/false if the science book is certified
     */
    void set_certified(const bool certified);

    /**
     * Print method
     *
     * Displays object for the user
     */
    void print() override;

    /**
     * Clone method
     *
     * Returns the pointer of the object
     */
    Book *clone() override;

    /**
    * Type detection method
    *
    * Returns the type of the object
    */
    char GetType() override;
};

/**
* Overload comparison operator == for Fiction Book object
*/
bool operator==(const ScienceBook& A, const ScienceBook&  B);

/**
* Overload of the output operator << for the Fiction Book object
*/
ostream & operator<<(ostream &out, const ScienceBook& book);

/**
* Overload of the input operator >> for the Fiction Book object
*/
istream & operator>>(istream &in, ScienceBook& book);


#endif

