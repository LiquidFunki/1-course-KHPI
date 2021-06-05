#include "list.h"

int main() {
    Book book1 (true, "Potter", 218, PublishingHouse("license", "Ranok"),  HARD);
    Book book2 (false, "Snail", 115, PublishingHouse("license", "Shkola"), SOFT);
    Book book3 (true, "Chess", 125, PublishingHouse("license", "Shkola"), HARD);
    Book book4 (true, "Zelda", 67, PublishingHouse("license", "Ranok"), SOFT);

    List * list = new List;
    list->setsize(0);
    list->addBook(book1);
    list->addBook(book2);
    list->addBook(book3);
    list->addBook(book4);

    cout << "Copy construct demonstartion:" << endl;
    Book book5(book1);
    book5.print();
    cout << endl;

    cout << "Digital version( 1 - Yes, 0 - No)" << endl;
    cout << "Cover(0 - HARD, 1 - SOFT)"<< endl;
    cout << "Your list:" << endl;
    list->showAll();
    cout << endl;

    cout << "Function to find book with publishing house Ranok" << endl;
    list->findRanokBook();
    cout << endl;

    cout << "Function to receive book with index user want" << endl;
    Book temp = list->getBook(1);
    temp.print();
    cout << endl;

    cout << "Function to delete element from the list" << endl;
    list->removeBook(2);
    list->showAll();
    cout << endl;

    return 0;
}
















//    delete list;
//    delete PublishingHouse;
//    delete book;
