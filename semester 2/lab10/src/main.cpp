#include "list.h"

int main() {
    List * list = new List;
    FictionBookList * list1 = new FictionBookList;
    ScienceBookList * list2 = new ScienceBookList;
    string path = "D:\\git2\\semester 2\\lab10\\books.txt";
    list->ReadFromFile(path);


    cout << "Digital version( 1 - Yes, 0 - No)" << endl;
    cout << "Cover(0 - HARD, 1 - SOFT)"<< endl;
    cout << "Your list:" << endl;
    //cout << *list;
    list->showAll();



//    cout << "Function to find book with publishing house Ranok" << endl;
//    list->findRanokBook();
//    cout << endl;
//
//    cout << "Function to receive book with index user want" << endl;
//    Book temp = list->getBook(1);
//    temp.print();
//    cout << endl;
//
//    cout << "Function to delete element from the list" << endl;
//    list->removeBook(2);
//    list->showAll();
//    cout << endl;

    path = "D:\\git2\\semester 2\\lab10\\booksout.txt";
    list->WriteToFile(path);

//First inheritor
    cout << "First inheritor" << endl;
    FictionBook fiction1(false, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
    FictionBook fiction2(true, "Sherlok", 217, PublishingHouse("license", "Ranok"), HARD, MODERN, DETECTIVE);
    FictionBook fiction3(false, "Everlasting.Summer", 100, PublishingHouse("license", "Soviet"), HARD, POSTMODERN, NOVEL);
    FictionBook fiction4(true, "Hatiko", 130, PublishingHouse("license", "Ranok"), SOFT, MODERN, STORY);

    list1->addBook(fiction1);
    list1->addBook(fiction2);
    list1->addBook(fiction3);
    list1->addBook(fiction4);
    list1->showAll();
    cout << endl;

    cout << "Find Ranok Book" << endl;
    list1->findRanokBook();
    cout << endl;
    cout << endl;

    cout << "Find online detective" << endl;
    list1->findOnlineDetective();
    cout << endl;
    cout << endl;


//Second inheritor
    cout << "Second inheritor" << endl;
    ScienceBook science1(true, "Chemistry", 132, PublishingHouse("license", "Shkola"), HARD, CHEMISTRY, true);
    ScienceBook science2(true, "Biology", 133, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);
    ScienceBook science3(true, "Physics", 134, PublishingHouse("license", "Shkola"), HARD, PHYSICS, true);
    ScienceBook science4(true, "Information.Technology", 135, PublishingHouse("license", "Ranok"), HARD, IT, true);

    list2->addBook(science1);
    list2->addBook(science2);
    list2->addBook(science3);
    list2->addBook(science4);
    list2->showAll();

    cout << "Find Ranok Book" << endl;
    list2->findRanokBook();
    cout << endl;
    cout << endl;

//Find max pages
    cout << "Find max pages" << endl;
    Book temp1 = list->FindMaxPages();
    FictionBook temp2 = list1->findMaxPages();
    ScienceBook temp3 = list2->findMaxPages();
    if(temp1.get_pages() < temp2.get_pages()){
        if(temp2.get_pages() < temp3.get_pages()){
            temp3.print3();
        }
        else{
            temp2.print2();
        }
    }
    else{
        if(temp1.get_pages() < temp3.get_pages()){
            temp3.print3();
        }
        else{
            temp1.print1();
        }
    }


    delete list1;
    delete list2;
    delete list;
    return 0;
}
















//    delete list;
//    delete PublishingHouse;
//    delete book;
