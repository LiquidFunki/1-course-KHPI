int main()
{
    int size = 17;
    char space = '_';
    char line[] = "Helloo          ";
    int sum = 0;
      for (int i = 0; line[i] != ' '; i++)  //считаем сколько у нас символов
      {
          sum += 1;
      }
    char buffer[size];
      for (int i = 0; i < size; i++)        //делаем ещё 1 массив в качестве буфера, где будет находится само слово
      {
          buffer[i] = line[i];
      }
    int X = (size - sum - 1) / 2;
      for (int j = 0; j < X; j++)           //начинаем заполнять первые символы основного массива пробелами
      {
          line[j] = space;
      }
    int j = 0;
      for (int k = X; k <= X + sum; k++)    //вписываем само слово
      {
          line[k] = buffer[j];
          j += 1;
      }
    int Y = sum + X;
      for (int n = Y; n < size - 1; n++)    //делаем окончательное центрирование, дописывая "пробелы"
      {
          line[n] = space;
      }
    return 0;
}
