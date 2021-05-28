//
// Created by Yura on 28.04.2021.
//

#include "list.h"

bool Test_findOnlineDetective(){
    bool result = true;

    FictionBook fiction1(0, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
    FictionBook fiction2(1, "Sherlok", 217, PublishingHouse("license", "Ranok"), HARD, MODERN, DETECTIVE);
    FictionBook fiction3(1, "Everlasting.Summer", 100, PublishingHouse("license", "Soviet"), HARD, POSTMODERN, NOVEL);


    ScienceBook science1(1, "Chemistry", 132, PublishingHouse("license", "Shkola"), HARD, CHEMISTRY, true);
    ScienceBook science2(0, "Biology", 133, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);
    ScienceBook science3(1, "Physics", 134, PublishingHouse("license", "Shkola"), HARD, PHYSICS, true);


    List list;
    list.addBook(&fiction1);
    list.addBook(&fiction2);
    list.addBook(&fiction3);
    list.addBook(&science1);
    list.addBook(&science2);
    list.addBook(&science3);

    cout << "Ожидаемый результат:" << endl;
    fiction2.print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    vector<FictionBook*> actual = list.findOnlineDetective();
    cout << endl;

    if (actual[0]->get_digital_version() == fiction2.get_digital_version()
        && actual[0]->get_title() == fiction2.get_title()
        && actual[0]->get_pages() == fiction2.get_pages()
        && actual[0]->get_cover() == fiction2.get_cover()
        && actual[0]->get_pH().getVersion() == fiction2.get_pH().getVersion()
        && actual[0]->get_pH().getName() == fiction2.get_pH().getName()
        && actual[0]->get_direction() == fiction2.get_direction()
        && actual[0]->get_genre() == fiction2.get_genre()){

        result &= true;
    } else {
        result &= false;
    }
    return result;
}


bool Test_findMaxPages(){
    bool result = true;

    FictionBook fiction1(0, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
    FictionBook fiction2(1, "Sherlok", 217, PublishingHouse("license", "Ranok"), HARD, MODERN, DETECTIVE);
    FictionBook fiction3(1, "Everlasting.Summer", 100, PublishingHouse("license", "Soviet"), HARD, POSTMODERN, NOVEL);


    ScienceBook science1(1, "Chemistry", 132, PublishingHouse("license", "Shkola"), HARD, CHEMISTRY, true);
    ScienceBook science2(0, "Biology", 133, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);
    ScienceBook science3(1, "Physics", 134, PublishingHouse("license", "Shkola"), HARD, PHYSICS, true);

    List list;
    list.addBook(&fiction1);
    list.addBook(&fiction2);
    list.addBook(&fiction3);
    list.addBook(&science1);
    list.addBook(&science2);
    list.addBook(&science3);

    cout << "Ожидаемый результат:" << endl;
    fiction2.print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    auto actual = (FictionBook*)list.findMaxPages();
    cout << endl;

    if (actual->get_digital_version() == fiction2.get_digital_version()
        && actual->get_title() == fiction2.get_title()
        && actual->get_pages() == fiction2.get_pages()
        && actual->get_cover() == fiction2.get_cover()
        && actual->get_pH().getVersion() == fiction2.get_pH().getVersion()
        && actual->get_pH().getName() == fiction2.get_pH().getName()
        && actual->get_direction() == fiction2.get_direction()
        && actual->get_genre() == fiction2.get_genre()){

        result &= true;
    } else {
        result &= false;
    }
    return result;
}

int main(){
    bool result = true;

    cout << "\nTest 1: \n\n";
    result = Test_findOnlineDetective();
    if (result){
        cout << endl << "Test result: succeed\n";
    }else{
        cout << "Test result: failed";
    }

    cout << "\nTest 2: \n\n";
    result = Test_findMaxPages();
    if (result){
        cout << endl << "Test result: succeed\n";
    }else{
        cout << "Test result: failed";
    }

    cout << "\n";
    return 0;
}