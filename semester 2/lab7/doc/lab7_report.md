# Лабораторна робота №7. Вступ до ООП

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 24-квітня-2021

### 1.2 Загальне завдання

 1. **Розробити клас**, що відображає сутність базового класу, у тому числі:
	 * конструктор за замовчуванням
	 * конструктор копіювання
	 * конструктор з аргументами
	 * деструктор 

 2. **Розробити клас**, що  має у собі:
	 * динамічний масив об'єктів базового класу
	 * метод додавання елемента
	 * метод видалення елемента
	 * метод отримання елемента по індексу
	 * метод виводу усіх елементів на екран
	 * метод 1 обходу колекції (знаходження книг видавництва Ранок) 

### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту


## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів. 

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених методів. Методи:  `addBook` додає нові елементи в список;`removeBook` видаляє елемент зі списку по індексу; `getBook` отримує елемент по індексу; `ShowAll` виводить список на екран;`findRanokBook` виконує пошук елемента .

_Головна функція_`main()`. 
Створює елементи списку та додає їх у список, викликає усі розроблені методи


_Метод пошуку_ `findRanokBook`. Метод 1 обходу колекції; Функція знаходить книги видавництва Ранок серед списку елементів.
_Схема алгоритму метода_ подана на рис. 1.

![Схема алгоритму функції](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab7/doc/assests/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)

Рисунок 1 --- Схема алгоритму методу `findRanokBook`

_Метод_ `ShowAll`: Метод виводить список елементів на екран.

_Метод_ `getBook`: Метод повертає елемент зі списку по заданому індексу.

_Метод_ `removeBook`: Метод видаляє елемент зі списку по заданому індексу.

_Метод_ `addBook`: Метод додає елемент у список.




### 2.3 Важливі фрагменти програми

#### Метод пошуку книг видавництва Ранок.

``` 
Book& List::findRanokBook() const {
    string publishing_house = "Ranok";
    for (int i = 0; i < this->size; ++i) {
        if(publishing_house == books[i]->get_publishingHouse().getName()){
            books[i]->print();
        }
    }
}
```
#### Метод виводу не екран

```
void List::showAll() {
    for (int i = 0; i < size; ++i) {
        Book temp = getBook(i);
        temp.print();
    }
}
```
#### Метод видалення  елементу
```
void List::removeBook(int index) {
    Book **temp = new Book*[this->size - 1];

    memcpy(temp, books, sizeof(Book) * (index));
    memcpy(temp + index, books + index + 1, sizeof(Book) * (size - index));

    delete[] this->books;
    this->books = temp;
    this->size -= 1;
}
```
#### Метод отримання елементу по індексу
```
Backpack& List::getBackpack(int index) const{  
  if(index < 0){  
  index= 0;  
    }  
  if(index >= this->Count) {  
  index = this->Count - 1;  
    }  
  
  return *backpacks[index];  
}
```
#### Метод додання елементу
```
void List::addBook(Book& book) {
    Book **temp1 = new Book*[this->size + 2];
    for (int i = 0; i < this->size; ++i) {
        *(temp1 + i) = this->books[i];
    }
    *(temp1 + size) = &book;
    //delete[] this->books;
    this->books = temp1;
    this->size += 1;
}
```
### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Результат роботи методу пошуку елементу

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab7/doc/assests/Screenshot_2.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 3_ (див. рис.3 ). Результат роботи всієї програми

![result3](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab7/doc/assests/Screenshot_1.png?raw=true)

Рисунок 3 --- Результат виконання кроку 3


### Структура проекту

	├── lab7
	    ├── doc
	        ├── lab7.md
	        └── assets
        ├── CMakelist.txt
		├── test
            ├── test.cpp
		└── src
		    ├── main.cpp
		    ├── list.cpp
            ├── list.h
		    ├── Book.cpp
		    └── Book.h
## Висновки

Було отримано навички у створюванні класів, та розробленні методів для роботи з ними.