#define SIZE 3
int main()
{
    int massive[SIZE][SIZE] = {{1, 2, 3},       //начальный массив
                               {4, 5, 6},
                               {7, 8, 9}};
    int new_massive[SIZE][SIZE] = {{0, 0, 0},
                                   {0, 0, 0},
                                   {0, 0, 0}};  //новый массив, где у нас будет находится матрица из первого массива, умноженная сама на себя

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
              for (int k = 0; k < SIZE; k++)
              {
                new_massive[i][j] += massive[i][k] * massive[k][j]; //заполняем элементы массива по правилам умножения матриц
              }
        }
    }
    return 0;
}
