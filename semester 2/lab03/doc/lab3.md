# Лабораторна робота №3. Динамічні масиви. Динамічні списки

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 12-квітня-2021

### 1.2 Загальне завдання

1. **Розробити** функцію, яка зчитує список з файлу

2. **Розробити** функцію, яка записує дані(список) у файлу;

3. **Розробити** функцію, яка виводить список на екран;

4. **Розробити** функцію, яка буде сортувати список за заданим критерієм;

5. **Розробити** функцію, яка буде знаходити заданий елемент у списку;

6. **Розробити** функцію, яка видаляє елемент зі списку;

7. **Розробити** функцію, яка вставляє новий елемент по індексу;

8. **Реалізувати** діалоговий режим спілкування з користувачем
* **Розробити** функцію, яка зчитує список з файлу

* **Розробити** функцію, яка записує дані(список) у файлу;

* **Розробити** функцію, яка виводить список на екран;

* **Розробити** функцію, яка буде сортувати список за заданим критерієм;

* **Розробити** функцію, яка буде знаходити заданий елемент у списку;

* **Розробити** функцію, яка видаляє елемент зі списку;

* **Розробити** функцію, яка вставляє новий елемент по індексу;

### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту

## 2. Опис програми на основі динамічних масивів

### 2.1 Функціональне призначення

За допомогою розроблених функцій вставляється рядок в рядок, видаляється рядок з рядка, вставляється та видаляється структура з масиву структур.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції: `insert_arr`, виконує вставку рядка в рядок, `delete_arr`виконує видалення рядка з рядка,`InsertStruct` виконує вставку структури в масив структур,  `DeleteStruct` видаляє структуру з масиву структур.`FindBook` знаходить книгу за заданим критерієм.

_Головна функція_`main()`. Викликає розроблені функції .

_Функція вставки_ `insert_arr`. Функція приймає два рядки, та позицію, на яку вставляти рядок. Повертає новий рядок .

_Функція `delete_arr`. Функція приймає текст, та позицію для видалення з нього рядка. Повертає новий рядок.

_Функція_ `InsertStruct`. Функція приймає масив структур, в який треба вставити нову структуру, структуру, яку буде поставлено та позиція на яку вставити структуру.

_Функція_ `DeleteStruct`. Функція приймає масив структур, з якого треба видалити структуру та позицію з якої треба видалити структуру структуру.

_Функція_ `FindBook`. Функція здійснює пошук книги за заданим критерієм(рис.1).

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/func_lab_3.png?raw=true)

Рисунок 1 -- блок-схема ф-ції пошуку книги.

### 2.3 Важливі фрагменти програми

#### Функція вставки рядка в рядок.

``` 
char * insert_arr(char * arr1, char * arrCenter, size_t index)
{
    char *new_array = malloc((strlen(arr1) + 1) * sizeof(char ));
            memcpy(new_array, arr1, index * sizeof(char));
            memcpy(new_array + index, arrCenter, strlen(arrCenter) * sizeof(char));
            memcpy(new_array + index + strlen(arrCenter), arr1 + index, strlen(arr1) - index);
            *(new_array + strlen(arr1) + strlen(arrCenter)) = '\0';
    return new_array;

}
```
#### Функція видалення структури з масиву структур.

```
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
```
#### Функція сортування списку.
```
void SortListByCriterion(struct List *list, int(*compare)(struct BookList*, struct BookList*))
{
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
```
#### Функція пошуку книги.
```
void FindBackpack(struct List * list, int index)
{
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

```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація роботи функцій вставки та видалення з рядку.

![result1](https://github.com/LiquidFunki/liquid_images/blob/main/1.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 2_(рис.3). Демонстрація роботи функції видалення діапазону символів з рядка.
![](https://github.com/LiquidFunki/liquid_images/blob/main/2.png?raw=true)

Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (рис.4 ). Демонстрація виконання функції вставки структури в масив структур по індексу
![](https://github.com/LiquidFunki/liquid_images/blob/main/3.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3

_Крок 4_ (рис.5 ). Демонстрація виконання функції видалення структури з масиву структур по індексу.
![](https://github.com/LiquidFunki/liquid_images/blob/main/4.png?raw=true)
Рисунок 5 --- Результат виконання кроку 3

### Структура проекту

	├── lab3
	    ├── backpacks.txt
	    ├── doc
	        ├── lab3.md
	        └── assests
	    ├── lab18
		    ├── CMakelists.txt
		    ├── test
			    ├── test.c
		    └── src
		        ├── main.c
		        ├── lib.c
		        └── lib.h
	    └── lab19
			├── CMakelists.txt
		    ├── test
			    ├── test.c
		    └── src
		        ├── main.c
		        ├── data.c
		        ├── data.h
		        ├── lsit.c
		        └── list.h
## Висновки

Було отримано навички у роботі з динамічними масивами та списками.