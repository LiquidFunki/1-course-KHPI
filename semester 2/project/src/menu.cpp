//
// Created by Yura on 30.05.2021.
//

#include "menu.h"

void Menu::User_menu() {
    controller.ReadFromFile("D:\\git2\\semester 2\\project\\books.txt");
    for (int i = 0; i < 244; ++i)
    {
        int marker;
        cout << "Menu" << endl;
        cout << "1. Show list." << endl;
        cout << "2. Delete all elements." << endl;
        cout << "3. Delete element." << endl;
        cout << "4. Get element." << endl;
        cout << "5. Add element." << endl;
        cout << "6. Find online detective." << endl;
        cout << "7. Find Ranok books." << endl;
        cout << "8. Find book with max pages." << endl;
        cout << "9. Sort books by field." << endl;
        cout << "10. Write in file." << endl;
        cout << "11. Exit." << endl;
        cin >> marker;
        cout << endl;
        cout << endl;

        switch (marker)
        {
            case 1: {
                cout << "Here your list: " << endl;
                controller.getlist()->showAll();
                cout << endl;
                cout << endl;
                break;
            }
            case 2: {
                cout << "You deleted all elements: " << endl;
                controller.getlist()->DeleteAll();
                cout << "Your list now: empty" << endl;
                controller.getlist()->showAll();
                cout << endl;
                cout << endl;
                break;
            }
            case 3: {
                cout << "Enter the index of element you want to delete: " << endl;
                int pos;
                cin >> pos;
                controller.getlist()->DeleteElement(pos);
                cout << "Element successfully deleted." << endl;
                cout << endl;
                break;
            }
            case 4: {
                cout << "Enter the index of element you want to get: " << endl;
                int index;
                cin >> index;
                vector<Book *>::iterator iter = controller.getlist()->getBook().begin();
                iter += index;
                (*iter)->print();
                cout << endl;
                break;
            }
            case 5: {
                cout << "Adding element" << endl;
                cout << "Is this fiction book or science book: 0 - fiction book, 1 - science book " << endl;
                int checker;
                cin >> checker;
                if (checker == 0) {
                    FictionBook fiction;

                    stringstream buffer1;

                    regex reg("^[0-1] [A-Z][a-zA-Z]* [0-9]{1,4} [A-Za-z][a-zA-Z]* [A-Za-z][a-zA-Z]* [0-4] [0-4] [0-4]$");

                    cout << "Availability of digital version: 0 - no, 1 - yes: " << endl;
                    int dv;
                    cin >> dv;
                    fiction.set_digital_version(dv);

                    cout << "Name of the book: " << endl;
                    string title;
                    cin >> title;
                    fiction.set_title(title);

                    cout << "Count of pages: " << endl;
                    int pages;
                    cin >> pages;
                    fiction.set_pages(pages);

                    cout << "Publishing house version: " << endl;
                    string ph_version;
                    cin >> ph_version;
                    cout << "Name of the publishong house: " << endl;
                    string ph_name;
                    cin >> ph_name;
                    PublishingHouse *ph = new PublishingHouse(ph_version, ph_name);
                    fiction.set_pH(ph);

                    cout << "Cover of the book: 0 - hard, 1 - soft: " << endl;
                    int cover;
                    cin >> cover;
                    if (cover == 0) fiction.set_cover(HARD);
                    else if (cover == 1) fiction.set_cover(SOFT);

                    cout << "Direction of the book: 0 - revival, 1 - modern, 2 - postmodern: " << endl;
                    int direction;
                    cin >> direction;
                    if (direction == 0) fiction.set_direction(REVIVAL);
                    else if (direction == 1) fiction.set_direction(MODERN);
                    else if (direction == 2) fiction.set_direction(POSTMODERN);
                    else cout << "Error";

                    cout << "Genre of the book: 0 - romance, 1 - detective, 2 - novel, 3 - story: " << endl;
                    int genre;
                    cin >> genre;
                    if (genre == 0) fiction.set_genre(ROMANCE);
                    else if (genre == 1) fiction.set_genre(DETECTIVE);
                    else if (genre == 2) fiction.set_genre(NOVEL);
                    else if (genre == 3) fiction.set_genre(STORY);
                    else cout << "Error";

                    buffer1 << dv << " " << title << " " << pages << " " << ph_version << " " << ph_name << " "
                    << cover << " " << direction << " " << genre;

                    if (regex_match(buffer1.str(), reg)) {
                    cout << "Book you added: " << endl;
                    fiction.print();

                    cout << "Do you want to add it in the end of the list or by index: 0 - end, 1 - by index: " << endl;
                    int checker_add;
                    cin >> checker_add;
                    if (checker_add == 0) {
                        cout << "Your list: " << endl;
                        controller.getlist()->addBook(&fiction);
                        controller.getlist()->showAll();
                    } else if (checker_add == 1) {
                        auto iter = controller.getlist()->getBook().begin();
                        int iter_pos;
                        cout << "Enter the index, after which you want to add your book: " << endl;
                        cin >> iter_pos;
                        auto temp = controller.getlist()->getBook();
                        temp.insert(iter + iter_pos, fiction.clone());
                        controller.getlist()->setBook(temp);
                        cout << "Your list: " << endl;
                        controller.getlist()->showAll();
                    }} else {
                        cout << endl;
                        cout << endl;
                        cout << "Error, wrong definition" << endl;
                        return;
                    }
                } else if (checker == 1) {
                    ScienceBook science;

                    stringstream buffer2;

                    regex reg("^[0-1] [A-Z][a-zA-Z]* [0-9]{1,4} [A-Za-z][a-zA-Z]* [A-Za-z][a-zA-Z]* [0-4] [0-4] [0-4]$");

                    cout << "Availability of digital version: 0 - no, 1 - yes: " << endl;
                    int dv1;
                    cin >> dv1;
                    science.set_digital_version(dv1);

                    cout << "Name of the book: " << endl;
                    string title1;
                    cin >> title1;
                    science.set_title(title1);

                    cout << "Count of pages: " << endl;
                    int pages1;
                    cin >> pages1;
                    science.set_pages(pages1);

                    cout << "Publishing house version: " << endl;
                    string ph_version1;
                    cin >> ph_version1;
                    cout << "Name of the publishong house: " << endl;
                    string ph_name1;
                    cin >> ph_name1;
                    PublishingHouse *ph1 = new PublishingHouse(ph_version1, ph_name1);
                    science.set_pH(ph1);

                    cout << "Cover of the book: 0 - hard, 1 - soft: " << endl;
                    int cover1;
                    cin >> cover1;
                    if (cover1 == 0) science.set_cover(HARD);
                    else if (cover1 == 1) science.set_cover(SOFT);

                    cout << "Sphere of the book: 0 - chemistry, 1 - biology, 2 - physics, 3 - information technologies: " << endl;
                    int sphere1;
                    cin >> sphere1;
                    if (sphere1 == 0) science.set_sphere(CHEMISTRY);
                    else if (sphere1 == 1) science.set_sphere(BIOLOGY);
                    else if (sphere1 == 2) science.set_sphere(PHYSICS);
                    else if (sphere1 == 3) science.set_sphere(IT);
                    else cout << "Error";

                    cout << "Is this book certified: 0 - no, 1 - yes: " << endl;
                    int certified1;
                    cin >> certified1;
                    science.set_certified(certified1);

                    buffer2 << dv1 << " " << title1 << " " << pages1 << " " << ph_version1 << " "
                    << ph_name1 << " " << cover1 << " " << sphere1 << " " << certified1;

                    if (regex_match(buffer2.str(), reg)) {
                    cout << "Book you added: " << endl;
                    science.print();

                    cout << "Do you want to add it in the end of the list or by index: 0 - end, 1 - by index: " << endl;
                    int checker_add1;
                    cin >> checker_add1;
                    if (checker_add1 == 0) {
                        cout << "Your list: " << endl;
                        controller.getlist()->addBook(&science);
                        controller.getlist()->showAll();
                    } else if (checker_add1 == 1) {
                        auto iter1 = controller.getlist()->getBook().begin();
                        int iter_pos1;
                        cout << "Enter the index, after which you want to add your book: " << endl;
                        cin >> iter_pos1;
                        auto temp1 = controller.getlist()->getBook();
                        temp1.insert(iter1 + iter_pos1, science.clone());
                        controller.getlist()->setBook(temp1);
                        cout << "Your list: " << endl;
                        controller.getlist()->showAll();
                    }}else {
                        cout << "Error, wrong option" << endl;
                        return;
                    }
                }
                break;
            }
            case 6:{
                cout << "Find Online Detective: " << endl;
                controller.findOnlineDetective();
                cout << endl;
                break;
            }
            case 7:{
                cout << "Find Ranok Books: " << endl;
                controller.findRanok();
                cout << endl;
                break;
            }
            case 8:{
                cout << "Find Max pages: " << endl;
                controller.findMaxPages();
                cout << endl;
                break;
            }
            case 9:{
                string str;
                cout << "Enter the field you want to sort by: digital_version, title, pages, ph_version, ph_name, cover " << endl;
                cin >> str;
                controller.SortByField(str);
                break;
            }
            case 10:{
                controller.WriteToFile("D:\\git2\\semester 2\\project\\booksout.txt");
                break;
            }
            case 11:{
                return;
            }
            default:
                printf("ERROR: Wrong option!\n");
                printf("\n\n");
                break;
        }
    }
}
