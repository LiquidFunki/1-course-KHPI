#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 3

int main(){

    float temp; //змінна, що виконує функцію буфуеру
    float * result_array = (float*)malloc(ARRAY_SIZE * sizeof(float)); //покажчик на масив
    float value;
    float array[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            printf("Enter your value.\n");
            scanf("%f", &value);
            array[i][j] = value;
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

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%f ", * (result_array + i));
    }
    free(result_array);
}
