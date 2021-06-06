//
// Created by Yura on 27.05.2021.
//

/**
 * @file controller.h
 * @brief Файл з класом-контролером
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#ifndef LAB11_CONTROLLER_H
#define LAB11_CONTROLLER_H

#include <list.h>

/**
 * Controller class
 */

class Controller {
private:
    List list;
public:
    /**
    * Default constructor
    */
    Controller() = default;

    /**
    * Default destructor
    */
    ~Controller() = default;

    /**
     * Method that reads data from file
     *
     * Method thar reads data from file and puts it down in list
     */
    void ReadFromFile(const string &path);

    /**
     * Method that writes to file
     *
     * Method thar writes collection to file
     */
    void WriteToFile(const string &path);

    /**
     * Getter
     *
     * Gets list
     */
    List* getlist();

    /**
     * Sort method
     *
     * Method that sorts by given field
     * @param field - the field, that method will sort by
     */
    void SortByField(string field);

    /**
     * Find object method
     *
     * Method that finds online detective in collection
     * @return vector with object(s) that we wanted to find
     */
    vector<FictionBook*> findOnlineDetective();

    /**
     * Find object method
     *
     * Method that finds books with publishing house "Ranok"
     * @return vector with object(s) that we wanted to find
     */
    vector<FictionBook*> findRanok();

    /**
     * Find object method
     *
     * Method that finds book with max count of pages
     * @return vector with object that we wanted to find
     */
    vector<Book*> findMaxPages();
};


#endif //LAB11_CONTROLLER_H
