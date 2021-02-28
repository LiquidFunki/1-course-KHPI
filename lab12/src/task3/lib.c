#include "lib.h"

void filling_entering_array(int size, double ** array){
    char value[30];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            puts("Enter your value.");
            fread(value, sizeof(char), 4, stdin);
            *(*(array + i) + j) = atoi(value);
        }
    }
}

void sort_array(int size, double **array, double *result_array) {
    double temp = 0.0; //змінна, що виконує функцію буфуеру
    for (int i = 0; i < ARRAY_SIZE; i++) {
        temp = *(*(array) + i);
        for (int j = 1; j < ARRAY_SIZE; j++) {
            if (*(*(array + j) + i) > temp) {
                temp = *(*(array + j) + i);
            }
        }
        *(result_array + i) = temp;
    }
}

void print_result_array(int size, double * result_array) {
    char **result_buf = (char **) malloc(size * 2 * sizeof(char *));
    for (int i = 0; i < size * 2; i++) {
        result_buf[i] = (char *) malloc(12 * sizeof(char));
    }
    for(int i = 0; i < ARRAY_SIZE; i++) {
        sprintf(* (result_buf + i), "%f", * (result_array + i));
        fwrite(* (result_buf + i), sizeof(char), strlen(result_buf) , stdout);
    }
}