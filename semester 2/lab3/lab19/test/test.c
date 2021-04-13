#include "list.h"

bool Test_NewList(){
    bool result = true;

    struct BookList * expected = malloc(sizeof (struct BookList));
    struct BookList * actual = NewBookList(1, "RopeJam", 228, "Ranok", 0 );
    char name[10] = "RopeJam";
    char publishing_house[15] = "Ranok";
    expected->digital_version = 1;
    for (int i = 0; i < 10; ++i) {
        expected->name[i] = name[i];
    }
    expected->pages = 228;
    for (int i = 0; i < 15; ++i) {
        expected->publishing_house[i] = publishing_house[i];
    }
    expected->book_cover = 0;
    expected->next = NULL;
    expected->prev = NULL;

    if(expected->digital_version == actual->digital_version && expected->pages == actual->pages && expected->book_cover == actual->book_cover && strcmp(actual->name, expected->name)==0 && strcmp(expected->publishing_house, actual->publishing_house)==0){
        result &= true;
    }else{
        result &= false;
    }
    return result;
}


bool Test_InsertElement() {
    bool result = true;

    struct List *list = NewList();
    AddElementEnd(list, 1, "Potter", 150, "Ranok", 0);
    AddElementEnd(list, 1, "Stranger", 164, "Family", 1);
    AddElementEnd(list, 0, "It", 170, "Family", 1);

    InsertElement(list, 1, 1, "RopeJam", 228, "Ranok", 0);

    struct List *expected = NewList();
    struct BookList *first = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *second = NewBookList(1, "RopeJam", 228, "Ranok", 0);NewBookList(1, "Stranger", 164, "Family", 1);
    struct BookList *third = NewBookList(1, "Stranger", 164, "Family", 1);
    struct BookList *forth = NewBookList(0, "It", 170, "Family", 1);
    first->prev = NULL;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = forth;
    forth->prev = third;
    forth->next = NULL;
    expected->head = first;
    expected->tail = forth;

    struct BookList *book = list->head;
    struct BookList *new_expected = expected->head;
    for (; book != NULL && expected != NULL; book = book->next, new_expected = new_expected->next) {
        if (book->digital_version == new_expected->digital_version && new_expected->pages == book->pages && new_expected->book_cover == book->book_cover && strcmp(book->name, new_expected->name) == 0 &&strcmp(new_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }
    return result;
}


bool Test_DeleteElement(){
    bool result = true;

    struct List *list = NewList();
    AddElementEnd(list, 1, "Potter", 150, "Ranok", 0);
    AddElementEnd(list, 1, "Stranger", 164, "Family", 1);
    AddElementEnd(list, 0, "It", 170, "Family", 1);

    DeleteElement(list, 2);

    struct List *expected = NewList();
    struct BookList *first = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *second = NewBookList(1, "Stranger", 164, "Family", 1);

    first->prev = NULL;
    first->next = second;
    second->prev = first;
    second->next = NULL;
    expected->head = first;
    expected->tail = second;

    struct BookList *book = list->head;
    struct BookList *new_expected = expected->head;
    for (; book != NULL && expected != NULL; book = book->next, new_expected = new_expected->next) {
        if (book->digital_version == new_expected->digital_version && new_expected->pages == book->pages && new_expected->book_cover == book->book_cover && strcmp(book->name, new_expected->name) == 0 && strcmp(new_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    return result;
}

bool Test_SortListByCriterion(){
    bool result = true;

    struct List *list = NewList();
    AddElementEnd(list, 1, "Potter", 150, "Ranok", 0);
    AddElementEnd(list, 1, "Stranger", 164, "Family", 1);
    AddElementEnd(list, 1, "RopeJam", 228, "Ranok", 0);
    AddElementEnd(list, 0, "It", 170, "Family", 1);

    SortListByCriterion(list, comparePages );

    struct List *expected_1 = NewList();
    struct BookList *first_1 = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *second_1 = NewBookList(1, "Stranger", 164, "Family", 1);
    struct BookList *third_1 = NewBookList(0, "It", 170, "Family", 1);
    struct BookList *forth_1 = NewBookList(1, "RopeJam", 228, "Ranok", 0);
    first_1->prev = NULL;
    first_1->next = second_1;
    second_1->prev = first_1;
    second_1->next = third_1;
    third_1->prev = second_1;
    third_1->next = forth_1;
    forth_1->prev = third_1;
    forth_1->next = NULL;
    expected_1->head = first_1;
    expected_1->tail = forth_1;

    struct BookList *book = list->head;
    struct BookList *case_expected = expected_1->head;
    for (; book != NULL && expected_1 != NULL; book = book->next, case_expected = case_expected->next) {
        if (book->digital_version == case_expected->digital_version && case_expected->pages == book->pages && case_expected->book_cover == book->book_cover && strcmp(book->name, case_expected->name) == 0 && strcmp(case_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, compareDv);

    struct List *expected_2 = NewList();
    struct BookList *first_2 = NewBookList(0, "It", 170, "Family", 1);
    struct BookList *second_2 = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *third_2 = NewBookList(1, "Stranger", 164, "Family", 1);NewBookList(1, "RopeJam", 228, "Ranok", 0);
    struct BookList *forth_2 = NewBookList(1, "RopeJam", 228, "Ranok", 0);
    first_2->prev = NULL;
    first_2->next = second_2;
    second_2->prev = first_2;
    second_2->next = third_2;
    third_2->prev = second_2;
    third_2->next = forth_2;
    forth_2->prev = third_2;
    forth_2->next = NULL;
    expected_2->head = first_2;
    expected_2->tail = forth_2;

    book = list->head;
    case_expected = expected_2->head;
    for (; book != NULL && expected_2 != NULL; book = book->next, case_expected = case_expected->next) {
        if (book->digital_version == case_expected->digital_version && case_expected->pages == book->pages && case_expected->book_cover == book->book_cover && strcmp(book->name, case_expected->name) == 0 && strcmp(case_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, compareName);

    struct List *expected_3 = NewList();
    struct BookList *first_3 = NewBookList(0, "It", 170, "Family", 1);
    struct BookList *second_3 = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *third_3 = NewBookList(1, "RopeJam", 228, "Ranok", 0);
    struct BookList *forth_3 = NewBookList(1, "Stranger", 164, "Family", 1);
    first_3->prev = NULL;
    first_3->next = second_3;
    second_3->prev = first_3;
    second_3->next = third_3;
    third_3->prev = second_3;
    third_3->next = forth_3;
    forth_3->prev = third_3;
    forth_3->next = NULL;
    expected_3->head = first_3;
    expected_3->tail = forth_3;

    book = list->head;
    case_expected = expected_3->head;
    for (; book != NULL && expected_3 != NULL; book = book->next, case_expected = case_expected->next) {
        if (book->digital_version == case_expected->digital_version && case_expected->pages == book->pages && case_expected->book_cover == book->book_cover && strcmp(book->name, case_expected->name) == 0 && strcmp(case_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, comparePL);

    struct List *expected_4 = NewList();
    struct BookList *first_4 = NewBookList(0, "It", 170, "Family", 1);
    struct BookList *second_4 = NewBookList(1, "Stranger", 164, "Family", 1);
    struct BookList *third_4 = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *forth_4 = NewBookList(1, "RopeJam", 228, "Ranok", 0);
    first_4->prev = NULL;
    first_4->next = second_4;
    second_4->prev = first_4;
    second_4->next = third_4;
    third_4->prev = second_4;
    third_4->next = forth_4;
    forth_4->prev = third_4;
    forth_4->next = NULL;
    expected_4->head = first_4;
    expected_4->tail = forth_4;

    book = list->head;
    case_expected = expected_4->head;
    for (; book != NULL && expected_4 != NULL; book = book->next, case_expected = case_expected->next) {
        if (book->digital_version == case_expected->digital_version && case_expected->pages == book->pages && case_expected->book_cover == book->book_cover && strcmp(book->name, case_expected->name) == 0 && strcmp(case_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, compareCover);

    struct List *expected_5 = NewList();
    struct BookList *first_5 = NewBookList(1, "Potter", 150, "Ranok", 0);
    struct BookList *second_5 = NewBookList(1, "RopeJam", 228, "Ranok", 0);
    struct BookList *third_5 = NewBookList(0, "It", 170, "Family", 1);
    struct BookList *forth_5 = NewBookList(1, "Stranger", 164, "Family", 1);
    first_5->prev = NULL;
    first_5->next = second_5;
    second_5->prev = first_5;
    second_5->next = third_5;
    third_5->prev = second_5;
    third_5->next = forth_5;
    forth_5->prev = third_5;
    forth_5->next = NULL;
    expected_5->head = first_5;
    expected_5->tail = forth_5;

    book = list->head;
    case_expected = expected_5->head;
    for (; book != NULL && expected_5 != NULL; book = book->next, case_expected = case_expected->next) {
        if (book->digital_version == case_expected->digital_version && case_expected->pages == book->pages && case_expected->book_cover == book->book_cover && strcmp(book->name, case_expected->name) == 0 && strcmp(case_expected->publishing_house, book->publishing_house) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    return result;
}

    int main(){
        bool result = true;
        printf("\nCreate new list element test:\n\n");
        result &= Test_NewList();
        if (result == true){
            printf("Test result: succeed\n");
        }else{
            printf("Test result:failed\n");
        }
        printf("\nInsert new element test:\n\n");
        result &= Test_InsertElement();
        if (result == true){
            printf("Test result: succeed\n");
        }else{
            printf("Test result:failed\n");
        }
        printf("\nDelete element from list test:\n\n");
        result &= Test_DeleteElement();
        if (result == true){
            printf("Test result: succeed\n");
        }else{
            printf("Test result:failed\n");
        }
        printf("\nSort list test\n\n");
        result &= Test_SortListByCriterion();
        if (result == true){
            printf("Test result: succeed\n");
        }else{
            printf("Test result:failed\n");
        }
}