#include "list.h"

int main() {

    FictionBook fiction1(0, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
    FictionBook fiction2(1, "Sherlok", 217, PublishingHouse("license", "Ranok"), HARD, MODERN, DETECTIVE);
    FictionBook fiction3(1, "Everlasting.Summer", 100, PublishingHouse("license", "Soviet"), HARD, POSTMODERN, NOVEL);
    FictionBook fiction4(0, "It", 113, PublishingHouse("license", "Lion"), HARD, POSTMODERN, STORY);


    ScienceBook science1(1, "Chemistry", 132, PublishingHouse("license", "Shkola"), HARD, CHEMISTRY, true);
    ScienceBook science2(0, "Biology", 133, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);
    ScienceBook science3(1, "Physics", 134, PublishingHouse("license", "Shkola"), HARD, PHYSICS, true);

    List *list = new List;
    list->addBook(&fiction1);
    list->addBook(&fiction2);
    list->addBook(&fiction3);
    list->addBook(&fiction4);
    list->addBook(&science1);
    list->addBook(&science2);
    list->addBook(&science3);

    FictionBook fiction5(0, "Berserk", 166, PublishingHouse("license", "Manga"), HARD, REVIVAL, STORY);
    FictionBook fiction6(1, "FirePunch", 144, PublishingHouse("license", "Manga"), HARD, MODERN, NOVEL);

    ScienceBook science4(1, "Chemistry.second.production", 121, PublishingHouse("license", "Shkola"), HARD, CHEMISTRY, true);
    ScienceBook science5(0, "English.second.production", 122, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);

    List *secondList = new List;
    secondList->addBook(&fiction5);
    secondList->addBook(&fiction6);
    secondList->addBook(&science4);
    secondList->addBook(&science5);



    //Исходный список
    cout << "Your List: " << endl;
    list->showAll();
    cout << endl;


    //find ranok books
    cout << "Ranok Books: " << endl;
    list->findRanok();
    cout << endl;

    //find online detective
    cout << "Online Detective: " << endl;
    list->findOnlineDetective();
    cout << endl;

    //max pages
    cout << "Max Pages: " << endl;
    list->findMaxPages();
    cout << endl;

    //sort list
    cout << "Sort list" << endl;
    list->SortByPages(false);
    list->showAll();
    cout << endl;

    //insert list
    cout << "Second list" << endl;
    secondList->showAll();
    cout << endl;

    //new list
    cout << "New list" << endl;
    list->InsertList(*secondList);
    list->showAll();

    delete list;
    delete secondList;
    return 0;
}