//
// Created by Yura on 03.06.2021.
//


#include "task.h"


Task::Task() : fileName(), Count(0), sizes(nullptr), arrays(nullptr), result(nullptr) {}

Task::~Task() {
    if (arrays)
        for (int i = 0; i < Count; i++)
            delete[] arrays[i];
    delete[] arrays;
    delete[] sizes;
    delete[] result;
}

void Task::Run() {
    bool test = true;
    while(test) {
        try {
            cout << "Enter Input FileName: ";
            cin >> fileName;
            if (fileName == "\\exit") // \\exit => "\exit"
                return;
            cout << "Reading... " <<endl;
            ReadFromFile();
            result = FindMinElem();
            cout << endl << "Enter Output FileName: ";
            cin >> fileName;
            if (fileName == "\\exit")
                return;
            cout << "Writing... " << endl;
            WriteToFile();
            break;
        }
        catch (out_of_range& e) {
            cout << e.what() << endl;
        }
        catch (ios_base::failure& e) {
            cout << e.what() << endl;
        }
        catch (invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
}


void Task::ReadFromFile() {
    ifstream fin;
    fin.exceptions(ios_base::failbit | ios_base::badbit);
    fin.open(fileName, ios_base::in);
    fin >> Count;
    if (Count < 0) {
        throw invalid_argument("Bad Argument");
    }
    sizes = new int[Count];
    arrays = new int*[Count];
    for (int i = 0; i < Count; i++) {
        int val_size;
        fin >> val_size;
        setSize(i, val_size);
        arrays[i] = new int[getSize(i)];
        for (int j = 0; j < getSize(i); j++)
        {
            int val;
            fin >> val;
            setElem(i, j, val);
        }
    }
    fin.close();
}

void Task:: WriteToFile() {
    ofstream fout;
    fout.exceptions(ios_base::failbit | ios_base::badbit);
    fout.open(fileName, ios_base::out);
    for (int i = 0; i < Count; i++){
        fout << result[i] << " ";
    }
    fout.close();
}

int Task:: getSize(int arrIndex) {
    if (arrIndex >= Count || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return sizes[arrIndex];
    }
}

int Task:: getElem(int arrIndex, int index) {
    if (arrIndex >= Count || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return arrays[arrIndex][index];
    }
}

void Task:: setSize(int arrIndex, int val) {
    if (arrIndex >= Count || arrIndex < 0 || val < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        sizes[arrIndex] = val;
    }
}

void Task:: setElem(int arrIndex, int index, int val) {
    if (arrIndex >= Count || arrIndex < 0 ){
        throw out_of_range("Out of range exception:");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        arrays[arrIndex][index] = val;
    }
}

int* Task::FindMinElem(){
    int *temp_res = new int[Count];
    int elem = 0;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem > getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

void Task::ForTest(){
    fileName = "test_test.txt";
    ReadFromFile();
    result = FindMinElem();
    fileName = "TestResult.txt";
    WriteToFile();
}