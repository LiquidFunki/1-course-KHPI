#include <../src/lib.h>

bool testSortStructure(){
    struct books ** memory_for_books = malloc(3 * sizeof (struct books));
        for(int i = 0; i < 3; i++){
            *(memory_for_books + i) = malloc(sizeof(struct books));
        }
    (*(memory_for_books))->digital_version = 1;
    strcpy((*(memory_for_books))->name, "Potter");
    (*(memory_for_books))->pages = 156;
    strcpy((*(memory_for_books))->publishing_house, "Ranok");
    (*(memory_for_books))->cover = HARD;

    (*(memory_for_books + 1))->digital_version = 0;
    strcpy((*(memory_for_books + 1))->name, "It");
    (*(memory_for_books + 1))->pages = 132;
    strcpy((*(memory_for_books + 1))->publishing_house, "Family");
    (*(memory_for_books + 1))->cover = SOFT;

    (*(memory_for_books + 2))->digital_version = 1;
    strcpy((*(memory_for_books + 2))->name, "SNAIL");
    (*(memory_for_books + 2))->pages = 72;
    strcpy((*(memory_for_books + 2))->publishing_house, "Family");
    (*(memory_for_books + 2))->cover = SOFT;

    struct books ** expected_digital_version = malloc( 3 * sizeof(struct books));
    for (int i = 0; i < 3; i++){
        *(expected_digital_version + i) = malloc(sizeof(struct books));
    }

    (*(expected_digital_version))->digital_version = 1;
    strcpy((*(expected_digital_version))->name, "Potter");
    (*(expected_digital_version))->pages = 156;
    strcpy((*(expected_digital_version))->publishing_house, "Ranok");
    (*(expected_digital_version))->cover = HARD;

    (*(expected_digital_version + 1))->digital_version = 1;
    strcpy((*(expected_digital_version + 1))->name, "SNAIL");
    (*(expected_digital_version + 1))->pages = 72;
    strcpy((*(expected_digital_version + 1))->publishing_house, "Family");
    (*(expected_digital_version + 1))->cover = SOFT;

    (*(expected_digital_version + 2))->digital_version = 0;
    strcpy((*(expected_digital_version + 2))->name, "It");
    (*(expected_digital_version + 2))->pages = 132;
    strcpy((*(expected_digital_version + 2))->publishing_house, "Family");
    (*(expected_digital_version + 2))->cover = SOFT;

    struct books ** expected_name = malloc( 3 * sizeof(struct books));
    for (int i = 0; i < 3; i++){
        *(expected_name + i) = malloc(sizeof(struct books));
    }

    (*(expected_name))->digital_version = 1;
    strcpy((*(expected_name))->name, "SNAIL");
    (*(expected_name))->pages = 72;
    strcpy((*(expected_name))->publishing_house, "Family");
    (*(expected_name))->cover = SOFT;

    (*(expected_name + 1))->digital_version = 1;
    strcpy((*(expected_name + 1))->name, "Potter");
    (*(expected_name + 1))->pages = 156;
    strcpy((*(expected_name + 1))->publishing_house, "Ranok");
    (*(expected_name + 1))->cover = HARD;

    (*(expected_name + 2))->digital_version = 0;
    strcpy((*(expected_name + 2))->name, "It");
    (*(expected_name + 2))->pages = 132;
    strcpy((*(expected_name + 2))->publishing_house, "Family");
    (*(expected_name + 2))->cover = SOFT;

    struct books ** expected_pages = malloc( 3 * sizeof(struct books));
    for (int i = 0; i < 3; i++){
        *(expected_pages + i) = malloc(sizeof(struct books));
    }

    (*(expected_pages))->digital_version = 1;
    strcpy((*(expected_pages))->name, "Potter");
    (*(expected_pages))->pages = 156;
    strcpy((*(expected_pages))->publishing_house, "Ranok");
    (*(expected_pages))->cover = HARD;

    (*(expected_pages + 1))->digital_version = 0;
    strcpy((*(expected_pages + 1))->name, "It");
    (*(expected_pages + 1))->pages = 132;
    strcpy((*(expected_pages + 1))->publishing_house, "Family");
    (*(expected_pages + 2))->cover = SOFT;

    (*(expected_pages + 2))->digital_version = 1;
    strcpy((*(expected_pages + 2))->name, "SNAIL");
    (*(expected_pages + 2))->pages = 72;
    strcpy((*(expected_pages + 2))->publishing_house, "Family");
    (*(expected_pages + 2))->cover = SOFT;

    struct books ** expected_publishing_house = malloc( 3 * sizeof(struct books));
    for (int i = 0; i < 3; i++){
        *(expected_publishing_house + i) = malloc(sizeof(struct books));
    }

    (*(expected_publishing_house))->digital_version = 1;
    strcpy((*(expected_publishing_house))->name, "Potter");
    (*(expected_publishing_house))->pages = 156;
    strcpy((*(expected_publishing_house))->publishing_house, "Ranok");
    (*(expected_publishing_house))->cover = HARD;

    (*(expected_publishing_house + 1))->digital_version = 1;
    strcpy((*(expected_publishing_house + 1))->name, "SNAIL");
    (*(expected_publishing_house + 1))->pages = 72;
    strcpy((*(expected_publishing_house + 1))->publishing_house, "Family");
    (*(expected_publishing_house + 1))->cover = SOFT;

    (*(expected_publishing_house + 2))->digital_version = 0;
    strcpy((*(expected_publishing_house + 2))->name, "It");
    (*(expected_publishing_house + 2))->pages = 132;
    strcpy((*(expected_publishing_house + 2))->publishing_house, "Family");
    (*(expected_publishing_house + 2))->cover = SOFT;

    struct books ** expected_cover = malloc( 3 * sizeof(struct books));
    for (int i = 0; i < 3; i++){
        *(expected_cover + i) = malloc(sizeof(struct books));
    }

    (*(expected_cover))->digital_version = 0;
    strcpy((*(expected_cover))->name, "It");
    (*(expected_cover))->pages = 132;
    strcpy((*(expected_cover))->publishing_house, "Family");
    (*(expected_cover))->cover = SOFT;

    (*(expected_cover + 1))->digital_version = 1;
    strcpy((*(expected_cover + 1))->name, "SNAIL");
    (*(expected_cover + 1))->pages = 72;
    strcpy((*(expected_cover + 1))->publishing_house, "Family");
    (*(expected_cover + 1))->cover = SOFT;

    (*(expected_cover + 2))->digital_version = 1;
    strcpy((*(expected_cover + 2))->name, "Potter");
    (*(expected_cover + 2))->pages = 156;
    strcpy((*(expected_cover + 2))->publishing_house, "Ranok");
    (*(expected_cover + 2))->cover = HARD;

    char option1[20] = "digital_version";
    char option2[20] = "name";
    char option3[20] = "pages";
    char option4[20] = "publishing_house";
    char option5[20] = "cover";

    bool result = true;

    Sort(memory_for_books, option1, 3);
    for( int i = 0; i < 3; i++){
        if((*(memory_for_books + i))->digital_version == (*(expected_digital_version + i))->digital_version){
            result &= true;
        }
        else{
            result &= false;
        }
    }

    Sort(memory_for_books, option2, 3);
    for( int i = 0; i < 3; i++){
        if((*(memory_for_books + i))->name == (*(expected_name + i))->name){
            result &= true;
        }
        else{
            result &= false;
        }
    }

    Sort(memory_for_books, option3, 3);
    for( int i = 0; i < 3; i++){
        if((*(memory_for_books + i))->pages == (*(expected_pages + i))->pages){
            result &= true;
        }
        else{
            result &= false;
        }
    }

    Sort(memory_for_books, option4, 3);
    for( int i = 0; i < 3; i++){
        if((*(memory_for_books + i))->publishing_house == (*(expected_publishing_house + i))->publishing_house){
            result &= true;
        }
        else{
            result &= false;
        }
    }

    Sort(memory_for_books, option5, 3);
    for( int i = 0; i < 3; i++){
        if((*(memory_for_books + i))->cover == (*(expected_cover + i))->cover){
            result &= true;
        }
        else{
            result &= false;
        }
    }

    for (int  i = 0; i < 3; i++){
        free(*(memory_for_books + i));
    }
    for (int  i = 0; i < 3; i++){
        free(*(expected_digital_version + i));
    }
    for (int  i = 0; i < 3; i++){
        free(*(expected_name + i));
    }
    for (int  i = 0; i < 3; i++){
        free(*(expected_pages + i));
    }
    for (int  i = 0; i < 3; i++){
        free(*(expected_publishing_house + i));
    }
    for (int  i = 0; i < 3; i++){
        free(*(expected_cover + i));
    }

    return result;

}
bool testFindPublishingHouse() {

    struct books ** memory_for_books = malloc(3 * sizeof (struct books));
    for(int i = 0; i < 3; i++){
        *(memory_for_books + i) = malloc(sizeof(struct books));
    }

    (*(memory_for_books))->digital_version = 1;
    strcpy((*(memory_for_books))->name, "Potter");
    (*(memory_for_books))->pages = 156;
    strcpy((*(memory_for_books))->publishing_house, "Ranok");
    (*(memory_for_books))->cover = HARD;

    (*(memory_for_books + 1))->digital_version = 0;
    strcpy((*(memory_for_books + 1))->name, "It");
    (*(memory_for_books + 1))->pages = 132;
    strcpy((*(memory_for_books + 1))->publishing_house, "Family");
    (*(memory_for_books + 1))->cover = SOFT;

    (*(memory_for_books + 2))->digital_version = 1;
    strcpy((*(memory_for_books + 2))->name, "SNAIL");
    (*(memory_for_books + 2))->pages = 72;
    strcpy((*(memory_for_books + 2))->publishing_house, "Family");
    (*(memory_for_books + 2))->cover = SOFT;

    struct books *expected = malloc(sizeof(struct books));

    expected->digital_version = 1;
    strcpy(expected->name, "Potter");
    expected->pages = 156;
    strcpy(expected->publishing_house, "Ranok");
    expected->cover = HARD;

    struct books *true_struct = FindPublishingHouse(memory_for_books, 3);

    if (strcmp(true_struct->publishing_house, expected->publishing_house) == 0) {
        result = true;
    } else {
        result = false;
    }

    for (int  i = 0; i < 3; i++){
        free(*(memory_for_books + i));
    }

    free(expected);
    free(true_struct);

    return result;
}

int main()
{
    bool test = true;
    test &= testSortStructure();
    test &= testFindPublishingHouse();
    if (test){
        printf("All tests got success\n");
    }else{
        printf("All or some of tests got failed\n");
    }
    return test;
}