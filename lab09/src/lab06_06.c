#include <stdio.h>
#include <time.h>
#define SIZE 3

/**
 * @file lab06_06.c
 * @brief Перемноження матриці саму на себе
 *
 * @author Klymenko Y.
 * @date 10-dec-2020
 * @version 0.1
*/

/**
 * Перемноження матриці саму на себе
 * @param massive первинний масив з матрицею
 */

void mas_func(int massive[SIZE][SIZE]);

/**
Головна функція  {оголошення первинного масиву,
                  заповнення його псевдовипадковими значеннями,
                  оголошення функції mas_func
                 }
*/

int main()
{
    srand(time(NULL));
    int massive[SIZE][SIZE];
        for(int i = 0; i <= SIZE; i++)
        {
            for(int j = 0; j <= SIZE; j++){
                massive[i][j] = rand() % 10;
            }
        }
    mas_func(massive);
    return 0;
}



void mas_func(int massive[SIZE][SIZE])
{
    int new_massive[SIZE][SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};/**< перемножена сама на себе матриця*/

 /*заповнненя кожного нового елементу масиву з матрицею за правилами множення матриці*/
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
              for (int k = 0; k < SIZE; k++)
              {
                new_massive[i][j] += massive[i][k] * massive[k][j];
              }
        }
    }
    return;
}
