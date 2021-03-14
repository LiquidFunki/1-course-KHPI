#include "lib.h"

void sort_array(int size, float **array, float *result_array){
    float temp;//змінна, що виконує функцію буфуеру
    for(int i = 0; i < ARRAY_SIZE; i++){
        temp = *(*(array) + i);
        for(int j = 1; j < ARRAY_SIZE; j++){
            if(*(*(array + j) + i) > temp){
                temp = *(*(array + j) + i);
            }
        }
        * (result_array + i) = temp;
    }
}
void filling_entering_array(int size, float ** array) {
    float value;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter your value.\n");
            scanf("%f", &value);
            *(*(array + i) + j) = value;
        }
    }
}
void print_result_array(int size, float * result_array){
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%f ", * (result_array + i));
    }
}
