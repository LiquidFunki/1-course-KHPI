#ifndef LAB9_LIST_H
#define LAB9_LIST_H

/**
 * @file list.h
 * @brief File with list class
 *
 * @author Klymenko Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include "book.h"

/**
 * List class
 */
class List {
    vector<Book*> books;
    int index = -1;
public:
    /**
    * Default constructor
    */
    List();

    /**
    * Copy constructor
    */
    List(const List &copy);

    /**
    * Default destructor
    */
    virtual ~List();

    /**
     * Adding element method
     *
     * Method that adds new element in the end of the vector
     * @param book - object, that will be added
     */
    void addBook(Book *book);

    /**
     * Getter
     *
     * Returns vector of objects
     */
    vector<Book*> getBook();

    /**
     * Setter
     *
     * Sets new vector
     */
    void setBook(vector<Book*> &book1);

    /**
    * Showing method
    *
    * Method that displays collection for user
    */
    void showAll() const;

    /**
    * Deleting by index element
    *
    * Method, that deletes element in vector by index
    * @param index - element on this position will be deleted
    */
    void DeleteElement(int index);

    /**
    * Method, that clears the vector
    *
    * Method deletes all elements from the vector
    */
    void DeleteAll();
};

#endif
