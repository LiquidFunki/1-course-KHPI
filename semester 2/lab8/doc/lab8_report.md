# Лабораторна робота №8. ООП. Потоки

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 26-квітня-2021

### 1.2 Загальне завдання

 * **Поширити**, попередню роботу таким чином:
	 * використання функцій `printf/scanf` замінити на `cin/cout`;
	 * усі конкатенації строк замінити на використання `stringstream`;  
	 * замінити метод вводу інформації про об'єкт на метод, що приймає рядок з інформацією про об'єкт, обробляє його та створює об'єкт  на базі цієї інформації;
	 * поширити клас-список, шляхом реалізації методів роботи з файлами.


### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту


## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів. 

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених методів. Методи:  `object_book` обробляє строку;`toString()` перетворює об'єкт в строку; `ReadFromFile` зчитує масив елементів з файлу; `WriteToFile` записує масив елементів у файл .

_Головна функція_`main()`. 
Створює елементи списку та додає їх у список, викликає усі розроблені методи


_Метод пошуку_ `object_book`. Метод який приймає строку, та обробляє її таким чином, щоб на основі даної строки зробити об'єкт списку
_Схема алгоритму метода_ подана на рис. 1.

![Схема алгоритму функції](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab8/doc/assests/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)

Рисунок 1 --- Схема алгоритму методу `object_book`

_Метод_ `ReadFromFile`: Метод зчитує масив елементів з файлу.

_Метод_ `WriteToFile`: Метод записує масив елементів у файл.





### 2.3 Важливі фрагменти програми

#### Метод обробки рядка в об'єкт

``` 
Book& Book::object_book(string s){
    Book *new_book = new Book;
    string temp = s;
    int pos = 0;

    pos = temp.find(' ');
    string field1 = temp.substr(0, pos);
    int new_field1 = stoi(field1);
    new_book->digital_version = new_field1;
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field2 = temp.substr(0, pos);
    new_book->title = field2;
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field3 = temp.substr(0, pos);
    int new_field3 = stoi(field3);
    new_book->pages = new_field3;
    temp.erase(0, pos+1);

    pos = temp.find(' ');
    string field4 = temp.substr(0, pos);
    temp.erase(0, pos+1);
    pos = temp.find(' ');
    string field5 = temp.substr(0, pos);
    temp.erase(0, pos+1);
    PublishingHouse *temp_house = new PublishingHouse(field4, field5);
    new_book->publishingHouse = *temp_house;

    pos = temp.find(' ');
    string field6 = temp.substr(0, pos);
    int  new_field6 = stoi(field6);
    if(new_field6 == 0) new_book->cover = HARD;
    if(new_field6 == 1) new_book->cover = SOFT;
    temp.erase(0, pos+1);

    return *new_book;
}
```
#### Метод перетворення об'єкта в строку

```
string Book::toString(){
    stringstream result;
    result << get_digital_version() << " " << get_title() << " " << get_pages() << " " << get_cover() << " "
           << get_publishingHouse().getVersion() << " " << get_publishingHouse().getName() << endl;
    return result.str();
}
```
#### Метод зчитування елементів з файлу
```
void List::ReadFromFile(const string &path) {

    ifstream in;
    in.open(path);
    string object;
    this->setsize(6);
    this->books = new Book*[size];
    for( int i = 0; i < size; i++ ){
        books[i] = new Book;
    }
    int dv;
    string tt;
    int pg;
    string vs;
    string nm;
    int cvr;

    for(int i = 0; i < size; i++){
        if (in.is_open()){
            in >> dv;
            books[i]->set_digital_version(dv);
            in >> tt;
            books[i]->set_title(tt);
            in >> pg;
            books[i]->set_pages(pg);
            in >> vs;
            in >> nm;
            PublishingHouse pH(vs, nm);
            books[i]->set_publishingHouse(&pH);
            in >> cvr;
            switch(cvr){
                case 0:
                    books[i]->set_cover(HARD);
                case 1:
                    books[i]->set_cover(SOFT);
            }
        }
    }
    in.close();
}
```
#### Метод запису масиву елементів у файл
```
void List::WriteToFile(const string &path) {

    ofstream out;
    out.open(path);

    for(int i = 0; i < size; i++){
        if(out.is_open()) out << this->getBook(i).toString();
    }
}
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Результат роботи методу обробки перетворення об'єкта в строку

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab8/doc/assests/Screenshot_3.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3 ). Результат роботи методу перетворення строки в об'єкт.

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab8/doc/assests/Screenshot_1.png?raw=true)
Рисунок 3 --- Результат виконання кроку 2

### Структура проекту

	├── lab8
	    ├── doc
	        ├── lab8.md
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

Було отримано навички у роботі з потоками.