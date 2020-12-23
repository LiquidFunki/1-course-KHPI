#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @file lab11_04.c
 * @brief програма виписує, упорядковані за зростанням, елементи головної
 * діагоналі в одновимірний масив з двовимірного.
 *
 * @author Klymenko Y.
 * @date 10-dec-2020
 * @version 0.1
*/

/**
 * Сортування елементів масиву за зростанням.
 * @param size розмір масиву, котрий заданий в головній функції.
 */

void bubble_sort(int* arr, int size);

/**
Головна функція  {оголошення змінної N з розміром масиву,
                  показчиків на масив з результатом та двовимірний масив, котрий
                  заповнюється за допомогою псевдовипадкового генератора. Потім
                  заповнюється результуючий масив елементами головної діагоналі.
                  Далі оголошується функція bubble_sort, котра сортує елементи
                  головної діагоналі за зростанням. Далі йде вивід результуючого
                  масиву.
                 }
*/

int main(){
  srand(time(NULL));

  int N = 10;
  int * result_array = (int*)malloc(N * sizeof(int));
  int ** arr = (int **)malloc(N * sizeof(int *));

  for(int i=0; i<N; i++){
    arr[i] = (int *)malloc(N*sizeof(int));
  }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
           arr[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++){
      * (result_array + i) = arr[i][i];
    }

    bubble_sort(result_array, N);

    for(int i = 0; i < N; i++){
      printf("%d ", * (result_array + i));
    }

    free(result_array);
    free(arr);
}

void bubble_sort(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if ( *(arr + j) > *(arr + j + 1) ) {
        int temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
      }
    }
  }
}
