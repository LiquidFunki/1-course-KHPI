#include "list.h"

int main() {
    List * list = new List;
    string path = "D:\\git2\\semester 2\\lab9\\books.txt";
    list->ReadFromFile(path);

    //operator in
//    cin >> *list;
//    cout << *list << endl;

    //operator =
//    Book book;
//    book.operator=(list->operator[](3));
//    cout << book;

    //operator ==/!=
    bool result;
    if (list->getBook(1) != list->getBook(2)) {
        result = true;
    }else{
        result = false;
    }
    cout << result << endl;

    //operator in for base
    Book book;
    cin >> book;
    cout << book;

//    cout << "Object to string converting" << endl;
//    string test = list->getBook(4).toString();
//    list->getBook(4).print();
//    cout << endl << "> Information about the object in the line: " << test;
//
//    cout << "String to object converting" << endl;
//    string s = "0 Bukvar 33 license Shkola 1";
//    Book book6 = book6.object_book(s);
//    book6.print();

//    cout << "Copy construct demonstartion:" << endl;
//    Book book5(book1);
//    book5.print();
//    cout << endl;

    cout << "Digital version( 1 - Yes, 0 - No)" << endl;
    cout << "Cover(0 - HARD, 1 - SOFT)"<< endl;
    cout << "Your list:" << endl;
    cout << *list;
    //list->showAll();
    cout << endl;

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

    path = "D:\\git2\\semester 2\\lab8\\booksout.txt";
    list->WriteToFile(path);

    delete list;
    return 0;
}
















//    delete list;
//    delete PublishingHouse;
//    delete book;
