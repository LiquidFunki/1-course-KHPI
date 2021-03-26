#include <stdio.h>
#include <time.h>

/**
 * @file lab05_05.c
 * @brief Отримання кореню числа без допомоги зовнішніх бібліотек
 *
 * @author Klymenko Y.
 * @date 10-dec-2020
 * @version 0.1
*/

/**
 * Отримання кореню числа без допомоги зовнішніх бібліотек
 * @param num число, з якого нам потрібно отримати корінь
 * @param root_num корінь, який ми шукаємо
 * @return корінь, який ми шукаємо
 */

float func(float num);

/**
Головна функція  {оголошення функції, заповнення змінної num
                  за допомогою псевдовипадкового числа
                 }
*/

int main()
{
    srand(time(NULL));
    func(rand() % 100 + 1);
    return 0;
}

float func(float num)
{
    float root_num = 0.0;
        while ( root_num * root_num <= num )
        {
            root_num += 0.0001;
        }
    return root_num;
}
