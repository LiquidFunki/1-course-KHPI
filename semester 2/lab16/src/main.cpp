#include <iostream>
#include "list.hpp"

int main() {
    FictionBook fiction1(0, "Past", 158, PublishingHouse("license", "Ranok"), HARD, REVIVAL, ROMANCE);
    FictionBook fiction2(1, "Sherlok", 217, PublishingHouse("license", "Ranok"), HARD, MODERN, DETECTIVE);
    FictionBook fiction3(1, "Everlasting.Summer", 100, PublishingHouse("license", "Soviet"), HARD, POSTMODERN, NOVEL);


    ScienceBook science1(1, "Chemistry", 132, PublishingHouse("license", "Shkola"), HARD, CHEMISTRY, true);
    ScienceBook science2(0, "Biology", 133, PublishingHouse("license", "Shkola"), HARD, BIOLOGY, true);
    ScienceBook science3(1, "Physics", 134, PublishingHouse("license", "Shkola"), HARD, PHYSICS, true);
    {

        List<unique_ptr<Book>> list;

        unique_ptr<Book> uniquePtr(new FictionBook(fiction1));
        unique_ptr<Book> uniquePtr1(new FictionBook(fiction2));
        unique_ptr<Book> uniquePtr2(new FictionBook(fiction3));
        unique_ptr<Book> uniquePtr3(new ScienceBook(science1));
        unique_ptr<Book> uniquePtr4(new ScienceBook(science2));
        unique_ptr<Book> uniquePtr5(new ScienceBook(science3));
//        {
//            unique_ptr<Book> uniquePtr6(std::move(uniquePtr)); // После выполнения uniquePtr ни на что не указывает
//            cout << "Demo: " << endl;
//            uniquePtr6.get()->print();
//            cout << endl << endl;
//            uniquePtr = std::move(uniquePtr6);  // После выполнения uniquePtr возврщается прежнее значение, а uniquePtr6
//            // больше ни на что не указывает
//        }

        list.addItem(&uniquePtr);
        list.addItem(&uniquePtr1);
        list.addItem(&uniquePtr2);
        list.addItem(&uniquePtr3);
        list.addItem(&uniquePtr4);
        list.addItem(&uniquePtr5);



        //Исходный список
        cout << "unique_ptr LIST: " << endl;
        for (auto &backpack : list) {
            backpack->get()->print();  // используем метод get() для конвертации std::unique_ptr в обычный указатель
            cout << endl;
        }
    }

    {
        List<shared_ptr<Book>> list;

        shared_ptr<Book> sharedPtr (new FictionBook(fiction1));
        shared_ptr<Book> sharedPtr1  (new FictionBook(fiction2));
        shared_ptr<Book> sharedPtr2  (new FictionBook(fiction3));
        shared_ptr<Book> sharedPtr3  (new ScienceBook(science1));
        shared_ptr<Book> sharedPtr4  (new ScienceBook(science2));
        shared_ptr<Book> sharedPtr5  (new ScienceBook(science3));
        shared_ptr<Book> sharedPtr6  (sharedPtr);   // sharedPtr6 указывает на тот же объект, что и sharedPtr
        // и в таком случае объект будет уичтожен только тогда,
        // когда оба этих указателей выйдут за область видимости функции


        list.addItem(&sharedPtr);
        list.addItem(&sharedPtr1);
        list.addItem(&sharedPtr2);
        list.addItem(&sharedPtr3);
        list.addItem(&sharedPtr4);
        list.addItem(&sharedPtr5);
        list.addItem(&sharedPtr6);



        //Исходный список
        cout << "shared_ptr LIST: " << endl;
        for (auto &backpack : list) {
            backpack->get()->print();  // используем метод get() для конвертации std::shared_ptr в обычный указатель
            cout << endl;
        }


    }

    {
        List<weak_ptr<Book>> list;

        shared_ptr<Book> sharedPtr (new FictionBook(fiction1));
        shared_ptr<Book> sharedPtr1  (new FictionBook(fiction2));
        shared_ptr<Book> sharedPtr2  (new FictionBook(fiction3));
        shared_ptr<Book> sharedPtr3  (new ScienceBook(science1));
        shared_ptr<Book> sharedPtr4  (new ScienceBook(science2));
        shared_ptr<Book> sharedPtr5  (new ScienceBook(science3));

        // weak_ptr используется, когда нужен умный указатель, который имеет доступ к ресурсу, но не считается его владельцем.
        weak_ptr<Book> weakPtr = sharedPtr;
        weak_ptr<Book> weakPtr1 = sharedPtr1;
        weak_ptr<Book> weakPtr2 = sharedPtr2;
        weak_ptr<Book> weakPtr3 = sharedPtr3;
        weak_ptr<Book> weakPtr4 = sharedPtr4;
        weak_ptr<Book> weakPtr5 = sharedPtr5;
        weak_ptr<Book> weakPtr6 = weakPtr;


        list.addItem(&weakPtr);
        list.addItem(&weakPtr1);
        list.addItem(&weakPtr2);
        list.addItem(&weakPtr3);
        list.addItem(&weakPtr4);
        list.addItem(&weakPtr5);
        list.addItem(&weakPtr6);



        //Исходный список
        cout << "weak_ptr LIST: " << endl;
        cout << endl;
        for (auto &backpack : list) {
            backpack->lock()->print();  //используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
            cout << endl;
        }
    }

    return 0;
}
