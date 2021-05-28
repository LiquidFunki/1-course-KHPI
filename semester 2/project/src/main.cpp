
#include "controller.h"

int main() {

    Controller controller;

    controller.ReadFromFile("D:\\git2\\semester 2\\project\\books.txt");
    controller.getlist().showAll();
    controller.WriteToFile("D:\\git2\\semester 2\\project\\booksout.txt");

    cout << "Find Online Detective: " << endl;
    controller.findOnlineDetective();
    cout << endl;

    cout << "Find Ranok Books: " << endl;
    controller.findRanok();
    cout << endl;

    cout << "Find Max/Min pages: " << endl;
    controller.findMaxPages();
    cout << endl;

    string str;
    cout << "Enter the field you want to sort by: digital_version, title, pages, ph_version, ph_name, cover " << endl;
    cin >> str;
    controller.SortByField(str);

    return 0;
}