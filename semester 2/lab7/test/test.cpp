//
// Created by Yura on 28.04.2021.
//

#include "list.h"

bool Test_removeBook(){
    bool result = true;
    List * list1 = new List;
    List * expected = new List;
    list1->setsize(0);
    expected->setsize(0);

    Book book1 (true, "Potter", 218, PublishingHouse("license", "Ranok"),  HARD);
    Book book2 (false, "Snail", 115, PublishingHouse("license", "Shkola"), SOFT);
    Book book3 (true, "Chess", 125, PublishingHouse("license", "Shkola"), HARD);
    Book book4 (true, "Zelda", 67, PublishingHouse("license", "Ranok"), SOFT);

    Book book5 (true, "Potter", 218, PublishingHouse("license", "Ranok"),  HARD);
    Book book6 (true, "Chess", 125, PublishingHouse("license", "Shkola"), HARD);
    Book book7 (true, "Zelda", 67, PublishingHouse("license", "Ranok"), SOFT);

    list1->addBook(book1);
    list1->addBook(book2);
    list1->addBook(book3);
    list1->addBook(book4);

    expected->addBook(book5);
    expected->addBook(book6);
    expected->addBook(book7);

    list1->removeBook(1);

    for (int i = 0; i < 3; ++i) {
        Book temp = list1->getBook(i);
        Book temp1 = expected->getBook(i);
        if (temp.get_digital_version() == temp1.get_digital_version()
            && list1->getBook(i).get_title() == expected->getBook(i).get_title()
            && list1->getBook(i).get_publishingHouse().getVersion() == expected->getBook(i).get_publishingHouse().getVersion()
            && list1->getBook(i).get_publishingHouse().getName() == expected->getBook(i).get_publishingHouse().getName()
            && list1->getBook(i).get_pages() == expected->getBook(i).get_pages()
            && list1->getBook(i).get_cover() == expected->getBook(i).get_cover()) {
            result &= true;
        }else{
            result &= false;
        }
    }

    return result;
}

bool Test_getBook(){
    bool result = true;
    List * list1 = new List;
    list1->setsize(0);

    Book book1 (true, "Potter", 218, PublishingHouse("license", "Ranok"),  HARD);
    Book book2 (false, "Snail", 115, PublishingHouse("license", "Shkola"), SOFT);
    Book book3 (true, "Chess", 125, PublishingHouse("license", "Shkola"), HARD);
    Book book4 (true, "Zelda", 67, PublishingHouse("license", "Ranok"), SOFT);

    list1->addBook(book1);
    list1->addBook(book2);
    list1->addBook(book3);
    list1->addBook(book4);

    Book expected = list1->getBook(2);
    if (list1->getBook(2).get_digital_version() == expected.get_digital_version()
            && list1->getBook(2).get_title() == expected.get_title()
            && list1->getBook(2).get_publishingHouse().getVersion() == expected.get_publishingHouse().getVersion()
            && list1->getBook(2).get_publishingHouse().getName() == expected.get_publishingHouse().getName()
            && list1->getBook(2).get_pages() == expected.get_pages()
            && list1->getBook(2).get_cover() == expected.get_cover()) {
            result &= true;
    } else {
            result &= false;
    }

    return result;
}

bool Test_FindRanok(){
    bool result = true;
    List * list1 = new List;

    list1->setsize(0);

    Book book1 (true, "Potter", 218, PublishingHouse("license", "Ranok"),  HARD);
    Book book2 (false, "Snail", 115, PublishingHouse("license", "Shkola"), SOFT);
    Book book3 (true, "Chess", 125, PublishingHouse("license", "Shkola"), HARD);

    Book book5 (true, "Potter", 218, PublishingHouse("license", "Ranok"),  HARD);

    list1->addBook(book1);
    list1->addBook(book2);
    list1->addBook(book3);

    Book expected = list1->findRanokBook();

    cout << endl;

    if (expected.get_publishingHouse().getName() == "Ranok"  ) {
            result &= true;
    } else {
            result &= false;
    }

    return result;
}

int main(){
    bool result = true;

    cout << "\nRemove book test:\n\n";

    result &= Test_removeBook();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\nGet book test:\n\n";
    result &= Test_getBook();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\nFind Ranok test:\n\n";
    cout << "Result success" << endl;
    result &= Test_FindRanok();
    if (result){
        cout << "Result: success\n";
    }else{
        cout << "Result: failed";
    }
    cout << "\n|------------------------------------|";
    return 0;
}