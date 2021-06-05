//
// Created by Yura on 27.05.2021.
//

#ifndef LAB11_CONTROLLER_H
#define LAB11_CONTROLLER_H

#include <list.h>

class Controller {
private:
    List list;
public:
    void ReadFromFile(const string &path);

    void WriteToFile(const string &path);

    List* getlist();

    void SortByField(string field);

    void SortByPages(bool flag);

    vector<FictionBook*> findOnlineDetective();

    vector<FictionBook*> findRanok();

    vector<Book*> findMaxPages();
};


#endif //LAB11_CONTROLLER_H
