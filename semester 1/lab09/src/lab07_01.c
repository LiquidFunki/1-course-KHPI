#include <stdarg.h>

/**
 * @mainpage
 * # Загальне завдання
 * 1. Переробити програми з тем "Масиви" та "Цикли" таким чином, щоб
 * використовувалися функції для обчислення результату
 *
 * @author Klyemnko Y.
 * @date 10-dec-2020
 * @version 0.1
 */

/**
 * @file lab07_01.c
 * @brief визначення кількості пар у послідовності, де перше число менше наступного
 за допомогою варіативної функції
 *
 * @author Klymenko Y.
 * @date 10-dec-2020
 * @version 0.1
*/

/**
 * Визначення кількості пар у послідовності, де перше число менше наступного
 * @param amount кількість аргументів, що передаються у функцію
 * @return кількість пар, в яких перше число менше наступного
 */

int func(int amount, ...);

/**
Головна функція  {оголошення функції func та задання послідовності
                 }
*/

int main()
{
  func(5, 1, 2, 3, 4, 5);
  return 0;
}

int func(int amount, ...)
{
  va_list arg;
  int i;
  int amount_numerator = 0;

  va_start(arg, amount);
  int first_buf = va_arg(arg, int);
  int second_buf;
  for (int i = 0; i < amount; i++)
  {
    second_buf = va_arg(arg, int);
    if ( first_buf < second_buf)
    {
      amount_numerator += 1;
      first_buf = second_buf;
    }
  }

  va_end(arg);
  return amount_numerator;
}
