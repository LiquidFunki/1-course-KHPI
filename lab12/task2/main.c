
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 3

float main(){

    float temp; //змінна, що виконує функцію буфуеру
    float * result_array = (float*)malloc(ARRAY_SIZE * sizeof(float)); //покажчик на масив
    char value[30];
    float array[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            puts("Enter your value.\n");
            gets(value);
            array[i][j] = atoi(value);
        }
    }
    for(int i = 0; i < ARRAY_SIZE; i++){
        temp = array[0][i];
        for(int j = 1; j < ARRAY_SIZE; j++){
            if(array[j][i] > temp){
                temp = array[j][i];
            }
        }
        * (result_array + i) = temp;
    }
    char result_buf[ARRAY_SIZE + 1];
    for(int i = 0; i < ARRAY_SIZE; i++){
        sprintf(&result_buf[i], "%f", * (result_array + i));
        puts(&result_buf[i]);
    }

    free(result_array);
}
