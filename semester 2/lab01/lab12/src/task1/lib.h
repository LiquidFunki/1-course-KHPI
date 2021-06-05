#ifndef PROGRAMING_REPO_LIB_H
#define PROGRAMING_REPO_LIB_H
/**
* @file lib.h
* @brief Task1
*
* @author Klymenko Y.
* @date 15-feb-2021
* @version 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Size of incoming array
*/

#define ARRAY_SIZE 3
/**
* Function, that fills entering array
*
* @param array - array we got
*/


void filling_entering_array(int size, float **array);

/**
* Function, that sorts elements of the array
*
* @param array - entering array
* @param result_array - array, which has elements with the biggest value from every column
*/

void sort_array(int size, float **array, float *result_array);


/**
 * Function, that shows the result in console
 *
 * @param result_array - array, which is shown in console
 */

void print_result_array(int size, float * result_array);
#endif //PROGRAMING_REPO_LIB_H