#include "list.h"

int main()
{

    struct List *list = NewList();
    ReadListFromFile(list);
    for (int i = 0; i < 44; ++i)
    {
        int marker;
        printf("Menu:\n");
        printf("1. Show list.\n");
        printf("2. Find element.\n");
        printf("3. Delete element.\n");
        printf("4. Sort list.\n");
        printf("5. Insert new element.\n");
        printf("6. Exit.\n");
        printf("\n\n");
        printf("Choose your option: ");
        scanf("%d", &marker);
        printf("\n\n");

        switch (marker)
        {
            case 1:
                printf("Here your list:\n\n");
                ShowList(list);
                printf("\n\n");
                PrintListInFile(list);
                break;
            case 2:
                printf("\n Here is the list with elements you can choose to find by:\n");
                printf("1. Availability of digital version. \n");
                printf("2. Name.\n");
                printf("3. Pages.\n");
                printf("4. Publishing house.\n");
                printf("5. Cover of the book.\n");
                printf("\n\n");
                printf("Choose the element you want to find by: ");
                int number;
                scanf("%d", &number);
                FindBackpack(list, number);
                break;
            case 3:
                printf("\n Enter the index of element you want to delete:\n ");
                int pos;
                scanf("%d", &pos);
                DeleteElement(list, pos);
                printf("Element successfully deleted.\n");
                printf("\n\n");
                break;
            case 4:
                printf("\nOptions for sort\n");
                printf(" 1. Availability of digital version:\n");
                printf("2. Name.\n");
                printf("3. Pages.\n");
                printf("4. Publishing house.\n");
                printf("5. Cover.\n");
                printf("\n\n");
                printf("Choose the option you want to sort by: ");
                int num;
                scanf("%d", &num);
                switch (num) {
                    case 1:
                        SortListByCriterion(list, compareDv);
                        printf("Sorting done successfully.\n");
                        printf("\n\n");
                        break;
                    case 2:
                        SortListByCriterion(list, compareName);
                        printf("Sorting done successfully.\n");
                        printf("\n\n");
                        break;
                    case 3:
                        SortListByCriterion(list, comparePages);
                        printf("Sorting done successfully.\n");
                        printf("\n\n");
                        break;
                    case 4:
                        SortListByCriterion(list, comparePL);
                        printf("Sorting done successfully.\n");
                        printf("\n\n");
                        break;
                    case 5:
                        SortListByCriterion(list, compareCover);
                        printf("Sorting done successfully.\n");
                        printf("\n\n");
                        break;
                    default:
                        printf("ERROR: there is no option like this.\n");
                        printf("\n\n");
                        break;
                }
                break;
            case 5:
                printf("\nInserting element\n");
                printf("\nEnter the values of element you want to insert:\n");
                int dv;
                char name[10];
                int pages;
                char publishing_house[15];
                int cover;
                printf("Availability of digital version(1-yes, 0-no): ");
                scanf("%d", &dv);
                printf("Name of the book: ");
                scanf("%s", name);
                printf("Count of pages: ");
                scanf("%d", &pages);
                printf("Publishing house: ");
                scanf("%s", publishing_house);
                printf("Cover of the book(1-hard, 0-soft): ");
                scanf("%d", &cover);
                printf("\nEnter the position, after which you want to insert the element: ");
                int position;
                scanf("%d", &position);
                InsertElement(list,  position, dv, name ,  pages,  publishing_house,  cover);
                printf("Inserting succeed!");
                printf("\n\n");
                break;
            case 6:
                FreeList(list);
                printf("Have a nice day!\n");
                printf("\n\n");
                return 0;
            default:
                printf("|\tERROR: Wrong option!\n");
                printf("\n\n");
                break;
        }
    }
    FreeList(list);
    return 0;
}