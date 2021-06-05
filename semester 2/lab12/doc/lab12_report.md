# Лабораторна робота №12. Обробка виключних ситуацій

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 04-червня-2021

### 1.2 Загальне завдання

**Необхідно** реалізувати програму, що виконує перераховані нижче дії:
* введення з клавіатури назви вхідного файлу з даними;
* читання даних з файлу;
* виконання індивідуального завдання;
* введення з клавіатури вихідного файлу;
* запис результату операції у файл;
* доступ до елемента за індексом слід винести в окрему функцію, що виконує перевірку на можливість виходу за межі масиву.
**При обробці виключень** цикл не повинен перериватись.

### 1.3 Індивідуальне завдання

1. **Знайти** у масиві елемент з мінімальним значенням;


## 2. Опис програми 

### 2.1 Функціональне призначення

Загальне завдання виконується за допомогою розроблених методів:
```  void ReadFileName();  
void ReadFromFile();  
void WriteToFile();  
int getSize(int arrIndex);  
int getElem(int arrIndex, int index);  
void setSize(int arrIndex, int val);  
void setElem(int arrIndex, int index, int val);
```

### 2.2 Опис логічної структури програми

_Метод_ `int* FindMinElem();`Виконує індивідуальне завдання №5 - знаходить в кожному масиві мінімальний елемент, та записує його у вихідний масив; Повертає масив з мінімальними елементами.
_Схема алгоритму метода_  подана на рис. 1.
![result3](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab12/doc/assets/%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.png?raw=true)
Рисунок 1 --- Схема алгоритму метода `int* FindMinElem().`

### 2.3 Важливі фрагменти програми

#### Перевірка на коректність вхідних  з файлу даних

``` 
ifstream fin;  
fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);  
fin.open(fileName, std::ios_base::in);  
fin >> Count;  
if (Count < 0) {  
  throw std::invalid_argument("Bad Argument");  
}
```

```
void Task:: setSize(int arrIndex, int val) {  
    if (arrIndex >= Count || arrIndex < 0 || val < 0){  
	    throw out_of_range("Out of range exception");  
    }  
    else{  
	    sizes[arrIndex] = val;  
    }  
}
```
```
void Task:: setElem(int arrIndex, int index, int val) {  
    if (arrIndex >= Count || arrIndex < 0 ){  
	    throw out_of_range("Out of range exception:");  
    }  
    else if (index >= sizes[arrIndex] || index < 0){  
	    throw out_of_range("Out of range exception");  
    }  
    else{  
	    arrays[arrIndex][index] = val;  
    }  
}
```
#### Метод вхідних даних для виконання індивідуального завдання

```
int Task:: getElem(int arrIndex, int index) {  
    if (arrIndex >= Count || arrIndex < 0){  
	    throw out_of_range("Out of range exception");  
    }  
    else if (index >= sizes[arrIndex] || index < 0){  
	    throw out_of_range("Out of range exception");  
    }  
    else{  
	    return arrays[arrIndex][index];  
    }  
}  
```
```
int Task:: getSize(int arrIndex) {  
	if (arrIndex >= Count || arrIndex < 0){  
	    throw out_of_range("Out of range exception");  
    }  
    else{  
	    return sizes[arrIndex];  
    }  
}
```
```
int* Task::FindMinElem(){
    int *temp_res = new int[Count];
    int elem = 0;
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem > getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.2 ). Демонстрація  відлову виключень для читання з файлу(1 випадок - некоректна назва файлу, 2 випадок - некоректна кількість масивів у файлі, 3 випадок - некоректний розмір масиву в файлі)

![result1](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab12/doc/assets/Screenshot_4.png?raw=true)

Рисунок 2 --- Результат виконання кроку 1

_Крок 2_ (див. рис.3-4 ). Демонстрація виконання методу. Рисунок 3 - вхідні данні. Рисунок 4 - результат(масив з мінімальних елементів кожного з масивів)

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab12/doc/assets/Screenshot_1.png?raw=true)

Рисунок 3 --- Вхідні данні.

![result2](https://github.com/LiquidFunki/liquid-prog/blob/main/semester%202/lab12/doc/assets/Screenshot_2.png?raw=true)
Рисунок 4 --- Результат виконання.

### Структура проекту

	├── lab12
	    ├── doc
	        ├── lab12.md
	        └── assets
        ├── CMakelist.txt
		├── test
            ├── test.cpp
		└── src
		    ├── main.cpp
		    ├── task.cpp
		    └── task.h
## Висновки

Було отримано навички у роботі з обробкою виключних ситуацій, "кидати" виключення, та "відловлювати" їх.