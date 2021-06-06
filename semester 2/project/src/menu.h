//
// Created by Yura on 30.05.2021.
//

/**
 * @file menu.h
 * @brief File with menu class
 *
 * @author Klymenko Y.
 * @date 29-may-2021
 * @version 1.0
 */

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include "controller.h"

/**
 * Клас-меню
 */

class Menu {
private:
    Controller controller;
public:
    /**
    * Default constructor
    */
    Menu() = default;

    /**
    * Default destructor
    */
    ~Menu() = default;

    /**
     * Method that shows user menu
     *
     * The method displays options for working with the collection
     */
    void User_menu();
};


#endif //PROJECT_MENU_H
