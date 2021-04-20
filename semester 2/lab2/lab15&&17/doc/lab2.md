# Лабораторна робота №2. Структуровані типи даних. Модульні тести

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 02-квітня-2021

### 1.2 Загальне завдання

1. **Розробити** функцію, яка читає дані(масив елементів) з файлу;  
2. **Розробити** функцію, яка записує дані(масив елементів) у файлу;  
3. **Розробити** функцію, яка виводить масив елементів на екран;  
4. **Розробити** функцію, яка буде сортувати масив елементів за заданим критерієм;  
5. **Розробити** функцію, яка буде знаходити книги видавництва ранок;  
6. **Розробити** функцію, яка генерує чисельні елементи структури;  
7.  **Розробити** тести, до функцій сортування та пошуку об'єкта

### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту

## 2. Опис програми

### 2.1 Функціональне призначення

За допомогою розроблених функцій зчитується масив структур з файлу, сортується його за заданим критерієм, та виводиться його на екран або у звичайний файл формату txt.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції: `ReadFromFile`, зчитує масив структур з файлу, `GenerateRandomPages` генерує чисельні поля структури,`Sort` сортує масив структур за заданим критерієм,  `PutInConsole` та `PutInFile` виводять відсортований масив структур на екран та у файл відповідно,  `FindPublishingHouse`  знаходить книжки видавництва ранок.

_Головна функція_`main()`. Викликає функції для роботи зі структурою.

_Функція сортування_ `Sort`. функцію, яка сортує масив елементів за заданим критерієм.
_Схема алгоритму функції_ подана на рис. 1.

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/func_lab_2.png?raw=true)

Рисунок 1 --- Схема алгоритму функції `Sort`

_Функція_ `FindPublishingHouse`:
 Функція знаходить структури книжок видавництва ранок та виводить їх на екран.


#### Структура проекту

	├── lab15&&lab17
	    ├── CMakeLists.txt
	    ├── books.txt
	    ├── doc
	        ├── lab2.md
	        └── assests
	    ├── test
		    ├── test.c
	    └── src
	        ├── main.c
	        ├── lib.c
	        └── lib.h

### 2.3 Важливі фрагменти програми

#### Функція сортування масиву структур залежно від критерія.

``` 
void Sort(struct books **memory_for_books, char user_option[20], int size)
{
        char option1[20] = "digital_version";
        char option2[20] = "name";
        char option3[20] = "pages";
        char option4[20] = "publishing_house";
        char option5[20] = "cover";

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                //struct books *memory_for_books = *(memory_for_books + i);
                if (strcmp(user_option, option1) == 0)
                {
                    if(memory_for_books[j]->digital_version < memory_for_books[j+1]->digital_version)
                    {
                        struct books *temp = *(memory_for_books + j);
                        *(memory_for_books + j) = *(memory_for_books + j + 1);
                        *(memory_for_books + j + 1) = temp;
                    }

                } else if (strcmp(user_option, option2) == 0)
                  {
                    if (strcmp(memory_for_books[j]->name, memory_for_books[j + 1]->name) == 0 &&
                        strcmp(memory_for_books[j]->name, memory_for_books[j + 1]->name) > 0)
                    {
                        continue;
                    } else if (strcmp(memory_for_books[j]->name, memory_for_books[j + 1]->name) < 0)
                      {
                        struct books *temp = *(memory_for_books + j);
                        *(memory_for_books + j) = *(memory_for_books + j + 1);
                        *(memory_for_books + j + 1) = temp;
                      }
                } else if (strcmp(user_option, option3) == 0)
                  {
                    if(memory_for_books[j]->pages < memory_for_books[j+1]->pages)
                    {
                        struct books *temp = *(memory_for_books + j);
                        *(memory_for_books + j) = *(memory_for_books + j + 1);
                        *(memory_for_books + j + 1) = temp;
                    }
                } else if (strcmp(user_option, option4) == 0)
                  {
                    if (strcmp(memory_for_books[j]->publishing_house, memory_for_books[j + 1]->publishing_house) == 0 &&
                        strcmp(memory_for_books[j]->publishing_house, memory_for_books[j + 1]->publishing_house) > 0)
                        {
                        continue;
                    } else if (strcmp(memory_for_books[j]->publishing_house, memory_for_books[j + 1]->publishing_house) < 0)
                      {
                        struct books *temp = *(memory_for_books + j);
                        *(memory_for_books + j) = *(memory_for_books + j + 1);
                        *(memory_for_books + j + 1) = temp;
                      }
                } else if (strcmp(user_option, option5) == 0)
                  {
                    if(memory_for_books[j]->cover < memory_for_books[j+1]->cover)
                    {
                        struct books *temp = *(memory_for_books + j);
                        *(memory_for_books + j) = *(memory_for_books + j + 1);
                        *(memory_for_books + j + 1) = temp;
                    }
                }
            }
        }
}  
```
#### Функція `FindPublishingHouse`

```
struct books* FindPublishingHouse(struct books **memory_for_books, int size)
{
    int temp;
    char str1[15] = "Ranok";
    for (int i = 0; i < size; i++) {
        struct books *product = *(memory_for_books + i);
        if (strcmp(str1, product->publishing_house) == 0)
         {
            temp = i;
            if (product->digital_version == 1)
            {
                printf("Does this book have digital version?: Yes\n");
            } else
              {
                printf("Does this book have digital version?: NO\n");
              }
            printf("Name: %s\n", product->name);
            printf("Pages: %d \n", product->pages);
            printf("Publishing House: %s\n", product->publishing_house);
            if (product->cover == HARD)
            {
                printf("Cover of book: hard\n");
            } else if (product->cover == SOFT)
              {
                printf("Cover of book: soft\n");
                printf("\n");
              }
        }
    printf("\n");
    }
    return *(memory_for_books + temp);
}
```
#### Функція зчитування з файлу.
```
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
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Виводиться відсортований масив структур за заданим критерієм(pages).

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_1.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (рис.3 ). Виконується функція пошуку книги видавництва Ранок.

![result2](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_2.png?raw=true)

Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Результат виконання тестів.

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_3.png?raw=true)

Рисунок 4 --- Результат виконання кроку 3

## Висновки

Отримано навички роботи зі структурованими типами даних та розроблено модульні тести до функцій.
