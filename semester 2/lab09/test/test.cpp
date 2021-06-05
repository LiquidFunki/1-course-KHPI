//
// Created by Yura on 28.04.2021.
//

#include "list.h"

bool Test_comparison_operator(){
    bool result = true;

    Book book1 (true, "Harry", 158, PublishingHouse("license", "Ranok"), HARD );
    Book book2 (true, "Harry", 158, PublishingHouse("license", "Ranok"), HARD );

    if (book2 == book1) {
        result &= true;
    }else{
        result &= false;
    }


    return result;
}

bool Test_operator_equals(){
    bool result = true;

    Book book1 (true, "Harry", 158, PublishingHouse("license", "Ranok"), HARD );
    Book book2 = book1;

    if (book2 == book1) {
        result &= true;
    }else{
        result &= false;
    }

    return result;
}

bool Test_operator_index(){
    bool result = true;

    Book book1 (true, "Harry", 158, PublishingHouse("license", "Ranok"), HARD );
    Book book2 (true, "Snail", 135, PublishingHouse("license", "Ranok"), SOFT );
    Book book3 (false, "Bukvar", 107, PublishingHouse("license", "Shkola"), SOFT );
    List list;
    list.setsize(0);
    list.addBook(book1);
    list.addBook(book2);
    list.addBook(book3);

    if (book2 == list[1]) {
        result &= true;
    }else{
        result &= false;
    }

    return result;
}

int main(){
    bool result = true;
    cout << "\nTest operator =\n\n";
    result = Test_operator_equals();
    if (result){
        cout << "Test result: succed\n";
    }else{
        cout << "Test result: failed";
    }
    cout << "\nTest operator ==\n\n";
    result = Test_comparison_operator();
    if (result){
        cout << "Test result: succed\n";
    }else{
        cout << "Test result: failed";
    }
    cout << "\n|------------------------------------------------|";
    return 0;
}