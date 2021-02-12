#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARRAY_SIZE 3

int main(){

    double temp = 0.0; //змінна, що виконує функцію буфуеру
    double * result_array = (double*)malloc(ARRAY_SIZE * sizeof(double)); //покажчик на масив
    char value[30];
    double array[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            puts("Enter your value.\n");
            fread(value, sizeof(char), 4, stdin);
            array[i][j] = atof(value);
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
    char result_buf[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++){
        sprintf(&result_buf[i], "%f", * (result_array + i));
        fwrite(&result_buf[i], sizeof(char), strlen(result_buf) , stdout);
    }
    free(result_array);
}
