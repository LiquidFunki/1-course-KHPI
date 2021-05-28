#include "list.h"

int main() {

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

    //Исходный список
    cout << "Your List: " << endl;
    list.showAll();
    cout << endl;


    //Метод 1
    cout << "Ranok Books: " << endl;
    list.findRanok();
    cout << endl;

    //Метод 2
    cout << "Online Detective: " << endl;
    list.findOnlineDetective();
    cout << endl;

    //Метод 3
    cout << "Max Pages: " << endl;
    list.findMaxPages();
    cout << endl;


    return 0;
}