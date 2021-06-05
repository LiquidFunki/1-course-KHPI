//
// Created by Yura on 28.04.2021.
//

#include "controller.h"


class ControllerTest {
    Controller controller;
public:
    bool Test_FindRanokBook() {
        bool result = true;

        FictionBook fictionBook2(false, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
        controller.ReadFromFile("test.txt");

        cout << "Expected result:" << endl;
        fictionBook2.print();
        cout << endl;

        cout << endl << "Actual result:" << endl;
        vector<FictionBook*> actual = controller.findRanok();
        cout << endl;

        if (actual[0]->get_digital_version() == fictionBook2.get_digital_version()
            && actual[0]->get_title() == fictionBook2.get_title()
            && actual[0]->get_pages() == fictionBook2.get_pages()
            && actual[0]->get_cover() == fictionBook2.get_cover()
            && actual[0]->get_pH().getVersion() == fictionBook2.get_pH().getVersion()
            && actual[0]->get_pH().getName() == fictionBook2.get_pH().getName()
            && actual[0]->get_direction() == fictionBook2.get_direction()
            && actual[0]->get_genre() == fictionBook2.get_genre()) {

            result &= true;
        } else {
            result &= false;
        }
        for (auto &i: actual) {
            actual.pop_back();
        }
        return result;
    }

    bool Test_FindOnlineDetective() {
        bool result = true;

        FictionBook fictionBook2(true, "Sherlok", 217, PublishingHouse("license", "Pablo"), HARD, MODERN, DETECTIVE);


        cout << "Ожидаемый результат:" << endl;
        fictionBook2.print();
        cout << endl;

        cout << endl << "Актуальный результат:" << endl;
        vector<FictionBook*> actual = controller.findOnlineDetective();
        cout << endl;

        if (actual[0]->get_digital_version() == fictionBook2.get_digital_version()
            && actual[0]->get_title() == fictionBook2.get_title()
            && actual[0]->get_pages() == fictionBook2.get_pages()
            && actual[0]->get_cover() == fictionBook2.get_cover()
            && actual[0]->get_pH().getVersion() == fictionBook2.get_pH().getVersion()
            && actual[0]->get_pH().getName() == fictionBook2.get_pH().getName()
            && actual[0]->get_direction() == fictionBook2.get_direction()
            && actual[0]->get_genre() == fictionBook2.get_genre()) {

            result &= true;
        } else {
            result &= false;
        }
        for (auto &i: actual) {
            actual.pop_back();
        }
        return result;
    }


    bool Test_FindMaxPages() {
        bool result = true;

        FictionBook fictionBook2(true, "Sherlok", 217, PublishingHouse("license", "Pablo"), HARD, MODERN, DETECTIVE);


        cout << "Ожидаемый результат:" << endl;
        fictionBook2.print();
        cout << endl;

        cout << endl << "Актуальный результат:" << endl;
        vector<Book *> actual = controller.findMaxPages();
        cout << endl;

        auto F = (FictionBook*)actual[0]->clone();

        if(F->get_digital_version() == fictionBook2.get_digital_version()
           && F->get_title() == fictionBook2.get_title()
           && F->get_pages() == fictionBook2.get_pages()
           && F->get_cover() == fictionBook2.get_cover()
           && F->get_pH().getVersion() == fictionBook2.get_pH().getVersion()
           && F->get_pH().getName() == fictionBook2.get_pH().getName()
           && F->get_direction() == fictionBook2.get_direction()
           && F->get_genre() == fictionBook2.get_genre()){
            result &= true;
        } else {
            result &= false;
        }
        for (auto &i: actual) {
            actual.pop_back();
        }

        delete F;
        return result;
    }
};

int main(){
    bool result;
    ControllerTest controllerTest;
    cout << "\n|-----------------------------------------------------------ТЕСТ МЕТОДА 1------------------------------------------------------------|\n\n";
    result = controllerTest.Test_FindRanokBook();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|-----------------------------------------------------------ТЕСТ МЕТОДА 2------------------------------------------------------------|\n\n";
    result = controllerTest.Test_FindOnlineDetective();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|----------------------------------------------------------ТЕСТ МЕТОДА 3------------------------------------------------------------|\n\n";
    result = controllerTest.Test_FindMaxPages();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------------------------------------------------------------------------------------------------------------------------------------|";
    return 0;
}