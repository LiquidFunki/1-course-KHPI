# Лабораторна робота №6. Регулярні вирази

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 18-квітня-2021

### 1.2 Загальне завдання

 1. При введені інформації про базовий тип виконати перевірку:
	   * Можна вводити тільки кириличні символи, латинські символи, цифри, пропуски, розділові знаки

	 * Не повинно бути пропусків та розділових знаків, які повторюються
	 * Перше слово не повинно починатися з маленького символу 

 1. У клас-список додати метод, що виводить на екран список усіх об'єктів, які мають одне або більше полів з щонайменше двома словами (перевірку виконати за допомогою регулярних виразів)


## 2. Опис програми 

### 2.1 Функціональне призначення

За допомогою регулярних виразів виконується перевірка вхідного тексту.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції:  `RegexChek` виконує перевірку вхідного тексту;`PrintFieldWithTwoWords` виводить на екран список необхідних елементів.

_Головна функція_`main()`. Виконує взаємодію з користувачем шляхом діалогового меню. Викликає функції `RegexCheck` та `PrintFieldWithTwoWords` в залежності від запитів користувача.

_Функція перевірки_ `RegexCheck`. виконує перевірку вхідного тексту за допомогою регулярних виразів, та в залежності від перевірки додає новий елемент в список .
_Схема алгоритму функції_ подана на рис. 2.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/RegexChek.png?raw=true)

Рисунок 1 --- Схема алгоритму функції `RegexChek`

_Функція_ `PrintFieldWithTwoWords`: Функція виконує перевірку полів елементу на наявність щонайменше двух слів і в залежності від результату перевірки виводить елемент на екран




### 2.3 Важливі фрагменти програми

#### Перевірка вхідного тексту за допомогою регулярних виразів `checker`.

``` 

  bool RegexCheck(char dv[], char n[], char pg[], char ph[], char cvr[]){
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
```
#### Виведення елементів у яких хоча б одне поле має щонайменше два слова

```
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
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.


_Крок 1_ (див. рис.2 ). Заповнення елементів списку

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab6/doc/assests/Screenshot_1.png?raw=true)

Рисунок 2 --- Результат виконання кроку 2

_Крок 2_ (див. рис.3 ). Результат роботи функції `PrintFieldWithTwoWords`
![result3](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab6/doc/assests/Screenshot_3.png?raw=true)

Рисунок 3 --- Результат виконання кроку 3


### Структура проекту

	├── lab6
	    ├── Doxyfile
	    ├── doc
	        ├── lab6.md
	        └── assets
        ├── CMakelist.txt
		├── test
            ├── test.c
		└── src
		    ├── main.c
		    ├── data.c
            ├── data.h
		    ├── list.c
		    └── list.h
## Висновки

Було отримано навички у роботі з регулярними виразами.