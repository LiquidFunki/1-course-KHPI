//
// Created by Yura on 27.05.2021.
//

#include "controller.h"

List Controller::getlist() {
    return this->list;
}
void Controller::ReadFromFile(const string &path) {

    ifstream in;
    in.open(path);
    string object;

    FictionBook fiction;

    ScienceBook science;

    char type;
    int dv;
    string tt;
    int pg;
    string vs;
    string nm;
    int cvr;
    int direction;
    int certified;
    int genre;
    int sphere;
    stringstream buffer;

    regex reg("^[0-1] [A-Z][a-zA-Z]* [0-9]{1,4} [A-Za-z][a-zA-Z]* [A-Za-z][a-zA-Z]* [0-4] [0-4] [0-4]$");
    if (in.is_open()) {
        while (!in.eof()) {
            in >> type;
            if (type == 'F') {
                in >> dv;
                in >> tt;
                in >> pg;
                in >> vs;
                in >> nm;
                in >> cvr;
                in >> direction;
                in >> genre;

                buffer << dv << " " << tt << " " << pg << " " << vs << " " << nm << " " << cvr << " " << direction
                       << " " << genre;
                if (regex_match(buffer.str(), reg)) {
                    fiction.set_digital_version(dv);
                    fiction.set_title(tt);
                    fiction.set_pages(pg);
                    if (cvr == 0) fiction.set_cover(HARD);
                    else if (cvr == 1) fiction.set_cover(SOFT);
                    PublishingHouse pH(vs, nm);
                    fiction.set_pH(&pH);
                    if (direction == 0) fiction.set_direction(REVIVAL);
                    else if (direction == 1) fiction.set_direction(MODERN);
                    else if (direction == 2) fiction.set_direction(POSTMODERN);
                    if (genre == 0) fiction.set_genre(ROMANCE);
                    else if (genre == 1) fiction.set_genre(DETECTIVE);
                    else if (genre == 2) fiction.set_genre(NOVEL);
                    else if (genre == 3) fiction.set_genre(STORY);
                    list.addBook(&fiction);
                }
                buffer.str("");
            } else if (type == 'S') {
                in >> dv;
                in >> tt;
                in >> pg;
                in >> vs;
                in >> nm;
                in >> cvr;
                in >> sphere;
                in >> certified;

                buffer << dv << " " << nm << " " << pg << " " << vs << " " << nm << " " << cvr << " " << sphere << " "
                       << certified;
                if (regex_match(buffer.str(), reg)) {
                    science.set_digital_version(dv);
                    science.set_title(tt);
                    science.set_pages(pg);
                    if (cvr == 0) science.set_cover(HARD);
                    else if (cvr == 1) science.set_cover(SOFT);
                    PublishingHouse pH(vs, nm);
                    science.set_pH(&pH);
                    if (sphere == 0) science.set_sphere(CHEMISTRY);
                    else if (sphere == 1) science.set_sphere(BIOLOGY);
                    else if (sphere == 2) science.set_sphere(PHYSICS);
                    else if (sphere == 3) science.set_sphere(IT);
                    if (certified == 0) science.set_certified(false);
                    else if (genre == 1) science.set_certified(true);
                    list.addBook(&science);
                }
                buffer.str("");
            }
        }
    }
    in.close();
}

void Controller::WriteToFile(const string &path) {

    ofstream out;
    out.open(path);

    auto temp = list.getBook();

    for(int i = 0; i < temp.size(); i++){
        if(out.is_open()){
            if(temp[i]->GetType() == 'F'){
                out << ((FictionBook*)temp[i]->clone())->get_digital_version();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_title();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_pages();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_pH().getVersion();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_pH().getName();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_cover();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_direction();
                out << "  ";
                out << ((FictionBook*)temp[i]->clone())->get_genre();
                out << endl;
            }else if(temp[i]->GetType() == 'S'){
                out << ((ScienceBook*)temp[i]->clone())->get_digital_version();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_title();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_pages();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_pH().getVersion();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_pH().getName();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_cover();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_sphere();
                out << "  ";
                out << ((ScienceBook*)temp[i]->clone())->get_certified();
                out << endl;
            }
        }
    }
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
vector<FictionBook*> Controller::findRanok(){
    vector<FictionBook*> temp;
    auto temp1 = list.getBook();
    auto iter = temp1.begin();
    while(*iter){
        iter = find_if(iter, temp1.end(), predRanok);
        if(iter == temp1.end()) break;
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

vector<FictionBook*> Controller::findOnlineDetective() {
    vector<FictionBook*> temp;
    auto temp1 = list.getBook();
    auto iter = temp1.begin();
    while(*iter){
        iter = find_if(iter, temp1.end(), predDetective);
        if(iter == temp1.end()) break;
        ((FictionBook*)*iter)->print();
        cout<<endl;
        temp.push_back((FictionBook*)*iter);
        iter++;
    }
    return temp;
}

bool functorTruePages(Book* A, Book* B){
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

bool functorFalsePages(Book* A, Book* B){
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
void Controller::SortByPages(bool flag) {
    if (flag) {
        std::sort(list.getBook().begin(), list.getBook().end(), functorTruePages);
    } else{
        std::sort(list.getBook().begin(), list.getBook().end(), functorFalsePages);
    }
}

Book* Controller::findMaxPages() {
    vector<Book*> temp;
    auto temp1 = list.getBook();
    int n;
    cout << "Enter how you want to sort your list: 0 - up to down/max pages 1 - down to up/min pages " << endl;
    cin >> n;
    temp.reserve(temp1.size());
    copy(temp1.begin(), temp1.end(), back_inserter(temp));
    if (n == 0) {
        sort(temp.begin(), temp.end(), functorFalsePages);
    } else if (n == 1) {
        sort(temp.begin(), temp.end(), functorTruePages);
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

bool functorTrueTitle(Book* A, Book* B){//down to up
    bool result = false;

    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_title() < temp2->get_title()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_title() < temp4->get_title()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_title() < temp1->get_title()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_title() < temp3->get_title()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorFalseTitle(Book* A, Book* B){//up to down
    bool result = false;
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_title() > temp2->get_title()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_title() > temp4->get_title()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_title() > temp1->get_title()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_title() > temp3->get_title()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

bool functorTrueDV(Book* A, Book* B){//down to up
    bool result = false;

    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_digital_version() < temp2->get_digital_version()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_digital_version() < temp4->get_digital_version()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_digital_version() < temp1->get_digital_version()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_digital_version() < temp3->get_digital_version()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorFalseDV(Book* A, Book* B){//up to down
    bool result = false;
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_digital_version() > temp2->get_digital_version()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_digital_version() > temp4->get_digital_version()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_digital_version() > temp1->get_digital_version()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_digital_version() > temp3->get_digital_version()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

bool functorTruePhVer(Book* A, Book* B){//down to up
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
        if (temp3->get_pH().getVersion() < temp4->get_pH().getVersion()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getVersion() < temp1->get_pH().getVersion()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_pH().getVersion() < temp3->get_pH().getVersion()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorFalsePhVer(Book* A, Book* B){//up to down
    bool result = false;
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_pH().getVersion() > temp2->get_pH().getVersion()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getVersion() > temp4->get_pH().getVersion()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getVersion() > temp1->get_pH().getVersion()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_pH().getVersion() > temp3->get_pH().getVersion()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

bool functorTruePhName(Book* A, Book* B){//down to up
    bool result = false;

    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_pH().getName() < temp2->get_pH().getName()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getName() < temp4->get_pH().getName()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getName() < temp1->get_pH().getName()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_pH().getName() < temp3->get_pH().getName()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorFalsePhName(Book* A, Book* B){//up to down
    bool result = false;
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_pH().getName() > temp2->get_pH().getName()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getName() > temp4->get_pH().getName()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_pH().getName() > temp1->get_pH().getName()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_pH().getName() > temp3->get_pH().getName()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

bool functorTrueCover(Book* A, Book* B){//down to up
    bool result = false;

    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_cover() < temp2->get_cover()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_cover() < temp4->get_cover()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_cover() < temp1->get_cover()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_cover() < temp3->get_cover()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorFalseCover(Book* A, Book* B){//up to down
    bool result = false;
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp1 = (FictionBook *) A->clone();
        auto *temp2 = (FictionBook *) B->clone();
        if (temp1->get_cover() > temp2->get_cover()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'S' && B->GetType() == 'S') {
        auto *temp3 = (ScienceBook *) A->clone();
        auto *temp4 = (ScienceBook *) B->clone();
        if (temp3->get_cover() > temp4->get_cover()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'S') {
        auto *temp3 = (FictionBook *) A->clone();
        auto *temp1 = (ScienceBook *) B->clone();
        if (temp3->get_cover() > temp1->get_cover()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'S' && B->GetType() == 'F') {
        auto *temp1 = (ScienceBook *) A->clone();
        auto *temp3 = (FictionBook *) B->clone();
        if (temp1->get_cover() > temp3->get_cover()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

void Controller::SortByField(string field) {
    vector<Book*> temp;
    auto temp1 = list.getBook();
    int n;
    string field1 = "digital_version";
    string field2 = "title";
    string field3 = "pages";
    string field4 = "ph_version";
    string field5 = "ph_name";
    string field6 = "cover";
    cout << "Enter how you want to sort your list: 0 - up to down 1 - down to up" << endl;
    cin >> n;
    temp.reserve(temp1.size());
    copy(temp1.begin(), temp1.end(), back_inserter((temp)));

    if(field == field1) {
        if (n == 0) {
            sort(temp.begin(), temp.end(), functorFalseDV);
        } else if (n == 1) {
            sort(temp.begin(), temp.end(), functorTrueDV);
        }
    } else if (field == field2){
        if (n == 0) {
            sort(temp.begin(), temp.end(), functorFalseTitle);
        } else if (n == 1) {
            sort(temp.begin(), temp.end(), functorTrueTitle);
        }
    } else if (field == field3){
        if (n == 0) {
            sort(temp.begin(), temp.end(), functorFalsePages);
        } else if (n == 1) {
            sort(temp.begin(), temp.end(), functorTruePages);
        }
    } else if (field == field4){
        if (n == 0) {
            sort(temp.begin(), temp.end(), functorFalsePhVer);
        } else if (n == 1) {
            sort(temp.begin(), temp.end(), functorTruePhVer);
        }
    } else if (field == field5){
        if (n == 0) {
            sort(temp.begin(), temp.end(), functorFalsePhName);
        } else if (n == 1) {
            sort(temp.begin(), temp.end(), functorTruePhName);
        }
    } else if (field == field6){
        if (n == 0) {
            sort(temp.begin(), temp.end(), functorFalseCover);
        } else if (n == 1) {
            sort(temp.begin(), temp.end(), functorTrueCover);
        }
    } else {
        cout << "Error";
    }
    for (int i = 0; i <= temp.size(); ++i) {
        temp[i]->print();
    }
    temp.clear();
    temp.shrink_to_fit();
}