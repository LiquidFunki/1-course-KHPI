#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

/**
 * Function, that shows the "tree" of current directory and shows it in console
 *
 * @param directory_path - the name of the directory we need
 * @param tab - tabulation
**/
void show_tree(char * directory_path, int tab);


/**
 * Function, that gives the result of calculating the size of directory
**/
void put_directory_size_on_console();


/**
 * Function, that calculates directory size
 *
 * @param directory_path - name of the directory, which size will be calculated
**/
float calculate_directory_size(char * directory_path);

/**
 * Function, that calculates file size
 *
 * @param file - file, which size will be calculated
**/
int calculate_file_size(FILE * file);

/**
 * Function, that gets data from file
 *
 * @param name - file name
 * @param data - data from file
 * @param size - limit of symbols we can read from file
 */
void get_data_from_file(char *name, char *data, int size);

/**
 * Function, that puts down the result to file
 *
 * @param name - file name, where will be put down the result
 * @param result - result of the function
 */
void put_data_to_file(char * name, char * result);

/**
 * Function, that performs individual task
**/
int individual_task();

