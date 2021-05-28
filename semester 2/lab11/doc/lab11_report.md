# Лабораторна робота №11. Поліморфізм

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 21-травня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
	 1. **Зробити** базовий клас абстрактним, додати абстрактні методи;

	2. **Розроблені** класи-списки поєднуються до одного класу списку таким чином, щоб він міг працювати як з базовим класом, так і з класами-спадкоємцями;

	4.  **Обов'язково** використовувати ключові слова ``override`` або ``final``.


### 1.3 Індивідуальне завдання

Реалізувати методи 1-3 із розрахункового завдання:
1. **Знайти** книги видавництва Ранок;
2. **Знайти** книгу детектив, що має онлайн версію;
3. **Знайти** книгу з максимальною кількістю сторінок.

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів

### 2.2 Опис логічної структури програми
Індивідуальне  завдання виконується за допомогою наступних методів:
`findRanok`,  `findOnlineDetective`,  `findMaxPages`.

_Метод:_  `findRanok`: Виконує завдання 1 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку  знаходимо книги видавництва Ранок.
_Схема алгоритму метода `findRanok`_ подана на рис. 1.
![Блок-схема](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab11/doc/assests/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)

Рисунок 1 --- Схема алгоритму метода`findRanok`

_Метод_ `findOnlineDetective` Виконує завдання 2 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку знаходимо замшевий рюкзак без підкладки.

_Метод_   `findMaxPages`Виконує завдання 3 з "методи для роботи з колекцією"; За допомогою даного методу в класі-списку знаходимо синій рюкзак з найбільшим об'ємом.



### 2.3 Важливі фрагменти програми

#### Метод пошуку книги-детектива, що має онлайн версію.

``` 
FictionBook* List::findOnlineDetective() {
    FictionBook * temp;
    for (int i = 0; i <= index; ++i) {
        if (books[i]->GetType() == 'F'){
            temp = (FictionBook *) getBook(i);
            if (temp->get_digital_version() == 1 && temp->get_genre() == DETECTIVE){
                temp->print();
                cout << endl;
                return temp;
            }
        }
    }
}
 
```
#### Метод пошуку книг видавництва Ранок

```
Book* List::findRanok(){
    FictionBook *temp1;
    ScienceBook *temp2;
    for (int i = 0; i <= index; ++i) {
        if(books[i]->GetType() == 'F'){
            temp1 = (FictionBook *) getBook(i);
            if(temp1->get_pH().getName() == "Ranok"){
                temp1->print();
                cout << endl;
            }
        }
        if(books[i]->GetType() == 'S'){
            temp2 = (ScienceBook *) getBook(i);
            if(temp2->get_pH().getName() == "Ranok"){
                temp2->print();
                cout << endl;
            }
        }
    }
    return temp1;
}
```
#### Метод пошуку книг з найбільшою кількістю сторінок

```
Book* List::findMaxPages() {
    FictionBook *temp1;
    ScienceBook *temp2;
    bool flag1 = false;
    bool flag2 = false;
    SortByPages();
    for (int i = index; i >= 0; --i) {
        if (books[i]->GetType() == 'F') {
            temp1 = (FictionBook *) getBook(i);
            temp1->print();
            cout << endl;
            flag1 = true;
            break;
        }
        if (books[i]->GetType() == 'S') {
            temp2 = (ScienceBook *) getBook(i);
            temp2->print();
            cout << endl;
            flag2 = true;
            break;
        }
        }
    if (flag1){
        return temp1;
    }
    if (flag2 ){
        return temp2;
    } else{
        cout << "ERROR: Nothing found" << endl;
        return nullptr;
    }
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  роботи методів пошуку

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab11/doc/assests/Screenshot_1.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Результат виконання всієї програми

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab11/doc/assests/Screenshot_2.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2


### Структура проекту

	├── lab11
	    ├── doc
	        ├── lab11.md
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

Було отримано навички у роботі з класами-спадкоємцями та зі списком для них.