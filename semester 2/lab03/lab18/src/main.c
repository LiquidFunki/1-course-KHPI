#include "lib.h"

int main()
{
    char* text1 = malloc(sizeof (char)* 255);
    char* insert_text= malloc(sizeof (char)* 255);
    char* text2 = malloc(sizeof (char)* 255);
    struct books ** memory_for_books = malloc(NUM_OF_BOOKS * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS; i++)
    {
        *(memory_for_books + i) = malloc(sizeof (struct books));
    }


    printf("Enter your string: ");
    scanf("%s", text1);
    printf("Enter the string you want to add: ");
    scanf("%s", insert_text);
    int index;
    printf("Enter the place, after which you want to place your string: ");
    scanf("%i", &index);
    char* result_insert = insert_arr(text1, insert_text, index);
    printf("Result: %s\n\n", result_insert);

    int start_index;
    int end_index;
    printf("Enter your string: ");
    scanf("%s", text2);
    printf("Enter the start index of deleting range: ");
    scanf("%d", &start_index);
    printf("Enter the end index of deleting range: ");
    scanf("%d", &end_index);
    char* result_deleting = delete_arr(text2, start_index, end_index);
    printf("Result: %s\n\n", result_deleting);


    ReadFromFile(memory_for_books);

    GenerateRandomPages(memory_for_books);

    struct books * insert = malloc(sizeof (struct books));

    (insert)->digital_version = 1;
    strcpy(insert->name, "Zelda");
    insert->pages = 145;
    stpcpy(insert->publishing_house, "Ranok");
    insert->cover = HARD;

    printf("Structure, you want to insert:\n\n");
    printf("Availability of digital version: Yes\n");
    printf("Name: %s\n", insert->name);
    printf("Count of pages: %d\n", insert->pages);
    printf("Publishing house: %s\n", insert->publishing_house);
    printf("Cover: hard\n");
    printf("\n");

    int struct_index_insert;
    printf("Enter the index, after which you want to insert the struct: ");
    scanf("%i", &struct_index_insert);

    InsertStruct(memory_for_books, insert, struct_index_insert);

    printf("\nStruct array:\n\n");
    PrintInConsole(memory_for_books, NUM_OF_BOOKS);

    int struct_index_delete;
    printf("Enter the index, after which you want to delete the struct: ");
    scanf("%i", &struct_index_delete);

    DeleteStruct(memory_for_books, struct_index_delete);


    free(result_insert);
    free(text1);
    free(insert_text);
    free(result_deleting);
    free(text2);
    free(insert);
    for (int  i = 0; i < NUM_OF_BOOKS; i++)
    {
        free(*(memory_for_books + i));
    }
    return 0;
}
