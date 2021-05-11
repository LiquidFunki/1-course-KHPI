#include "data.h"

void ReadFromFile(struct books **memory_for_books) {
    FILE *file = fopen("D:\\git2\\semester 2\\lab3\\lab19\\books.txt", "r");
    char digital;
    char n[15];
    char ph[15];
    char c;
    char p[4];
    if (file == NULL) {
        printf("Error due to: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < NUM_OF_BOOKS; i++) {
        struct books *product = *(memory_for_books + i);//индекс массива структур
        fscanf(file, "%d %s %d %d %s",&(product->digital_version), product->publishing_house, &(product->book_cover), &(product->pages), product->name);
    }

    fclose(file);
}




//void GenerateRandomPages(struct books **memory_for_books){
//    for(int i = 0; i < NUM_OF_BOOKS; i++){
//        struct books *product = *(memory_for_books + i);
//        product->pages = rand()%134 + 15;
//    }
//}

struct books* FindPublishingHouse(struct books **memory_for_books, int size) {
    int temp;
    char str1[15] = "Ranok";
    for (int i = 0; i < size; i++) {
        struct books *product = *(memory_for_books + i);
        if (strcmp(str1, product->publishing_house) == 0) {
            temp = i;
            if (product->digital_version == 1) {
                printf("Does this book have digital version?: Yes\n");
            } else {
                printf("Does this book have digital version?: NO\n");
            }
            printf("Name: %s\n", product->name);
            printf("Pages: %d \n", product->pages);
            printf("Publishing House: %s\n", product->publishing_house);
            if (product->book_cover == HARD) {
                printf("Cover of book: hard\n");
            } else if (product->book_cover == SOFT) {
                printf("Cover of book: soft\n");
                printf("\n");
            }
        }
        printf("\n");
    }
    return *(memory_for_books + temp);
}

void Sort(struct books **memory_for_books, char user_option[20], int size) {
    char option1[20] = "digital_version";
    char option2[20] = "name";
    char option3[20] = "pages";
    char option4[20] = "publishing_house";
    char option5[20] = "cover";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            //struct books *memory_for_books = *(memory_for_books + i);
            if (strcmp(user_option, option1) == 0) {
                if(memory_for_books[j]->digital_version < memory_for_books[j+1]->digital_version){
                    struct books *temp = *(memory_for_books + j);
                    *(memory_for_books + j) = *(memory_for_books + j + 1);
                    *(memory_for_books + j + 1) = temp;
                }

            } else if (strcmp(user_option, option2) == 0) {
                if (strcmp(memory_for_books[j]->name, memory_for_books[j + 1]->name) == 0 &&
                    strcmp(memory_for_books[j]->name, memory_for_books[j + 1]->name) > 0) {
                    continue;
                } else if (strcmp(memory_for_books[j]->name, memory_for_books[j + 1]->name) < 0) {
                    struct books *temp = *(memory_for_books + j);
                    *(memory_for_books + j) = *(memory_for_books + j + 1);
                    *(memory_for_books + j + 1) = temp;
                }
            } else if (strcmp(user_option, option3) == 0) {
                if(memory_for_books[j]->pages < memory_for_books[j+1]->pages){
                    struct books *temp = *(memory_for_books + j);
                    *(memory_for_books + j) = *(memory_for_books + j + 1);
                    *(memory_for_books + j + 1) = temp;
                }
            } else if (strcmp(user_option, option4) == 0) {
                if (strcmp(memory_for_books[j]->publishing_house, memory_for_books[j + 1]->publishing_house) == 0 &&
                    strcmp(memory_for_books[j]->publishing_house, memory_for_books[j + 1]->publishing_house) > 0) {
                    continue;
                } else if (strcmp(memory_for_books[j]->publishing_house, memory_for_books[j + 1]->publishing_house) < 0) {
                    struct books *temp = *(memory_for_books + j);
                    *(memory_for_books + j) = *(memory_for_books + j + 1);
                    *(memory_for_books + j + 1) = temp;
                }
            } else if (strcmp(user_option, option5) == 0) {
                if(memory_for_books[j]->book_cover < memory_for_books[j+1]->book_cover){
                    struct books *temp = *(memory_for_books + j);
                    *(memory_for_books + j) = *(memory_for_books + j + 1);
                    *(memory_for_books + j + 1) = temp;
                }
            }
        }
    }
}



void PutInConsole(struct books **memory_for_books){
    for (int j = 0; j < 6; j++) {
        struct books *product = *(memory_for_books + j);

        if (product->digital_version == 1) {
            printf("\tDoes this book have digital version?: Yes\n");
        } else {
            printf("\tDoes this book have digital version?: NO\n");
        }
        printf("\tName: %s\n", product->name);
        printf("\tPages: %d\n", product->pages);
        printf("\tPublishing House: %s\n", product->publishing_house);
        switch (product->book_cover ) {
            case HARD: printf("\tCover: hard\n\n");
                break;
            case SOFT: printf("\tCover: soft\n\n");
                break;
        }

    }
}

void PutInFile(struct books **memory_for_books){
    FILE *file = fopen("D:\\git\\semester 2\\lab2\\lab15&17\\booksout.txt", "w");
    for (int j = 0; j < 6; j++) {
        struct books *product = *(memory_for_books + j);

        if (product->digital_version == 1) {
            fprintf(file,"Does this book have digital version?: Yes\n");
        } else {
            fprintf(file,"Does this book have digital version?: NO\n");
        }
        fprintf(file,"\tName: %s\n", product->name);
        fprintf(file,"\tPages: %d\n", product->pages);
        fprintf(file,"\tPublishing House: %s\n", product->publishing_house);
        switch (product->book_cover ) {
            case HARD: fprintf(file,"\tCover: hard\n\n");
                break;
            case SOFT: fprintf(file,"\tCover: soft\n\n");
                break;
        }
    }
    fclose(file);
}


