#include "lib.h"

char * insert_arr(char * arr1, char * arrCenter, size_t index)
{
    char *new_array = malloc((strlen(arr1) + 1) * sizeof(char ));
            memcpy(new_array, arr1, index * sizeof(char));
            memcpy(new_array + index, arrCenter, strlen(arrCenter) * sizeof(char));
            memcpy(new_array + index + strlen(arrCenter), arr1 + index, strlen(arr1) - index);
            *(new_array + strlen(arr1) + strlen(arrCenter)) = '\0';
    return new_array;

}

char * delete_arr(char * arr, size_t start, size_t end)
{

    char * new_array = malloc((strlen(arr) - 1) * sizeof(char ));
    memcpy(new_array, arr, start * sizeof(char ));
    memcpy(new_array + start, arr + end, (strlen(arr) - (end - start)) * sizeof(char ));
    return new_array;

}

void ReadFromFile(struct books **memory_for_books)
{
    FILE *file = fopen("D:\\git\\semester 2\\lab2\\lab15&17\\books.txt", "r");
    if (file == NULL)
    {
        printf("Error due to: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < NUM_OF_BOOKS; i++)
    {
        struct books *product = *(memory_for_books + i);//индекс массива структур
        fscanf(file, "%d %s %s %d",&(product->digital_version), product->name, product->publishing_house, &(product->cover) );
    }

    fclose(file);
}

void GenerateRandomPages(struct books **memory_for_books)
{
    for(int i = 0; i < NUM_OF_BOOKS; i++)
    {
        struct books *product = *(memory_for_books + i);
        product->pages = rand()%134 + 15;
    }
}


struct books** InsertStruct (struct books **memory_for_books, struct books *insert, int index)
{
    struct books ** result = malloc((NUM_OF_BOOKS + 1) * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS + 1; i++)
    {
        *(result + i) = malloc(sizeof (struct books));
    }
    if(index < 0)
    {
        index = 0;
    }
    if(index >= NUM_OF_BOOKS)
    {
        index = NUM_OF_BOOKS;
        memcpy(*result, *memory_for_books, sizeof (struct books) * (index + 1));
        memcpy(*(result + index), insert, sizeof (struct books));
        memcpy(*(result + index + 1), *(memory_for_books + index), sizeof (struct books) * (NUM_OF_BOOKS - index));
    }
    else
    {
        memcpy(*result, *memory_for_books, sizeof (struct books) * (index + 1));
        memcpy(*(result + index), insert, sizeof (struct books));
        memcpy(*(result + index + 1), *(memory_for_books + index), sizeof (struct books) * (NUM_OF_BOOKS - index + 1) + 1);
    }
    printf("\nResult:\n\n");
    PrintInConsole(result, NUM_OF_BOOKS + 1);

    return result;
}

struct books **DeleteStruct (struct books **memory_for_books, int index)
{
    struct books ** result = malloc((NUM_OF_BOOKS - 1) * sizeof (struct books));
    for(int i = 0; i < NUM_OF_BOOKS - 1; i++)
    {
        *(result + i) = malloc(sizeof (struct books));
    }
    if(index < 0)
    {
        index = 0;
    }
    if(index >= NUM_OF_BOOKS - 1)
    {
        index = NUM_OF_BOOKS;
    }
    memcpy(*result, *memory_for_books, sizeof (struct books) * (index + 1));
    memcpy(*(result + index), *(memory_for_books + index + 1), sizeof (struct books) * (NUM_OF_BOOKS - index));

    printf("\nРезульат удаления:\n\n");
    PrintInConsole(result, NUM_OF_BOOKS - 1);

    return result;
}

void PrintInConsole(struct books **memory_for_books, int size){
    for(int i = 0; i < size; i++)
    {
        struct books *buf = *(memory_for_books + i);
        if (buf->digital_version == 1)
        {
            printf("Availability of a digital version: Yes\n");
        }
        else
        {
            printf("Availability of a digital version: NO\n");
        }
        printf("Name: %s\n", buf->name);
        printf("Pages: %d \n", buf->pages);
        printf("Publishing house: %s\n", buf->publishing_house);
        if (buf->cover == HARD)
        {
            printf("Cover: hard\n");
        }
        else if (buf->cover == SOFT)
        {
            printf("Cover: soft\n");
        }
        printf("\n");
    }
}
