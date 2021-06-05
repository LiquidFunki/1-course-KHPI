#include <iostream>
#include "list.hpp"

int main() {

    FictionBook fiction1(0, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
    FictionBook fiction2(1, "Sherlok", 217, PublishingHouse("license", "Ranok"), HARD, MODERN, DETECTIVE);
    FictionBook fiction3(1, "Everlasting.Summer", 100, PublishingHouse("license", "Soviet"), HARD, POSTMODERN, NOVEL);


    List<FictionBook> list;
    list.addElement(&fiction1);
    list.addElement(&fiction2);
    list.addElement(&fiction3);

    list.SortList();

    //Исходный список
    cout << "Fiction Book list: " << endl;
    list.ShowList();
    cout << endl;

    List<int> listint;

    int a = 10;
    int b = 1;
    int c = 5;

    listint.addElement(&a);
    listint.addElement(&b);
    listint.addElement(&c);

    cout << "Element from int list with index 1: " << endl;
    int res = listint.getElement(3);
    cout << res << endl << endl;

    listint.SortList();

    cout << "Min element from int list: " << endl;
    int min = listint.FindMinElement();
    cout << min << endl << endl;

    cout << "Your int list: " << endl;
    listint.ShowList();
    cout << endl;

    List<char> listchar;

    char sym1 = 'y';
    char sym2 = 'u';
    char sym3 = 'r';
    char sym4 = 'a';

    listchar.addElement(&sym1);
    listchar.addElement(&sym2);
    listchar.addElement(&sym3);
    listchar.addElement(&sym4);

    cout << "Your char list: " << endl;
    listchar.ShowList();
    cout << endl;


    List<string> liststring;
    string word1 = "Hello!";
    string word2 = "Welcome to hell!";
    string word3 = "Try to survive here!";

    liststring.addElement(&word1);
    liststring.addElement(&word2);
    liststring.addElement(&word3);

    cout << "Index of element word2 from list: ";
    int resindex = liststring.FindIndexElement(word2);
    cout << resindex << endl << endl;

    cout << "Your list string: " << endl;
    liststring.ShowList();
    cout << endl;

    cout << "Deleting element with index 1 from your string list: " << endl;
    liststring.deleteElement(1);
    liststring.ShowList();
    cout << endl;

    return 0;
}
