#define SIZE 3
int main()
{
    int array[SIZE][SIZE] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    for (int i = 0; i < SIZE; i++)
    {
        int buffer = array[i][0];//закидываем в буффер 0 элемент каждого из массивов в нашем двумерном массиве
        for (int j = 0; j < SIZE; j++ )

            array[i][j] = array[i][j+1];//делаем некий круговорот элементов в массиве
            array[i][SIZE - 1] = buffer;// и на последний элемент закидываем первый элемент из буффера

    }
    return 0;
}
