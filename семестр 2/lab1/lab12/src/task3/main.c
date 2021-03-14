/**
* @mainpage
* # Main task
*  Find the elements from array with biggest value in every column and rewrite them into another array
*
*
* @author Klymenko Y.
* @date 15-feb-2020
* @version 1
*/
#include "lib.h"

/**
* Main function.
*
* Steps:
* - creating entering array
* - creating result array
* - using function filling_entering_array to write down the elements for entering array
* - using function sort_array to find out the biggest value in every column
* - using function print_result_array to show the result in console
* @return result of code (0)
*/
void filling_entering_array(int size, double ** array);
void sort_array(int size, double **array, double *result_array);
void print_result_array(int size, double * result_array);

int main(){

    double * result_array = (double*)malloc(ARRAY_SIZE * sizeof(double)); //покажчик на масив
    double ** array = (double**) malloc( ARRAY_SIZE * sizeof(double*));
        for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = (double *) malloc(ARRAY_SIZE * sizeof(double));
        }

    filling_entering_array(ARRAY_SIZE, array);
    sort_array(ARRAY_SIZE, array, result_array);
    print_result_array(ARRAY_SIZE, result_array);

    free(array);
    free(result_array);
}

