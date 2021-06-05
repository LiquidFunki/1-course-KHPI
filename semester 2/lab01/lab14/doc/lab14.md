# Лабораторна робота №14. Взаємодія з файлами

## 1. Вимоги

### 1.1 Розробник

- Клименко Юрій Юрійович;

- студент групи КІТ-120а;

- 27-лютого-2021

### 1.2 Загальне завдання

1. Вивести структуру файлів та каталогів, як це робить утиліта tree.

 2. Визначити об'єм запитаного каталогу. 

### 1.3 Індивідуальне завдання

 Переробити завдання з лабораторної роботи №13, під взаємодію з файлами

## 2. Опис програми

### 2.1 Функціональне призначення

За допомогою взаємодії з файлами, код виводить на екран структуру директорії (як це робить утиліта `tree`); рахує розмір заданого каталогу; виконує арифметичну операцію беручи данні з заданого файла, а виводить результат в заданий файл.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою рекурсії. Функції `show_tree`, `put_directory_size_on_console` рекурсивно перебирають кожну директорію та файл и виводить структуру заданої директорії в першому завдані; та розмір заданої директорії в другому завдані. 

В індивідуальному завдані функція `get_data_from_file` зчитує інформацію з заданого файл; `individual_task` виконує індивідуальне завдання; та `put_data_to_file`  записує результат в заданий файл.

_Головна функція_`main()`. Викликає функції `show_tree`, `print_size_of_directory`,  `individual_task` для виконання загальних та індивідуального завдань
 _Схема алгоритму функції_ подана на рис. 1.


![Схема алгоритму функції](https://github.com/LiquidFunki/liquid_images/blob/main/main14.png?raw=true)


Рисунок 1  - Схема алгоритму функції `main`.

_Функція, що виводить структуру директорії_ `show_tree`. Функція рекурсивно перебирає усі файли та директорії даної директорії та виводить їх на екран, як це робить утиліта `tree`.
_Схема алгоритму функції_ подана на рис. 2.

![Схема алгоритму функції](https://github.com/LiquidFunki/liquid_images/blob/main/tree.png?raw=true)

Рисунок 2 - Схема алгоритму функції `show_tree`.

_Функція, що виводить розмір директорії_ `put_directory_size_on_console`:
 Функція запитує у користувача назву каталогу та викликає функції `calculate_directory_size` та `calculate_file_size` для розрахунку розміру запитуваної директорії, після чого виводить результат на екран.

_Функція_ `individual_task`: отримує вхідні дані з файлу `i.txt`, за допомогою шрифту Цезаря шифрує ці дані та отриманий результат записується в файл `s.txt`.

#### Структура проекту

    ├── lab14
    ├── Doxyfile
    ├── Makefile
    ├── s.txt
    ├── i.txt
    ├── doc
        ├── lab14.md
        └── assets
    └── src
        ├── main.c
        ├── lib.c
        └── lib.h

### 2.3 Важливі фрагменти програми

#### Рекурсивний виклик функції  `show_tree`

```
strcpy(subdirectory_name, directory_path);
strcat(subdirectory_name, "/");
strcat(subdirectory_name, entry->d_name);
show_tree(subdirectory_name, tab + 1);
```

#### Розрахунок розміру файлу
```
int calculate_file_size(FILE * file){    

    int check_point = ftell(file);
    fseek(file, 0L, SEEK_END);

    int file_size = ftell(file);
    fseek(file, check_point, SEEK_SET);

    return file_size;
}
```
#### Розрахунок розміру директорії
```
 while ((entry = readdir(folder))){

            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                char * subdirectory_name = malloc((strlen(directory_path) + 1 + strlen(entry->d_name)) * sizeof(char));

                strcpy(subdirectory_name, directory_path);
                strcat(subdirectory_name, "/");
                strcat(subdirectory_name, entry->d_name);

                directory_size += calculate_directory_size(subdirectory_name);
                free(subdirectory_name);
            }
        }
    }
```
#### Функція отримання даних з файлу
```
 void get_data_from_file(char *name, char *data, int size){
    FILE * f1 = fopen(name, "rt");
    if (f1 == NULL){
        puts("Error");
    }
    fgets(data, size, f1);
    fclose(f1);
}
```
#### Функція запису даних до файлу
```
void put_data_to_file(char *name, char * result){
    FILE * f2 = fopen(name, "wt");
    if (f2 == NULL){
        puts("Error");
    }
    for(int i = 0; i < strlen(result); i++) {
        fprintf(f2, "%c", *(result + i));
    }
    fclose(f2);
}

```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion.

На рисунку 3-5 подан результат виконання програми.

![result1](https://github.com/LiquidFunki/liquid_images/blob/main/lab14.png?raw=true)

Рисунок 3 - дерево та розрахунок розміру директорії.

![result1](https://github.com/LiquidFunki/liquid_images/blob/main/input.png?raw=true)

Рисунок 4 - вхідні дані з файлу.

![result1](https://github.com/LiquidFunki/liquid_images/blob/main/output.png?raw=true)

Рисунок 5 - результат у новому файлі.

## Висновки

Було отримано розробляти програми для взаємодії з файлами та каталогами.