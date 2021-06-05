# Лабораторна робота №16. ООП. Розумні вказівники

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 05-чеврня-2021

### 1.2 Загальне завдання

 * **Створити** STL-контейнер, що містить у собі об'єкти ієрархії класів, використати розумні вказівники:
	 * `unique_ptr`
	 * `shared_ptr`
	 * `weak_ptr  `

## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розумних вказівників: `unique_ptr`, `shared_ptr` та `weak_ptr`.

### 2.2 Опис логічної структури програми

_Вказівник:_  `unique_ptr`: Унікальний вказівник, який використовується для управління будь-яким динамічно виділеним об'єктом / ресурсом, але з умовою, що `unique_ptr` повністю володіє переданим йому об'єктом, а не «ділиться володінням» ще з іншими вказівниками. Таким чином, не можна  `unique_ptr` покажчику присвоїти інший  `unique_ptr` покажчик, який посилається на інший об'єкт. 


_Вказівник:_  `shared_ptr`: даний розумний покажчик  використовується для володіння одним динамічно виділеним ресурсом відразу декількома розумними покажчиками. Ресурс буде знищений, коли останній `shared_ptr` вийде з зони видимості.

_Вказівник:_  `weak_ptr`: використовується для вирішення проблеми «циклічної залежності», яку може створити`shared_ptr`.  `weak_ptr`є «спостерігачем» - він може спостерігати і отримувати доступ до того ж об'єкту, на який вказує `shared_ptr`, але не рахуватися власником цього об'єкта. І коли `shared_ptr` виходить з області видимості, він перевіряє, чи є інші власники `shared_ptr`. А **`weak_ptr`власником не рахується**


### 2.3 Важливі фрагменти програми

####  Створення контейнеру на основі `unique_ptr`

``` 
List<unique_ptr<Book>> list;

unique_ptr<Book> uniquePtr(new FictionBook(fiction1));
unique_ptr<Book> uniquePtr1(new FictionBook(fiction2));
unique_ptr<Book> uniquePtr2(new FictionBook(fiction3));
unique_ptr<Book> uniquePtr3(new ScienceBook(science1));
unique_ptr<Book> uniquePtr4(new ScienceBook(science2));
unique_ptr<Book> uniquePtr5(new ScienceBook(science3));
        
list.addItem(&uniquePtr);
list.addItem(&uniquePtr1);
list.addItem(&uniquePtr2);
list.addItem(&uniquePtr3);
list.addItem(&uniquePtr4);
list.addItem(&uniquePtr5);
        
cout << "unique_ptr LIST: " << endl;
for (auto &backpack : list) {
     backpack->get()->print();  
      cout << endl;
}
```

####  Створення контейнеру на основі `shared_ptr`

``` 
List<shared_ptr<Book>> list;

shared_ptr<Book> sharedPtr (new FictionBook(fiction1));
shared_ptr<Book> sharedPtr1  (new FictionBook(fiction2));
shared_ptr<Book> sharedPtr2  (new FictionBook(fiction3));
shared_ptr<Book> sharedPtr3  (new ScienceBook(science1));
shared_ptr<Book> sharedPtr4  (new ScienceBook(science2));
shared_ptr<Book> sharedPtr5  (new ScienceBook(science3));
       
list.addItem(&sharedPtr);
list.addItem(&sharedPtr1);
list.addItem(&sharedPtr2);
list.addItem(&sharedPtr3);
list.addItem(&sharedPtr4);
list.addItem(&sharedPtr5);
list.addItem(&sharedPtr6);
     
cout << "shared_ptr LIST: " << endl;
for (auto &backpack : list) {
       backpack->get()->print();  
       cout << endl;
     }
```

####  Створення контейнеру на основі `shared_ptr`

``` 
List<weak_ptr<Book>> list;

shared_ptr<Book> sharedPtr (new FictionBook(fiction1));
shared_ptr<Book> sharedPtr1  (new FictionBook(fiction2));
shared_ptr<Book> sharedPtr2  (new FictionBook(fiction3));
shared_ptr<Book> sharedPtr3  (new ScienceBook(science1));
shared_ptr<Book> sharedPtr4  (new ScienceBook(science2));
shared_ptr<Book> sharedPtr5  (new ScienceBook(science3));
        
 weak_ptr<Book> weakPtr = sharedPtr;
 
weak_ptr<Book> weakPtr1 = sharedPtr1;
weak_ptr<Book> weakPtr2 = sharedPtr2;
weak_ptr<Book> weakPtr3 = sharedPtr3;
weak_ptr<Book> weakPtr4 = sharedPtr4;
weak_ptr<Book> weakPtr5 = sharedPtr5;
weak_ptr<Book> weakPtr6 = weakPtr;


list.addItem(&weakPtr);
list.addItem(&weakPtr1);
list.addItem(&weakPtr2);
list.addItem(&weakPtr3);
list.addItem(&weakPtr4);
list.addItem(&weakPtr5);
list.addItem(&weakPtr6);


 cout << "weak_ptr LIST: " << endl;
cout << endl;
for (auto &backpack : list) {
      backpack->lock()->print();  
            cout << endl;
        }
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.1 ). Демонстрація контейнеру на основі `unique_ptr`

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab16/doc/assets/unique.png?raw=true)

Рисунок 1 --- Результат виконання кроку 1

_Крок 2_ (рис.2 ). Демонстрація контейнеру на основі `shared_ptr`

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab16/doc/assets/shared.png?raw=true)

Рисунок 2 --- Результат виконання кроку 2

_Крок 3_ (рис.3 ). Демонстрація контейнеру на основі `weak_ptr`

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab16/doc/assets/weak.png?raw=true)

Рисунок 3 --- Результат виконання кроку 3


### Структура проекту

	├── lab16
	    ├── doc
	        ├── lab16.md
	        └── assets
        ├── CMakelist.txt
		└── src
		    ├── main.cpp
            ├── List.hpp
		    ├── Book.cpp
		    └── Book.h
## Висновки

Було отримано навички у роботі зі стандартною бібліотекою шаблонів, з STL-контейнерами, їх методами і функціями. Також було отримано навички у використанні розумних вказівників та дізналися різницю між ними.
