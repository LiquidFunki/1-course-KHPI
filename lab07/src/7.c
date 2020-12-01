#include <stdarg.h>

int func(int amount, ...);

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
