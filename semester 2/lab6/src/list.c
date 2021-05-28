#include "list.h"


struct List *NewList()
{
    struct List *list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

struct BookList *NewBookList(int dv, char n[15], int pg, char ph[15], int cvr)
{
    struct BookList *book = malloc(sizeof(struct BookList));
    book->digital_version = dv;

    for (int i = 0; i < 15; ++i)
    {
        book->name[i] = n[i];
    }
    book->pages = pg;

    for (int i = 0; i < 15; ++i)
    {
        book->publishing_house[i] = ph[i];
    }
    book->book_cover = cvr;
    book->next = NULL;
    book->prev = NULL;
    return book;
}

void AddElementEnd(struct List *list, int dv, char n[15], int pg, char ph[15], int cvr)
{
    struct BookList *book = NewBookList(dv, n, pg, ph, cvr);

    book->prev = list->tail;
    if (list->tail)
    {
        list->tail->next = book;
    }
    else
    {
        list->head = book; //???
    }
    list->tail = book;
}

void AddElementBegin(struct List *list, int dv, char n[15], int pg, char ph[15], int cvr)
{
    struct BookList *book = NewBookList(dv, n, pg, ph, cvr);
    book->next = list->head;
    if(list->head)
    {
        list->head->prev = book;
    }
    else
    {
        list->tail = book;//???
    }
    list->head = book;
}

void InsertElement(struct List *list, int pos, int dv, char n[15], int pg, char ph[15], int cvr, int key)
{
    if(key == 0) {
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("%s", __FUNCTION__);
        log_info("Time & Date: %s", asctime (TimeInfo));
    }

    struct BookList *p = list->head;
    for(int i = pos; i > 0; i--)
    {
        if(!p)
        {
            AddElementEnd(list, dv, n, pg, ph, cvr);
            return;
        }
        p = p->next;
    }
    struct BookList * book = NewBookList(dv, n, pg, ph, cvr);
    book->prev = p->prev;
    book->next = p;
    book->next->prev = book;//?
    book->prev->next = book;
}

void DeleteElement(struct List *list, int pos, int key)
{
    if(key == 0) {
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("%s", __FUNCTION__);
        log_info("Time & Date: %s", asctime (TimeInfo));
    }

    struct BookList *p = list->head;
    for(int i = pos; i > 0; i--)//?????????
    {
        if(!p)
        {
            return;
        }
        p = p->next;
    }
    p->prev->next = p->next;
    if(p->next)
    {
        p->next->prev = p->prev;
    }
    else
    {
        list->tail = p->prev;
    }
    free(p);
}

void ReadList(struct List* list)
{

    for(int i = 0; i < NUM_OF_BOOKS; i++)
    {
        char dv[5];
        char n[15];
        char pg[10];
        char ph[15];
        char cvr[5];
        scanf("%s %s %s %s %s", dv, n, pg, ph, cvr );
        if( checker(dv, n, pg, ph, cvr) == true ){
            AddElementEnd(list, atoi(dv) , n , atoi(pg) ,ph ,atoi(cvr));
        }
    }
//    fclose(file);
}

bool checker(char dv[], char n[], char pg[], char ph[], char cvr[]){
    bool result = true;
    regex_t regex;
    int return_valueA = regcomp(&regex, "^[0-1]$", 0);
    return_valueA = regexec(&regex, dv, 0, NULL, 0);
    if (return_valueA != 0) {
        result &= false;
    }
    int return_valueB = regcomp(&regex, "^[A-Z][a-zA-Z]+([.][A-Z][a-zA-Z]+)*$", REG_EXTENDED);
    return_valueB = regexec(&regex, n, 0, NULL, 0);
    if (return_valueB != 0){
        result &= false;
    }
    int return_valueC = regcomp(&regex, "^[0-9]{1,4}$", REG_EXTENDED);
    return_valueC = regexec(&regex, pg, 0, NULL, 0);
    if (return_valueC != 0){
        result &= false;
    }
    int return_valueD = regcomp(&regex, "^[A-Z][a-zA-Z]+([.][A-Z][a-zA-Z]+)*$", REG_EXTENDED);
    return_valueD = regexec(&regex, ph, 0, NULL, 0);
    if (return_valueD != 0){
        result &= false;
    }
    int return_valueE = regcomp(&regex, "^[0-1]$", 0);
    return_valueE = regexec(&regex, cvr, 0, NULL, 0);
    if (return_valueE != 0) {
        result &= false;
    }
    return result;
}
void PrintFieldWithTwoWords(struct List *list){
    for (struct BookList *book = list->head; book != NULL; book = book->next) {
        regex_t regex;
        int return_value = regcomp(&regex, "^[A-Z][a-zA-Z]+[.][A-Z][a-zA-Z]+([.][A-Z][a-zA-Z]+)*$", REG_EXTENDED);
        return_value = regexec(&regex, book->name, 0, NULL, 0);
        if (return_value == 0) {
            if (book->digital_version == 1)
            {
                printf("Availability of a digital version: Yes\n");
            }
            else
            {
                printf("Availability of a digital version: NO\n");
            }
            printf("name: %s\n", book->name);
            printf("pages: %d\n", book->pages);
            printf("Publishing house: %s\n", book->publishing_house);
            if (book->book_cover == HARD)
            {
                printf("Cover of the book: hard\n");
            }
            else if (book->book_cover == SOFT)
            {
                printf("Cover of the book: soft\n");
            }
            printf("\n");
        }
    }
}
//Harry.Potter
void ShowList(struct List *list, int key)
{
    if(key == 0) {
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("%s", __FUNCTION__);
        log_info("Time & Date: %s", asctime (TimeInfo));
    }
        for (struct BookList *book = list->head; book != NULL; book = book->next)
        {
            if (book->digital_version == 1)
            {
                printf("Availability of a digital version: Yes\n");
            }
            else
            {
                printf("Availability of a digital version: NO\n");
            }
            printf("name: %s\n", book->name);
            printf("pages: %d\n", book->pages);
            printf("Publishing house: %s\n", book->publishing_house);
            if (book->book_cover == HARD)
            {
                printf("Cover of the book: hard\n");
            }
            else if (book->book_cover == SOFT)
            {
                printf("Cover of the book: soft\n");
            }
            printf("\n");
        }
//    else
//    {
//        for (struct BookList *book = list->tail; book != NULL; book = book->prev)
//        {
//            if (book->digital_version == 1)
//            {
//                printf("\tAvailability of a laptop department: \tYes\n");
//            }
//            else
//            {
//                printf("\tAvailability of a laptop department: \tNO\n");
//            }
//            printf("\tname: \t\t\t\t\t\t\t\t\t%s\n", book->name);
//            printf("\tpages: \t\t\t\t\t\t\t\t%d liter(s)\n", book->pages);
//            printf("\tProducing publishing_house: \t\t\t\t\t\t%s\n", book->publishing_house);
//            if (book->book_cover == URBAN)
//            {
//                printf("\tThe purpose: \t\t\t\t\t\t\tcity book\n");
//            }
//            else if (book->book_cover == TACTICAL)
//            {
//                printf("\tThe purpose: \t\t\t\t\t\t\ttactical book\n");
//            }
//            else if (book->book_cover == TOURIST)
//            {
//                printf("\tThe purpose: \t\t\t\t\t\t\ttravel book\n");
//            }
//            printf("\n");
//        }
//    }
}

void PrintListInFile(struct List *list)
{
    FILE *file = fopen("D:\\git2\\semester 2\\lab3\\lab19\\booksout.txt", "w");
    if (file == NULL)
    {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
        for (struct BookList *book = list->head; book != NULL; book = book->next)
        {
            if (book->digital_version == 1)
            {
                fprintf(file, "Availability of a digital version: Yes\n");
            }
            else
            {
                fprintf(file, "Availability of a digital version: NO\n");
            }
            fprintf(file, "name: %s\n", book->name);
            fprintf(file, "pages: %d\n", book->pages);
            fprintf(file, "Publishing house: %s\n", book->publishing_house);
            if (book->book_cover == HARD)
            {
                fprintf(file, "Cover of the book: hard\n");
            }
            else if (book->book_cover == SOFT)
            {
                fprintf(file, "Cover of the book: soft\n");
            }
            fprintf(file, "\n");
        }

//    else
//    {
//        for (struct BookList *book = list->tail; book != NULL; book = book->prev)
//        {
//            if (book->digital_version == 1)
//            {
//                fprintf(file, "\tAvailability of a laptop department: \tYes\n");
//            }
//            else
//            {
//                fprintf(file, "\tAvailability of a laptop department: \tNO\n");
//            }
//            fprintf(file, "\tname: \t\t\t\t\t\t\t\t\t%s\n", book->name);
//            fprintf(file, "\tpages: \t\t\t\t\t\t\t\t%d liter(s)\n", book->pages);
//            fprintf(file, "\tProducing publishing_house: \t\t\t\t\t\t%s\n", book->publishing_house);
//            if (book->book_cover == URBAN)
//            {
//                fprintf(file, "\tThe purpose: \t\t\t\t\t\t\tcity book\n");
//            }
//            else if (book->book_cover == TACTICAL)
//            {
//                fprintf(file, "\tThe purpose: \t\t\t\t\t\t\ttactical book\n");
//            }
//            else if (book->book_cover == TOURIST)
//            {
//                fprintf(file,"\tThe purpose: \t\t\t\t\t\t\ttravel book\n");
//            }
//            printf("\n");
//        }
//    }
    fclose(file);
}

void FindBook(struct List * list, int index, int key)
{
    if(key == 0) {
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("%s", __FUNCTION__);
        log_info("Time & Date: %s", asctime (TimeInfo));
    }
    int temp = 0;
    char name[15];
    char publishing_house[15];
    int pages;
    int cover;
    switch (index)
    {
        case 1:
            printf("\nРезультат поиска:\n\n");
            for (struct BookList *book = list->head; book != NULL; book = book->next)
            {
                if (book->digital_version == 1)
                {
                    temp = 1;
                    if (book->digital_version == 1)
                    {
                        printf("Availability of a digital version: Yes\n");
                    }
                    else
                    {
                        printf("Availability of a digital version: NO\n");
                    }
                    printf("name: %s\n", book->name);
                    printf("pages: %d\n", book->pages);
                    printf("Publishing house: %s\n", book->publishing_house);
                    if (book->book_cover == HARD)
                    {
                        printf("Cover of the book: hard\n");
                    }
                    else if (book->book_cover == SOFT)
                    {
                        printf("Cover of the book: soft\n");
                    }
                    printf("\n");
                }
            }
            break;
        case 2:
            printf("Enter the name you want to find by: ");
            scanf("%s", name);
            printf("\n");
            printf("Result:\n\n");
            for (struct BookList *book = list->head; book != NULL; book = book->next)
            {
                if (strcmp(book->name, name) == 0)
                {
                    temp = 1;
//                    printf("\tAvailability of a laptop department: \tYes\n");
//                    printf("\tname: \t\t\t\t\t\t\t\t\t%s\n", book->name);
//                    printf("\tpages: \t\t\t\t\t\t\t\t%d liter(s)\n", book->pages);
//                    printf("\tProducing publishing_house: \t\t\t\t\t\t%s\n", book->publishing_house);
//                    if (book->book_cover == URBAN)
//                    {
//                        printf("\tThe purpose: \t\t\t\t\t\t\tcity book\n");
//                    }
//                    else if (book->book_cover == TACTICAL)
//                    {
//                        printf("\tThe purpose: \t\t\t\t\t\t\ttactical book\n");
//                    }
//                    printf("\n");
                    if (book->digital_version == 1)
                    {
                        printf("Availability of a digital version: Yes\n");
                    }
                    else
                    {
                        printf("Availability of a digital version: NO\n");
                    }
                    printf("name: %s\n", book->name);
                    printf("pages: %d\n", book->pages);
                    printf("Publishing house: %s\n", book->publishing_house);
                    if (book->book_cover == HARD)
                    {
                        printf("Cover of the book: hard\n");
                    }
                    else if (book->book_cover == SOFT)
                    {
                        printf("Cover of the book: soft\n");
                    }
                    printf("\n");
                }
            }
            break;

        case 3:
            printf("Enter the count of pages you want to find by: ");
            scanf("%d", &pages);
            printf("\n");
            printf("Result:\n\n");
            for (struct BookList *book = list->head; book != NULL; book = book->next)
            {
                if (book->pages == pages)
                {
                    temp = 1;
                    if (book->digital_version == 1)
                    {
                        printf("Availability of a digital version: Yes\n");
                    }
                    else
                    {
                        printf("Availability of a digital version: NO\n");
                    }
                    printf("name: %s\n", book->name);
                    printf("pages: %d\n", book->pages);
                    printf("Publishing house: %s\n", book->publishing_house);
                    if (book->book_cover == HARD)
                    {
                        printf("Cover of the book: hard\n");
                    }
                    else if (book->book_cover == SOFT)
                    {
                        printf("Cover of the book: soft\n");
                    }
                    printf("\n");
                }
            }
            break;
        case 4:
            printf("Enter the publishing house, you want to find by: ");
            scanf("%s", publishing_house);
            printf("\n");
            printf("Result:\n\n");
            for (struct BookList *book = list->head; book != NULL; book = book->next)
            {
                if (strcmp(book->publishing_house, publishing_house) == 0)
                {
                    temp = 1;
                    if (book->digital_version == 1)
                    {
                        printf("Availability of a digital version: Yes\n");
                    }
                    else
                    {
                        printf("Availability of a digital version: NO\n");
                    }
                    printf("name: %s\n", book->name);
                    printf("pages: %d\n", book->pages);
                    printf("Publishing house: %s\n", book->publishing_house);
                    if (book->book_cover == HARD)
                    {
                        printf("Cover of the book: hard\n");
                    }
                    else if (book->book_cover == SOFT)
                    {
                        printf("Cover of the book: soft\n");
                    }
                    printf("\n");
                }
            }
            break;
        case 5:
            printf("Enter the cover of the book you want to find by: ");
            scanf("%d", &cover);
            printf("\n");
            printf("Result:\n\n");
            for (struct BookList *book = list->head; book != NULL; book = book->next)
            {
                if (book->book_cover == cover)
                {
                    temp = 1;
                    if (book->digital_version == 1)
                    {
                        printf("Availability of a digital version: Yes\n");
                    }
                    else
                    {
                        printf("Availability of a digital version: NO\n");
                    }
                    printf("name: %s\n", book->name);
                    printf("pages: %d\n", book->pages);
                    printf("Publishing house: %s\n", book->publishing_house);
                    if (book->book_cover == HARD)
                    {
                        printf("Cover of the book: hard\n");
                    }
                    else if (book->book_cover == SOFT)
                    {
                        printf("Cover of the book: soft\n");
                    }
                    printf("\n");
                }
            }
            break;
        default:
            printf("\tERROR:There is no such an option\n\n");
            temp = 1;
            break;
    }

    if(temp == 0)
    {
        printf("\tERROR: There is no such a book.\n\n");
    }
}


int compareDv(struct BookList* a, struct BookList* b)
{
    if (a->digital_version == b->digital_version)
        return 0;
    else if (a->digital_version > b->digital_version)
        return 1;
    else
        return -1;
}

int compareName(struct BookList* a, struct BookList* b)
{
    if(strcmp(a->name, b->name) == 0)
        return 0;
    else if (strcmp(a->name, b->name) > 0)
        return 1;
    else
        return -1;
}


int comparePages(struct BookList* a, struct BookList* b)
{
    if (a->pages == b->pages)
        return 0;
    else if (a->pages > b->pages)
        return 1;
    else
        return -1;
}

int comparePL(struct BookList* a, struct BookList* b)
{
    if(strcmp(a->publishing_house, b->publishing_house) == 0)
        return 0;
    else if (strcmp(a->publishing_house, b->publishing_house) > 0)
        return 1;
    else
        return -1;
}

int compareCover(struct BookList* a, struct BookList* b)
{
    if (a->book_cover == b->book_cover)
        return 0;
    else if (a->book_cover > b->book_cover)
        return 1;
    else
        return -1;
}

void SortListByCriterion(struct List *list, int(*compare)(struct BookList*, struct BookList*), int key)
{
    if(key == 0) {
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("%s", __FUNCTION__);
        log_info("Time & Date: %s", asctime (TimeInfo));
    }
    struct BookList *set = list->tail;
    while (set != list->head)
    {
        struct BookList *p = list->head->next;
        struct BookList *max = list->head;
        while (p != set->next)
        {
            if (compare(p, max) >= 0)
                max = p;
            p = p->next;
        }
        if (set == max)
        {
            set = max->prev;
            continue;
        }
        else if (max == list->head && set == list->tail)
        {
            list->head = set;
            list->tail = max;
            list->head->next = list->tail->next;
            list->tail->prev = list->head->prev;
            list->head->next->prev = list->head;
            list->tail->prev->next = list->tail;
            list->head->prev = NULL;
            list->tail->next = NULL;
        }
        else if (max == list->head)
        {
            list->head = set;
            max->prev = list->head->prev;
            list->head->prev = NULL;
            max->prev->next = max;
            struct BookList *t = max->next;
            max->next = list->head->next;
            list->head->next = t;
            max->next->prev = max;
            list->head->next->prev = list->head;
        }
        else if (set == list->tail)
        {
            list->tail = max;
            set->next = list->tail->next;
            list->tail->next = NULL;
            set->next->prev = set;
            struct BookList *t = set->prev;
            set->prev = list->tail->prev;
            list->tail->prev = t;
            set->prev->next = set;
            list->tail->prev->next = list->tail;
        }
        else
        {
            struct BookList *t = max->next;
            max->next = set->next;
            set->next = t;
            max->next->prev = max;
            set->next->prev = set;
            t = max->prev;
            max->prev = set->prev;
            set->prev = t;
            max->prev->next = max;
            set->prev->next = set;
        }
        set = max->prev;
    }
}

void FreeList(struct List *list, int key)
{
    if(key == 0) {
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("%s", __FUNCTION__);
        log_info("Time & Date: %s", asctime (TimeInfo));
    }
    while (list->head)
    {
        struct BookList *p = list->head;
        list->head = p->next;
        free(p);
    }
    free(list);
}
