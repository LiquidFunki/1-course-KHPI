#include "task.h"

bool Test_FindMinElem(){
    bool result = true;

    int actual[3];
    int expected[3] = {-2, -1, -3};

    Task test;
    test.ForTest();

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

int main(){
    bool result = true;

    cout << "\nTest Find Min element\n\n";
    result = Test_FindMinElem();
    if (result){
        cout << endl << "Test result: succeed.\n";
    }else {
        cout << "Test result: failed.";
    }

    cout << "\n|------------------------------------------------|";
    return 0;
}