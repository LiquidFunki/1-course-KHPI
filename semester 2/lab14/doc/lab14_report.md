# Лабораторна робота №11. STL. Вступ до Стандартної бібліотеки шаблонів(частина 1)

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 27-травня-2021

### 1.2 Загальне завдання

 * **Поширити**, лабораторну роботу №27 таким чином:
	 1. **Замінити** масив та CRUD методи роботи з ним на використання STL;

	2. **Оновити** всі методи роботи з колекцією на використання STL;

	3.  **Додати** функцію сортування колекції з використанням функтора.
	4.  **Додати** функцію об'єднання двох класів-списків.



### 1.3 Індивідуальне завдання

Виконати завдання, згідно варіанту

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів

### 2.2 Опис логічної структури програми
Загальне завдання виконується за допомогою наступних методів:
`findRanok`,  `findMaxPages`,  `findOnlineDetective`, `SortByPages`,  `InsertList`.

_Метод:_  `findRanok`: Виконує завдання 1 з "методи для роботи з колекцією"; За допомогою STL-функції `find_if` предиката `PredRanok` в класі-списку  знаходимо книги видавництва Ранок.
_Схема алгоритму метода `findRanok`_ подана на рис. 1.
![Блок-схема](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab14/doc/assests/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)

Рисунок 1 --- Схема алгоритму метода`findRanok`

_Метод_ `findOnlineDetective` Виконує завдання 2 з "методи для роботи з колекцією"; За допомогою STL-функції `find_if` предиката `predDetective` в класі-списку знаходимо книгу-детектив, що має онлайн версію.

_Метод_   `findMaxPages`Виконує завдання 3 з "методи для роботи з колекцією"; За допомогою STL-функції `sort` в класі-списку знаходимо книгу з найбільшою кількістю сторінок.

_Метод_ `SortByPages` Виконує сортування за допомогою STL-функції `sort` та розроблених функторів `functorTrue/functorFalse`.

_Метод_ `InsertList` Виконує об'єднання двох класів-списків за допомогою STL-функції `Insert`.


### 2.3 Важливі фрагменти програми

#### Метод пошуку книг видавництва Ранок.

``` 
vector<FictionBook*> List::findRanok(){
    vector<FictionBook*> temp;
    auto iter = books.begin();
    while(*iter){
        iter = find_if(iter, this->books.end(), predRanok);
        if(*iter == NULL) break;
        ((FictionBook*)*iter)->print();
        cout<<endl;
        temp.push_back((FictionBook*)*iter);
        iter++;
    }
    return temp;
}
```
#### Метод пошуку книги-детективу, що має онлайн-версію

```
vector<FictionBook*> List::findOnlineDetective() {
    vector<FictionBook*> temp;
    auto iter = books.begin();
    while(*iter){
        iter = find_if(iter, this->books.end(), predDetective);
        if(*iter == NULL) break;
        ((FictionBook*)*iter)->print();
        cout<<endl;
        temp.push_back((FictionBook*)*iter);
        iter++;
    }
    return temp;
}
```
#### Метод пошуку книги, що має найбільшу кількість сторінок

```
Book* List::findMaxPages() {
    vector<Book*> temp;
    int n;
    cout << "Enter how you want to sort your list: 0 - max pages 1 - min pages " << endl;
    cin >> n;
    temp.reserve(this->books.size());
    copy(this->books.begin(), this->books.end(), back_inserter(temp));
    if (n == 0) {
        sort(temp.begin(), temp.end(), functorFalse);
    } else if (n == 1) {
        sort(temp.begin(), temp.end(), functorTrue);
    }else {
        cout << "Error";
    }
    auto iter = temp.begin();
    if (((Book*)*iter)->GetType() == 'F'){
        ((FictionBook*)*iter)->print();
        cout << endl;
    }else {
        ((ScienceBook*)*iter)->print();
        cout << endl;
    }
    while (!temp.empty()){
        temp.pop_back();
    }
    temp.clear();
    temp.shrink_to_fit();
    return ((Book*)*iter)->clone();
}

```
#### Метод об'єднання двох класів-списків
```
void List::InsertList(List &in) {
    in.index++;
    this->books.reserve(this->index + in.index + 1);
    auto iter = this->books.end();
    for (int i = 0; i < in.index; i++) {
        this->books.insert(iter + i, in.books[i]);
    }
    this->index += in.index;
}
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація роботи методу сортування

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab14/doc/assests/Screenshot_3.png?raw=true)
Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (рис.3 ). Демонстрація  роботи методів пошуку

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab14/doc/assests/Screenshot_1.png?raw=true)

Рисунок 3 --- Результат виконання кроку 2

_Крок 3_ (див. рис.4 ). Результат виконання методу об'єднання двох класів-списків

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab14/doc/assests/Screenshot_2.png?raw=true)
Рисунок 4 --- Результат виконання кроку 3


### Структура проекту

	├── lab14
	    ├── doc
	        ├── lab14.md
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

Було отримано навички у роботі зі стандартною бібліотекою шаблонів, з STL-контейнерами  та їх методами і функціями.