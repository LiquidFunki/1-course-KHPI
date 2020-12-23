#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE 3

/**
 * @mainpage
 * Task
 * 1. Виконання лабораторної роботи № 11 на оцінку "Добре".
 *
 * @author Klymenko Y.
 * @date 22-dec-2020
 * @version 1.0
 */

 /**
  * @file lab11_03.c
  * @brief програма переписує максимальні елементи з кожного стовпця масива масивів в одновимірний масив.
  *
  * @author Klymenko Y.
  * @date 23-dec-2020
  * @version 0.1
 */

 /**
 Головна функція  {оголошення змінної temp, двовимірного масиву array,
                   та показчика на масив з результатом. Далі виконється сортування стовпців,
                   де елемент з найбільшим значенням заповнюється в result_array. Далі йде вивод
                   результуючого масиву.
                  }
 */
int main(){

  double temp = 0.0; //змінна, що виконує функцію буфуеру
  double * result_array = (double*)malloc(ARRAY_SIZE * sizeof(double)); //покажчик на масив
  double array[ARRAY_SIZE][ARRAY_SIZE] = {{5.1, 4.3, -2.0},
                                          {2.2, 7.2, 3.3},
                                          {3.3, 5.1, 1.2}};
  for(int i = 0; i < ARRAY_SIZE; i++){
    temp = array[0][i];
    for(int j = 1; j < ARRAY_SIZE; j++){
            if(array[j][i] > temp){
                temp = array[j][i];
            }
    }
  * (result_array + i) = temp;
  }
  for(int i = 0; i < ARRAY_SIZE; i++){
  printf("%f ", * (result_array + i));
}
free(result_array);
}
