# Лабораторна робота №10. Спадкування

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій;

- студент групи КІТ-120а;

- 12-травня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
	 1. **Додати** класи-спадкоємці, котрі будуть поширювати функціонал базового класу відповідно до індивідуального завдання;

	2. **Додати** клас-список для кожного класу-спадкоємця, який буде керувати лише елементами стосовно класа-спадкоємця.


### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту


## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів

### 2.2 Опис логічної структури програми
Загальне завдання виконується за допомогою наступних методів:
`findRanokBook`,  `findOnlineDetective`,  `findMaxPages`.

_Метод:_  `findRanokBook`: Виконує завдання 1 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку для спадкоємців 1 та 2 знаходимо всі книги видавництва Ранок.
_Схема алгоритму метода `findRanokBook`_ подана на рис. 1.
![result3](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab10/doc/assests/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)

Рисунок 1 --- Схема алгоритму метода`findRanokBook`

_Метод_ `findOnlineDetective` Виконує завдання 2 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку для спадкоємця 1 знаходимо детектив, який має онлайн версію.

_Метод_   `findMaxPages`Виконує завдання 3 з "методи для роботи з колекцією"; За допомогою даного методу в класах-списках для спадкоємців 1 та 2 знаходимо книгу з найбільшою кількістю сторінок.



### 2.3 Важливі фрагменти програми

#### Метод пошуку книг видавництва Ранок.

``` 
FictionBook& FictionBookList::findRanokBook() {
    string publishing_house = "Ranok";
    for (int i = 0; i < this->size; ++i) {
        //if(publishing_house == FictionBooks[i]->getFictionBook().get_publishingHouse().getName()){
        if(publishing_house == getFictionBook(i).get_publishingHouse().getName())
            FictionBooks[i]->print2();
        }
    }
```
#### Метод пошуку детективу, що має онлайн версію

```
FictionBook& FictionBookList::findOnlineDetective(){
    FictionBook *temp = new FictionBook;
    for (int i = 0; i < size; ++i) {
        if (getFictionBook(i).get_genre() == DETECTIVE
        && getFictionBook(i).get_digital_version() == true){
            temp = &getFictionBook(i);
            temp->print2();
        }
    }
    return *temp;
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  роботи методів пошуку

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab10/doc/assests/Screenshot_3.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1


### Структура проекту

	├── lab10
	    ├── doc
	        ├── lab10.md
	        └── assets
        ├── CMakelist.txt
		├── test
            ├── test.cpp
		└── src
		    ├── main.cpp
		    ├── List.cpp
            ├── List.h
		    ├── Book.cpp
		    └── Book.h
## Висновки

Було отримано навички у роботі з класами-спадкоємцями та списками для них.