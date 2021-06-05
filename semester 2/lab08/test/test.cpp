//
// Created by Yura on 28.04.2021.
//

#include "list.h"

bool Test_toString(){
    bool result = true;


    Book book1 (true, "Potter", 150, PublishingHouse("license", "Ranok"), HARD );

    string expected = "1 Potter 150 0 license Ranok\n";
    string actual = book1.toString();

    if (actual == expected) {
        result &= true;
    }else{
        result &= false;
    }


    return result;
}

bool Test_SplitLineToObject(){
    bool result = true;

    string  obj = "1 Potter 150 license Ranok 0";
    Book expected (true, "Potter", 150, PublishingHouse("license", "Ranok"), HARD );
    Book actual = actual.object_book(obj);

    if (actual.get_digital_version() == expected.get_digital_version()
        && actual.get_title() == expected.get_title()
        && actual.get_pages() == expected.get_pages()
        && actual.get_cover() == expected.get_cover()
        && actual.get_publishingHouse().getVersion() == expected.get_publishingHouse().getVersion()
        && actual.get_publishingHouse().getName() == expected.get_publishingHouse().getName()){
        result &= true;
    }else{
        result &= false;
    }

    return result;
}



int main(){
    bool result = true;

    cout << "To string test\n\n";
    result &= Test_toString();
    if (result){
        cout << "Result: succed\n";
    }else{
        cout << "Result: failed";
    }

    cout << "To object test\n\n";
    result &= Test_SplitLineToObject();
    if (result){
        cout << "Result: succed\n";
    }else{
        cout << "Result: failed";
    }
    return 0;
}