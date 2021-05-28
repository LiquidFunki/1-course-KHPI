# Лабораторна робота №9. Перевантаження операторів

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 30-квітня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
 1. **У базовому класі**, та класі/класах-спадкоємцях перевантажити:
	 * оператор присвоювання;
	 * оператор порівняння ( ``==`` ) ;
	 * оператор введення/виведення;
2. **У класі-списку** перевантажити:
	 * оператор індексування ( ``[]`` ) ;
	 * введення/виведення з акцентом роботи, у тому числі і з файлами.
* При цьому продовжувати використовувати регулярні вирази для валідації введених даних.


### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту


## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених перевантажень операторів 

### 2.2 Опис логічної структури програми

_Перевантаження:_  `operator=(Book& book)`  
перевантажує оператор присвоювання (``=``) для класу ``Book``.
_Схема алгоритму перевантаження оператора_ подана на рис. 1.
![result3](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab9/doc/assests/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)

Рисунок 1 --- Схема алгоритму перевантаження оператора `=`

_Перевантаження:_ `operator==(Book& first, Book& second)`. перевантажує оператор порівняння (``==``) для класу ``Book``.

_Перевантаження:_  `operator<<(ostream &out, Book& book)` перевантажує оператор виводу (``<<``) для класу ``Book``.

_Перевантаження:_  `operator>>(istream &in, Book& book)`перевантажує оператор вводу (``>>``) для класу ``Book``.

_Перевантаження:_  `operator[](const size_t index) const`перевантажує оператор індексування (``[]``) для класу-списку ``List``.

_Перевантаження:_  `operator>>(ifstream &in, List& list)`перевантажує оператор читання з файлу (``>>``) для класу-списку ``List``.

_Перевантаження:_  `operator<<(ofstream &out ,const List& list)` перевантажує оператор запису в файл (`<<`) для класу-списку ``List``.





### 2.3 Важливі фрагменти програми

#### Перевантаження оператора порівняння

``` 
bool operator==(Book& first, Book& second){
    bool  result = true;
    if (first.get_digital_version() == second.get_digital_version()
        && first.get_title() == second.get_title()
        && first.get_pages() == second.get_pages()
        && first.get_cover() == second.get_cover()
        && first.get_publishingHouse().getVersion() == second.get_publishingHouse().getVersion()
        && first.get_publishingHouse().getName() == second.get_publishingHouse().getName()){
        result &= true;
    }else{
        result &= false;
    }
    return result;
}
```
#### Перевантаження оператора присвоювання 

```
Book& Book::operator=(Book& book) {
        set_digital_version(book.get_digital_version());
        set_pages(book.get_pages());
        set_title(book.get_title());
        set_cover(book.get_cover());
        PublishingHouse pH(book.get_publishingHouse().getVersion(), book.get_publishingHouse().getName());
        set_publishingHouse(&pH);
    return *this;
}
```
#### Перевантаження оператора виводу для базового класу
```
ostream & operator<<(ostream &out, Book& book){
    out << "     ";
    out << book.get_digital_version();
    out << "     ";
    out << book.get_title();
    out << "     ";
    out << book.get_pages();
    out << "     ";
    out << book.get_publishingHouse().getVersion();
    out << "     ";
    out << book.get_publishingHouse().getName();
    out << "     ";
    out << book.get_cover() << endl;
    return out;
}
```
#### Перевантаження оператора вводу для базового класу
```
istream & operator>>(istream &in, Book& book){
    int dg;
    int pages;
    string name;
    int cover;
    string version;
    string pb_name;

    cout << "Availability of digital version: " << endl;
    in >> dg;
    cout << "Count of pages: " << endl;
    in >> pages;
    cout << "Name of the book: " << endl;
    in >> name;
    cout << "Cover of the book: " << endl;
    in >> cover;
    cout << "Version of the book: " << endl;
    in >> version;
    cout << "Name of the publishing house: " << endl;
    in >> pb_name;

    std::stringstream buffer;
    buffer << dg << " " << name << " " << pages << " " << cover << " " << pb_name << " " << version;
    regex reg("^[0-1] [A-Z][a-zA-Z]* [0-9]{1,4} [0-1] [A-Z][a-zA-Z]* [A-Za-z][a-zA-Z]*");

    if(regex_match(buffer.str(), reg)){
        book.set_digital_version(dg);
        book.set_title(name);
        book.set_pages(pages);
        if(cover == 0) book.set_cover(HARD);
        else if(cover == 1) book.set_cover(SOFT);
        PublishingHouse pH(version, pb_name);
        book.set_publishingHouse(&pH);
        return in;
        }
    }
```
#### Перевантаження оператора індексування для класу-списку 
```
Book& List::operator[](const size_t index) const{
    if(index < size) return *books[index];
    else return *books[0];
}
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  роботи перевантаження методу вводу базового класу

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab9/doc/assests/Screenshot_2.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Демонстрація  роботи перевантаження методу виводу класу-списку 

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab9/doc/assests/Screenshot_1.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

### Структура проекту

	├── lab9
	    ├── doc
	        ├── lab9.md
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

Було отримано навички у перевантажуванні операторів для роботи з класами.