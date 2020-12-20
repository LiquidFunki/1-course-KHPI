﻿ 
﻿## ﻿Лабораторна робота №10. Документація проекту.
# 1. Вимоги
### 1.1 Розробник: 
* Клименко Юрій;
* студент групи КІТ 120-а;
* 18-грудня-2020.
### 1.2 Загальне завдання:
Розробити повноцінний звіт для лабораторної роботи "Функції".
### 1.3 Перевірив:
асист. Челак Віктор Володимирович.
# 2. Загальний опис проекту.
Проект складається з:
* папки **src** з 3 кодами
* Doxyfile
* Makefile
* Readme

### Структура проекту:

	├── Doxyfile    
	├── Makefile    
	├── README.md    
	└── src
		├── lab05_05.c  
		├── lab06_06.с  
        └── lab07_01.c
# 3. Опис коду lab05_05.c
## 3.1 Функціональне призначення.
Програма отримує корінь числа без допомоги зовнішніх бібліотек. Результат зберігається в змінній `root_num`. Демонстрація результату передбачає покрокове виконання програми.
## 3.2 Опис логічної структури.
Спочатку ми задаємо число за допомогою генератора псевдовипадкових чисел. Потім ми оголошуємо функцію `func`, котра і знаходить нам корінь цього числа, поступово збільшуючи наш "корінь" на *0.0001* і перемножує його само на себе, доки ми не отримаємо число, задане в `main()`.

Головна функція `main()`. Схема алгоритму подана на рисунку 1.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/05_01.png?raw=true)
**Рисунок 1** - схема алгоритму головної функції `main()`.

Функція `func`, що знаходить корінь до заданого числа в головній функції. Схема алгоритму зображена на 2 рисунку.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/05_02.png?raw=true)
**Рисунок 2** - схема алгоритму функції `func`.
## 3.3 Результат виконання програми.
Використавши debug можно перевірити програму на дієздатність. Результат на *рисунках 3-4*.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_2.png?raw=true)
**Рисунок 3** - задане число генератором псевдовипадкових чисел.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_3.png?raw=true)
**Рисунок 4** - отриманий корінь. 

# 4. Опис коду lab06_06.c
## 4.1 Функціональне призначення.
Програма перемножує матрицю саму на себе. Результат зберігається в масиві `new_massive`. Демонстрація результату передбачає покрокове виконання програми.
## 4.2 Опис логічної структури програми.
Спочатку ми оголошуємо масив з матрицею, яку будемо перемножувати саму на себе. Задаємо псевдовипадкові числа цій матриці. Потім за допомогою функції `mas_func` ми виконуємо пермноження матриці саму на себе за правилами множення матриць.		

*Головна функція* `main()`. Схема алгоритму подана на рисунку 5.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/06_01.png?raw=true)
**Рисунок 5** - cхема алгоритму головної функції `main()`.

Функція `mas_func`, що заповнює кожний новий елемент масиву з матрицею за правилами множення матриці. Схема алгоритму на 6 рисунку.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/06_02.png?raw=true)
**Рисунок 6** - схема алгоритму функції `mas_func`.
## 4.3 Результат виконання програми.
Використавши debug можно перевірити програму на дієздатність. Результат на *рисунку 7*.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_1.png?raw=true)
**Рисунок 7** - результат виконання програми у **debug**.
## 5. Опис коду lab07_01.c.
## 5.1 Функціональне призначення.
Програма визначає кількість пар у послідовності, де перше число менше наступного за допомогою варіативної функції. Результат зберігається в `amount_numerator`.
## 5.2 Опис логічної структури програми.
Оголошуємо головну функцію `main()`, у котрій викликаємо функцію `func`, де задаємо кількість чисел в послідовності та саму послідовність.(5 - чисел в послідовності; 1, 2, 3, 4, 5 - сама послідовність) Далі `func` сортує цю послідовність та знаходить кількість пар, де перше число менше наступного.

*Головна функція* `main()`. Схема алгоритму подана на рисунку 8.![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/07_01.png?raw=true)

**Рисунок 8** - cхема алгоритму головної функції `main()`.

Функція `func`, котра  сортує послідовність та знаходить кількість пар, де перше число менше наступного. Схема алгоритму зображена на рисунку 9.
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/07_02.png?raw=true)
**Рисунок 9** - схема алгоритму функції `func`.
## 5.3 Результат виконання програми.
Використавши debug можно перевірити програму на дієздатність. Результат на *рисунку 10*. 
![enter image description here](https://github.com/LiquidFunki/liquid_images/blob/main/Screenshot_4.png?raw=true)
**Рисунок 10** - результат виконання програми у **debug**.
## Висновок
При виконанні лабораторної роботи №10 було отримано досвід у розробці документації формату *markdown*.