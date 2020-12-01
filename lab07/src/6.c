#include <stdio.h>
#include <time.h>
#define SIZE 3

void mas_func(int massive[SIZE][SIZE]);

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
    int new_massive[SIZE][SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

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



