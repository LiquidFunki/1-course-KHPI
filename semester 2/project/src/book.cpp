#include "book.h"

//Publishing house


PublishingHouse::PublishingHouse() : version(), name() { };


PublishingHouse::PublishingHouse(string version, string name) : version(version), name(name) { };


PublishingHouse::PublishingHouse(const PublishingHouse &temp) : version(temp.version), name(temp.name) { }


PublishingHouse::~PublishingHouse() = default;

string PublishingHouse::getVersion(){ return this->version; };

string PublishingHouse::getName(){ return this->name; };

void PublishingHouse::setVersion(const string Version) { this->version = Version; };

void PublishingHouse::setName(const string Name) { this->name = Name; };

void PublishingHouse::printpb() {
    cout << version;
    cout << "     ";
    cout << name;
    };

//First inheritor
FictionBook::FictionBook(): Book(), direction(REVIVAL), genre(ROMANCE) {}

FictionBook::FictionBook(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover, Direction direction, Genre genre) :
        digital_version(digital_version), title(title), pages(pages), publishingHouse(publishingHouse), cover(cover), direction(direction), genre(genre) {}


FictionBook:: ~FictionBook() {}

int FictionBook::get_digital_version() const { return this->digital_version; };

string FictionBook::get_title() const { return this->title; };

int FictionBook::get_pages() const { return this->pages; };

PublishingHouse FictionBook::get_pH() const { return this->publishingHouse; };

Cover FictionBook::get_cover() const { return this->cover; };

void FictionBook::set_digital_version(const int digital_version) {
    this->digital_version = digital_version;
}

void FictionBook::set_title(const string title) {
    this->title = title;
}

void FictionBook::set_pages(const int pages) {
    this->pages = pages;
}

void FictionBook::set_pH(PublishingHouse *ph) { ////////////!!!!!!!!!!!!!
    publishingHouse.setVersion(ph->getVersion());
    publishingHouse.setName(ph->getName());
}

void FictionBook::set_cover(const Cover cover) { /////////////!!!!!!!!
    this->cover = cover;
}

Direction FictionBook::get_direction() const { return this->direction; }

Genre FictionBook::get_genre() const { return this->genre; }

void FictionBook::set_direction(const Direction direction) {
    this->direction = direction;
}

void FictionBook::set_genre(const Genre genre) {
    this->genre = genre;
}

void FictionBook::print() {
    cout << "     ";
    cout << digital_version;
    cout << "     ";
    cout << title;
    cout << "     ";
    cout << pages;
    cout << "     ";
    publishingHouse.printpb();
    cout << "     ";
    cout << cover;
    cout << "     Direction: ";
    cout << direction;
    cout << "     Genre: ";
    cout << genre << endl;
}

char FictionBook::GetType() {
    return 'F';
}

Book* FictionBook::clone() {
    return (Book*)new FictionBook(*this);
}


//Second inheritor
ScienceBook::ScienceBook(): Book(), sphere(CHEMISTRY), certified(false) {}

ScienceBook::ScienceBook(int digital_version, string title, int pages, const PublishingHouse& publishingHouse, enum Cover cover, Sphere sphere, bool certified) :
        digital_version(digital_version), title(title), pages(pages), publishingHouse(publishingHouse), cover(cover), sphere(sphere), certified(certified) {}


ScienceBook:: ~ScienceBook() {}

int ScienceBook::get_digital_version() const { return this->digital_version; };

string ScienceBook::get_title() const { return this->title; };

int ScienceBook::get_pages() const { return this->pages; };

PublishingHouse ScienceBook::get_pH() const { return this->publishingHouse; };

Cover ScienceBook::get_cover() const { return this->cover; };

void ScienceBook::set_digital_version(const int digital_version) {
    this->digital_version = digital_version;
}

void ScienceBook::set_title(const string title) {
    this->title = title;
}

void ScienceBook::set_pages(const int pages) {
    this->pages = pages;
}

void ScienceBook::set_pH(PublishingHouse *ph) { ////////////!!!!!!!!!!!!!
    publishingHouse.setVersion(ph->getVersion());
    publishingHouse.setName(ph->getName());
}

void ScienceBook::set_cover(const Cover cover) { /////////////!!!!!!!!
    this->cover = cover;
}

Sphere ScienceBook::get_sphere() const { return this->sphere; }

bool ScienceBook::get_certified() const { return this->certified; }

void ScienceBook::set_sphere(const Sphere sphere) {
    this->sphere = sphere;
}

void ScienceBook::set_certified(const bool certified) {
    this->certified = certified;
}

void ScienceBook::print() {
    cout << "     ";
    cout << digital_version;
    cout << "     ";
    cout << title;
    cout << "     ";
    cout << pages;
    cout << "     ";
    publishingHouse.printpb();
    cout << "     ";
    cout << cover;
    cout << "     Sphere: ";
    cout << sphere;
    cout << "     Certified: ";
    cout << certified << endl;
}

char ScienceBook::GetType() {
    return 'S';
}

Book* ScienceBook::clone() {
    return (Book*)new ScienceBook(*this);
}

bool operator==(const FictionBook& A, const FictionBook& B){
    bool result = true;
    if (A.get_digital_version() == B.get_digital_version()
        && A.get_title() == B.get_title()
        && A.get_pages() == B.get_pages()
        && A.get_pH().getVersion() == B.get_pH().getVersion()
        && A.get_pH().getName() == B.get_pH().getVersion()
        && A.get_cover() == B.get_cover()
        && A.get_direction() == B.get_direction()
        && A.get_genre() == B.get_genre()) {
        result &= true;
    }else{
        result &= false;
    }
    return result;
}

bool operator==(const ScienceBook& A, const ScienceBook& B){
    bool result = true;
    if (A.get_digital_version() == B.get_digital_version()
        && A.get_title() == B.get_title()
        && A.get_pages() == B.get_pages()
        && A.get_pH().getVersion() == B.get_pH().getVersion()
        && A.get_pH().getName() == B.get_pH().getVersion()
        && A.get_cover() == B.get_cover()
        && A.get_sphere() == B.get_sphere()
        && A.get_certified() == B.get_certified()) {
        result &= true;
    }else{
        result &= false;
    }
    return result;
}
