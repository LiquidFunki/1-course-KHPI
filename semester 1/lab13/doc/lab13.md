﻿# Лабороторна робота № 13. Строки(Null-terminated C strings).
## 1. Вимоги.
### 1.1 Розробник:

 - Клименко Юрій;
 - студент групи КІТ 120-а;
 - 23-грудня-2020.
### 1.2 Загальне завдання:
Виконання завдань 13 лабораторної роботи, вкиористовуючи строки.
### 1.3 Перевірив:
асист. Челак Віктор Володимирович.
##  2. Загальний опис проекту.
Проект складається з:

-   папки  **src**  з 3 кодами;
-   папки **assests**;
-   Doxyfile;
-   Makefile;
-   Readme;
### 2.1 Структура проекту:

	├── doc
	├── assests
	├── Doxyfile   				 
	├── Makefile   			 
	├── README.md 			   
	└── src
		├── lab13_01.c
		├── lab13_02.c    
        └── lab13_04.c`
 
##  3. Опис коду lab13_04.c

###  3.1 Функціональне призначення.
Програма порівнює вхідний текст з алфавітом, та замінює відповідні символи тексту на символи шифрованого алфавіту "цезаря".
 
### 3.2 Опис логічної структури.
 Спочатку ми оголошуємо нашу строку `tex`. Далі оголошуємо масив з алфавітом `original_alphabet`, та алфавіт з "шифром цезаря".

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/lab13_04_scheme.png?raw=true)




**Рисунок 1** - схема алгоритму головної функції `main()`.



### 3.3 Результат виконання програми.

Використавши консоль можно перевірити програму на дієздатність. Вхідні дані двовимірного масиву на *рисунку 2*. Результат на *рисунку 3*.

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/lab13_04_entries.png?raw=true)

**Рисунок 2** - вхідні дані двовимірного масиву.

![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/lab13_04_result.png?raw=true)


**Рисунок 3** - результат програми.


## Висновок
При виконанні лабораторної роботи №13 було отримано досвід у використанні строк.
