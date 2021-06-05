/**
* @mainpage
* # Task
*  1. Show the "tree" of the directory.
*  2. Calculate directory size.
*
* # Individual task
*  - Remake the task from lab13 using the interaction with files
*
* @author Klymenko Y.
* @date 27-feb-2021
* @version 1
*/
#include "lib.h"

/**
* Main fuction.
*
* Steps:
* - using function show_tree for the first task
* - using function put_directory_size_on_console for the second task
* - using function individual_task for the individual task of the lab
* @return true result of code (0)
*/

int main() {
    printf("First task:\n");
    printf("Tree of current directory:\n");
    show_tree(".", 1);

    printf("Second task:\n");
    put_directory_size_on_console();

    printf("Individual task:\n");
    individual_task();

    return 0;
}