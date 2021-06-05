//
// Created by Yura on 03.06.2021.
//

#ifndef LAB12_TASK_H
#define LAB12_TASK_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::out_of_range;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::invalid_argument;

class Task {
    string fileName;
    int Count;
    int* sizes;
    int** arrays;
    int *result;
public:
    Task();
    ~Task();
    void Run();
    void ReadFromFile();
    void WriteToFile();
    int getSize(int arrIndex);
    int getElem(int arrIndex, int index);
    void setSize(int arrIndex, int val);
    void setElem(int arrIndex, int index, int val);
    int* FindMinElem();
    void ForTest();
};


#endif //LAB12_TASK_H
