#include "list.h"

List::List() {}

List::List(const List &copy) :index(copy.index), books(copy.books){}

List::~List(){
    while(!books.empty()){
        books.pop_back();
    }
    books.clear();
    books.shrink_to_fit();
}

vector<Book*>::iterator List::begin(){
    return books.begin();
}

vector<Book*>::iterator List::end(){
    return books.end();
}

void List::DeleteAll() {
    while (!books.empty()) {
        books.pop_back();
    }
    books.clear();
    books.shrink_to_fit();
    index = -1;
}

void List::addBook(Book *book) {
    index += 1;
    if (index >= 255){ ////!
        return;
    }
    this->books.push_back(book->clone());
}

vector<Book*> List::getBook() {
    return this->books;
}

void List::showAll() const {
    for (int i = 0; i <= this->index; ++i) {
        books[i]->print();
        cout << endl;
    }
}

void List::DeleteElement(int index) {
    if (index > books.size()){
        index = books.size();
    }else if (index < 0){
        index = 0;
    }
    vector<Book*>::iterator pos = books.begin() + index;
    books.erase(pos);
    this->index--;
}

bool predRanok(Book *a){
    if (a->GetType() == 'F') {
        auto *Book = (FictionBook *) a->clone();
        if (Book->get_pH().getName() == "Ranok") {
            delete Book;
            return true;
        } else {
            delete Book;
            return false;
        }
    }else{
        return false;
    }
}

vector<FictionBook*> List::findRanok(){
    vector<FictionBook*> temp;
    auto iter = books.begin();
    while(*iter){
        iter = find_if(iter, this->books.end(), predRanok);
        if(*iter == NULL) break;
        ((FictionBook*)*iter)->print();
        cout<<endl;
        temp.push_back((FictionBook*)*iter);
        iter++;
    }
    return temp;
}

bool predDetective(Book* a){
    if (a->GetType() == 'F') {
        auto *Book = (FictionBook *) a->clone();
        if (Book->get_digital_version() == 1
            && Book->get_genre() == DETECTIVE) {
            delete Book;
            return true;
        } else {
            delete Book;
            return false;
        }
    }else{
        return false;
    }
}

vector<FictionBook*> List::findOnlineDetective() {
    vector<FictionBook*> temp;
    auto iter = books.begin();
    while(*iter){
        iter = find_if(iter, this->books.end(), predDetective);
        if(*iter == NULL) break;
        ((FictionBook*)*iter)->print();
        cout<<endl;
        temp.push_back((FictionBook*)*iter);
        iter++;
    }
    return temp;
}

bool functorTrue(Book* A, Book* B){
    bool result = false;

    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_pages() < temp2->get_pages()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_pages() < temp4->get_pages()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_pages() < temp1->get_pages()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_pages() < temp3->get_pages()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorFalse(Book* A, Book* B){
    bool result = false;
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_pages() > temp2->get_pages()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_pages() > temp4->get_pages()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_pages() > temp1->get_pages()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_pages() > temp3->get_pages()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

void List::SortByPages(bool flag) {
    if (flag) {
        std::sort(books.begin(), books.end(), functorTrue);
    } else{
        std::sort(books.begin(), books.end(), functorFalse);
    }
}

Book* List::findMaxPages() {
    vector<Book*> temp;
    int n;
    cout << "Enter how you want to sort your list: 0 - max pages 1 - min pages " << endl;
    cin >> n;
    temp.reserve(this->books.size());
    copy(this->books.begin(), this->books.end(), back_inserter(temp));
    if (n == 0) {
        sort(temp.begin(), temp.end(), functorFalse);
    } else if (n == 1) {
        sort(temp.begin(), temp.end(), functorTrue);
    }else {
        cout << "Error";
    }
    auto iter = temp.begin();
    if (((Book*)*iter)->GetType() == 'F'){
        ((FictionBook*)*iter)->print();
        cout << endl;
    }else {
        ((ScienceBook*)*iter)->print();
        cout << endl;
    }
    while (!temp.empty()){
        temp.pop_back();
    }
    temp.clear();
    temp.shrink_to_fit();
    return ((Book*)*iter)->clone();
}

void List::InsertList(List &in) {
    in.index++;
    this->books.reserve(this->index + in.index + 1);
    auto iter = this->books.end();
    for (int i = 0; i < in.index; i++) {
        this->books.insert(iter + i, in.books[i]);
    }
    this->index += in.index;
}

