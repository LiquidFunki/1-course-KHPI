#include "lib.h"

int main(){
    struct books ** memory_for_books = malloc(NUM_OF_BOOKS * sizeof(struct books* ));
    for (int i = 0; i < NUM_OF_BOOKS; i++) {
        *(memory_for_books + i) = malloc(sizeof(struct books));
    }

    ReadFromFile(memory_for_books);

    GenerateRandomPages(memory_for_books);

    FindPublishingHouse(memory_for_books, NUM_OF_BOOKS);

    char user_option[20];
    printf("Enter the option you want to sort by: ");
    scanf( "%s" ,user_option);
    Sort(memory_for_books, user_option, NUM_OF_BOOKS);

    PutInConsole(memory_for_books);

    PutInFile(memory_for_books);

    for (int i = 0; i < NUM_OF_BOOKS; i++){
        free(*(memory_for_books + i));
    }
}