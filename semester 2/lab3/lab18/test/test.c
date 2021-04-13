#include "lib.h"

bool insert_test()
{
    bool result = true;
    char *expected = "aaaaassssssssaaaa";
    char *actual = insert_arr("aaaaaaaaa","ssssssss", 5);
    if(strcmp(expected, actual) == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    printf("Expected result: %s\n\n", expected);
    printf("Actual result: %s\n\n", actual);

    free(actual);
    return result;
}

bool delete_test()
{
    bool result = true;
    char *expected = "aaaaa";
    char* actual = delete_arr("aaaaaaaaa",3, 7);
    if(strcmp(expected, actual) == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    printf("Expected result: %s\n\n", expected);
    printf("Actual result: %s\n\n", actual);

    free(actual);
    return result;
}

bool test_insert_struct()
{
    bool result = true;

    struct books * insert = malloc(sizeof (struct books));

    insert->digital_version = 1;
    strcpy(insert->name, "Zelda");
    insert->pages = 145;
    strcpy(insert->publishing_house, "Ranok");
    insert->cover = SOFT;


    struct books ** books_for_test = malloc((NUM_OF_BOOKS + 1) * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS + 1; i++){
        *(books_for_test + i) = malloc(sizeof (struct books));
    }

    (*(books_for_test))->digital_version = 1;
    strcpy((*(books_for_test))->name, "Potter");
    (*(books_for_test))->pages = 145;
    stpcpy((*(books_for_test))->publishing_house, "Ranok");
    (*(books_for_test))->cover = HARD;

    (*(books_for_test + 1))->digital_version = 1;
    strcpy((*(books_for_test + 1))->name, "Stranger");
    (*(books_for_test + 1))->pages = 214;
    stpcpy((*(books_for_test + 1))->publishing_house, "Family");
    (*(books_for_test + 1))->cover = SOFT;

    (*(books_for_test + 2))->digital_version = 0;
    strcpy((*(books_for_test + 2))->name, "It");
    (*(books_for_test + 2))->pages = 400;
    stpcpy((*(books_for_test + 2))->publishing_house, "Family");
    (*(books_for_test + 2))->cover = SOFT;

    (*(books_for_test + 3))->digital_version = 0;
    strcpy((*(books_for_test + 3))->name, "Bukvar");
    (*(books_for_test + 3))->pages = 125;
    stpcpy((*(books_for_test + 3))->publishing_house, "Shkola");
    (*(books_for_test + 3))->cover = HARD;

    (*(books_for_test + 4))->digital_version = 1;
    strcpy((*(books_for_test + 4))->name, "Chess");
    (*(books_for_test + 4))->pages = 145;
    stpcpy((*(books_for_test + 4))->publishing_house, "Ranok");
    (*(books_for_test + 4))->cover = HARD;

    (*(books_for_test + 5))->digital_version = 1;
    strcpy((*(books_for_test + 5))->name, "Snail");
    (*(books_for_test + 5))->pages = 107;
    stpcpy((*(books_for_test + 5))->publishing_house, "Ranok");
    (*(books_for_test + 5))->cover = SOFT;

    struct books ** expected_test = malloc((NUM_OF_BOOKS + 1) * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS + 1; i++){
        *(expected_test + i) = malloc(sizeof (struct books));
    }

    (*(expected_test))->digital_version = 1;
    strcpy((*(expected_test))->name, "Potter");
    (*(expected_test))->pages = 145;
    stpcpy((*(expected_test))->publishing_house, "Ranok");
    (*(expected_test))->cover = HARD;

    (*(expected_test + 1))->digital_version = 1;
    strcpy((*(expected_test + 1))->name, "Stranger");
    (*(expected_test + 1))->pages = 214;
    stpcpy((*(expected_test + 1))->publishing_house, "Family");
    (*(expected_test + 1))->cover = SOFT;

    (*(expected_test + 2))->digital_version = 1;
    strcpy((*(expected_test + 2))->name, "Zelda");
    (*(expected_test + 2))->pages = 145;
    stpcpy((*(expected_test + 2))->publishing_house, "Ranok");
    (*(expected_test + 2))->cover = SOFT;

    (*(expected_test + 3))->digital_version = 0;
    strcpy((*(expected_test + 3))->name, "It");
    (*(expected_test + 3))->pages = 400;
    stpcpy((*(expected_test + 3))->publishing_house, "Family");
    (*(expected_test + 3))->cover = SOFT;

    (*(expected_test + 4))->digital_version = 0;
    strcpy((*(expected_test + 4))->name, "Bukvar");
    (*(expected_test + 4))->pages = 125;
    stpcpy((*(expected_test + 4))->publishing_house, "Shkola");
    (*(expected_test + 4))->cover = HARD;

    (*(expected_test + 5))->digital_version = 1;
    strcpy((*(expected_test + 5))->name, "Chess");
    (*(expected_test + 5))->pages = 145;
    stpcpy((*(expected_test + 5))->publishing_house, "Ranok");
    (*(expected_test + 5))->cover = HARD;

    (*(expected_test + 6))->digital_version = 1;
    strcpy((*(expected_test + 6))->name, "Snail");
    (*(expected_test + 6))->pages = 107;
    stpcpy((*(expected_test + 6))->publishing_house, "Ranok");
    (*(expected_test + 6))->cover = HARD;

    printf("Expected result:\n\n");
    PrintInConsole(expected_test, 7);

    struct books** actual = InsertStruct(books_for_test, insert, 2);

    for (int i = 0; i < NUM_OF_BOOKS + 1; ++i) {
        struct books * buf1 = *(actual + i);
        struct books * buf2 = *(expected_test + i);
        if(buf2->digital_version == buf1->digital_version && buf2->pages == buf1->pages && buf2->cover == buf1->cover){
            result &= true;
        }
        else
        {
            result &= false;
        }
        if(strcmp(buf1->name, buf2->name)==0)
        {
            result &= true;
        }
        else
        {
            result &= false;
        }
        if(strcmp(buf2->publishing_house, buf1->publishing_house) == 0)
        {
            result &= true;
        }
        else
        {
            result &= false;
        }
    }

    for (int i = 0; i < NUM_OF_BOOKS;  ++i)
    {
        free(*(books_for_test + i));
    }
    for (int i = 0; i < NUM_OF_BOOKS - 1;  ++i)
    {
        free(*(expected_test + i));
    }
    for (int i = 0; i < NUM_OF_BOOKS - 1;  ++i)
    {
        free(*(actual + i));
    }
    return result;
}


bool test_delete_struct(){
    bool result = true;

    struct books ** books_for_test = malloc((NUM_OF_BOOKS) * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS; i++){
        *(books_for_test + i) = malloc(sizeof (struct books));
    }

    (*(books_for_test))->digital_version = 1;
    strcpy((*(books_for_test))->name, "Potter");
    (*(books_for_test))->pages = 145;
    stpcpy((*(books_for_test))->publishing_house, "Ranok");
    (*(books_for_test))->cover = HARD;

    (*(books_for_test + 1))->digital_version = 1;
    strcpy((*(books_for_test + 1))->name, "Stranger");
    (*(books_for_test + 1))->pages = 214;
    stpcpy((*(books_for_test + 1))->publishing_house, "Family");
    (*(books_for_test + 1))->cover = SOFT;

    (*(books_for_test + 2))->digital_version = 0;
    strcpy((*(books_for_test + 2))->name, "It");
    (*(books_for_test + 2))->pages = 400;
    stpcpy((*(books_for_test + 2))->publishing_house, "Family");
    (*(books_for_test + 2))->cover = SOFT;

    (*(books_for_test + 3))->digital_version = 0;
    strcpy((*(books_for_test + 3))->name, "Bukvar");
    (*(books_for_test + 3))->pages = 112;
    stpcpy((*(books_for_test + 3))->publishing_house, "Shkola");
    (*(books_for_test + 3))->cover = HARD;

    (*(books_for_test + 4))->digital_version = 1;
    strcpy((*(books_for_test + 4))->name, "Chess");
    (*(books_for_test + 4))->pages = 135;
    stpcpy((*(books_for_test + 4))->publishing_house, "Ranok");
    (*(books_for_test + 4))->cover = HARD;

    (*(books_for_test + 5))->digital_version = 1;
    strcpy((*(books_for_test + 5))->name, "Chess");
    (*(books_for_test + 5))->pages = 145;
    stpcpy((*(books_for_test + 5))->publishing_house, "Ranok");
    (*(books_for_test + 5))->cover = HARD;



    struct books ** expected_test = malloc((NUM_OF_BOOKS - 1) * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS - 1; i++){
        *(expected_test + i) = malloc(sizeof (struct books));
    }

    (*(expected_test))->digital_version = 1;
    strcpy((*(expected_test))->name, "Potter");
    (*(expected_test))->pages = 145;
    stpcpy((*(expected_test))->publishing_house, "Ranok");
    (*(expected_test))->cover = HARD;

    (*(expected_test + 1))->digital_version = 1;
    strcpy((*(expected_test + 1))->name, "Stranger");
    (*(expected_test + 1))->pages = 214;
    stpcpy((*(expected_test + 1))->publishing_house, "Family");
    (*(expected_test + 1))->cover = SOFT;

    (*(expected_test + 2))->digital_version = 0;
    strcpy((*(expected_test + 2))->name, "Bukvar");
    (*(expected_test + 2))->pages = 112;
    stpcpy((*(expected_test + 2))->publishing_house, "Shkola");
    (*(expected_test + 2))->cover = HARD;

    (*(expected_test + 3))->digital_version = 1;
    strcpy((*(expected_test + 3))->name, "Chess");
    (*(expected_test + 3))->pages = 135;
    stpcpy((*(expected_test + 3))->publishing_house, "Ranok");
    (*(expected_test + 3))->cover = HARD;

    (*(expected_test + 4))->digital_version = 1;
    strcpy((*(expected_test + 4))->name, "Chess");
    (*(expected_test + 4))->pages = 145;
    stpcpy((*(expected_test + 4))->publishing_house, "Ranok");
    (*(expected_test + 4))->cover = HARD;

    printf("Expected result:\n\n");
    PrintInConsole(expected_test, 5);

    struct books** actual = DeleteStruct(books_for_test, 2);

    for (int i = 0; i < NUM_OF_BOOKS - 1; ++i) {
        struct books * buf1 = *(actual + i);
        struct books * buf2 = *(expected_test + i);
        if(buf2->digital_version == buf1->digital_version && buf2->pages == buf1->pages && buf2->cover == buf1->cover){
            result &= true;
        }
        else
        {
            result &= false;
        }
        if(strcmp(buf1->name, buf2->name)==0)
        {
            result &= true;
        }
        else
        {
            result &= false;
        }
        if(strcmp(buf2->publishing_house, buf1->publishing_house) == 0)
        {
            result &= true;
        }
        else
        {
            result &= false;
        }
    }


    for (int i = 0; i < NUM_OF_BOOKS;  ++i) {
        free(*(books_for_test + i));
    }
    for (int i = 0; i < NUM_OF_BOOKS - 1;  ++i) {
        free(*(expected_test + i));
    }


    return result;
}


int main(){
    bool result = true;
    printf("Insert string test\n\n");
    result &= insert_test();
    if (result == true){
        printf("Test result: succeed\n");
    }else{
        printf("Test result:failed\n");
    }
    printf("Delete string test\n\n");
    result &= delete_test();
    if (result == true){
        printf("Test result: succeed\n");
    }else{
        printf("Test result:failed\n");
    }
    printf("Insert struct test\n\n");
    result &= test_insert_struct();
    if (result == true){
        printf("Test result: succeed\n");
    }else{
        printf("Test result:failed\n");
    }
    printf("Delete struct test\n\n");
    result &= test_delete_struct();
    if (result == true){
        printf("Test result: succeed\n");
    }else{
        printf("Test result:failed\n");
    }
    return 0;
}