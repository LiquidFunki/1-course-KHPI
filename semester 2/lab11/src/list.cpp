#include "list.h"

List::List() {}

List::List(const List &copy) :index(copy.index){
   for(int i = 0; i <= copy.index; i++){
       books[i] = copy.books[i]->clone();
   }
}

List::~List(){
    while(index >= 0){
        delete books[index];
        index--;
    }
}

void List::addBook(Book *book) {
    index += 1;
    if (index >= ARRAY_SIZE){
        return;
    }
    books[index] = book->clone();
}

Book* List::getBook(int index) const {
    return books[index]->clone();
}

void List::showAll() const {
    for (int i = 0; i < this->index + 1; ++i) {
        books[i]->print();
        cout << endl;
    }
}
List& List::operator=(const List &copy) {
    while(index >= 0){
        delete books[index];
    }
    for(int i = 0; i <= copy.index; i++){
        books[i] = copy.books[i]->clone();
    }
    index = copy.index;
    return *this;
}
Book* List::findRanok(){
    FictionBook *temp1;
    ScienceBook *temp2;
    for (int i = 0; i <= index; ++i) {
        if(books[i]->GetType() == 'F'){
            temp1 = (FictionBook *) getBook(i);
            if(temp1->get_pH().getName() == "Ranok"){
                temp1->print();
                cout << endl;
            }
        }
        if(books[i]->GetType() == 'S'){
            temp2 = (ScienceBook *) getBook(i);
            if(temp2->get_pH().getName() == "Ranok"){
                temp2->print();
                cout << endl;
            }
        }
    }
    return temp1;
}

void List::SortByPages() {
    FictionBook *temp1;
    FictionBook *temp2;
    ScienceBook *temp3;
    ScienceBook *temp4;
    for (int i = 0; i <= index; ++i){
        for (int j = 0; j <= index - 1; ++j) {
            if (books[j]->GetType() == 'F' && books[j + 1]->GetType() == 'F'){
                temp1 = (FictionBook *) getBook(j);
                temp2 = (FictionBook *) getBook(j+1);
                if (temp1->get_pages() > temp2->get_pages()){
                    FictionBook *temp = (FictionBook *)getBook(j);
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
            if (books[j]->GetType() == 'S' && books[j + 1]->GetType() == 'S'){
                temp3 = (ScienceBook *) getBook(j);
                temp4 = (ScienceBook *) getBook(j + 1);
                if (temp3->get_pages() > temp4->get_pages()){
                    ScienceBook *temp = (ScienceBook *)getBook(j);
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
            if (books[j]->GetType() == 'S' && books[j + 1]->GetType() == 'F'){
                temp3 = (ScienceBook *) getBook(j);
                temp1 = (FictionBook *) getBook(j + 1);
                if(temp3->get_pages() > temp1->get_pages()){
                    ScienceBook *temp = (ScienceBook *) getBook(j);
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
            if (books[j]->GetType() == 'F' && books[j + 1]->GetType() == 'S'){
                temp1 = (FictionBook *) getBook(j);
                temp3 = (ScienceBook *) getBook(j + 1);
                if(temp1->get_pages() > temp3->get_pages()){
                    FictionBook *temp = (FictionBook *) getBook(j);
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
}

Book* List::findMaxPages() {
    FictionBook *temp1;
    ScienceBook *temp2;
    bool flag1 = false;
    bool flag2 = false;
    SortByPages();
    for (int i = index; i >= 0; --i) {
        if (books[i]->GetType() == 'F') {
            temp1 = (FictionBook *) getBook(i);
            temp1->print();
            cout << endl;
            flag1 = true;
            break;
        }
        if (books[i]->GetType() == 'S') {
            temp2 = (ScienceBook *) getBook(i);
            temp2->print();
            cout << endl;
            flag2 = true;
            break;
        }
        }
    if (flag1){
        return temp1;
    }
    if (flag2 ){
        return temp2;
    } else{
        cout << "ERROR: Nothing found" << endl;
        return nullptr;
    }
}

FictionBook* List::findOnlineDetective() {
    FictionBook * temp;
    for (int i = 0; i <= index; ++i) {
        if (books[i]->GetType() == 'F'){
            temp = (FictionBook *) getBook(i);
            if (temp->get_digital_version() == 1 && temp->get_genre() == DETECTIVE){
                temp->print();
                cout << endl;
                //break?
                return temp;
            }
        }

    }
}
