//
// Created by Yura on 28.04.2021.
//

#include "list.h"

bool Test_FindRanokBook(){
    bool result = true;

    ScienceBook science1(0, "Chemistry", 132, PublishingHouse("license", "Ranok"), HARD, CHEMISTRY, true);
    ScienceBook science2(1, "Biology", 133, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);
    ScienceBook science3(1, "Physics", 134, PublishingHouse("license", "Shkola"), HARD, PHYSICS, true);

    ScienceBookList * scienceBookList = new ScienceBookList;
    scienceBookList->addBook(science1);
    scienceBookList->addBook(science2);
    scienceBookList->addBook(science3);

    cout <<  "Ожидаемый результат:" << endl;
    science1.print3();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    ScienceBook * actual = &scienceBookList->findRanokBook();
    cout << endl;

    if (actual->get_digital_version() == science1.get_digital_version()
        && actual->get_title() == science1.get_title()
        && actual->get_pages() == science1.get_pages()
        && actual->get_cover() == science1.get_cover()
        && actual->get_publishingHouse().getVersion() == science1.get_publishingHouse().getVersion()
        && actual->get_publishingHouse().getName() == science1.get_publishingHouse().getName()
        && actual->get_sphere() == science1.get_sphere()
        && actual->get_certified() == science1.get_certified()){

        result &= true;
    } else {
        result &= false;
    }

    return result;
}


int main(){
    bool result = true;

    cout << "\nMethod test from one of inheritors\n\n";
    result = Test_FindRanokBook();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    return 0;
}