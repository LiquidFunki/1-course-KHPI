/**@file lab13_04.c
 * Зашифрувати вхідний текст шифром цезаря
 * @author Klymenko Y.
 * @version 1.0
 */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/**
 * Функція main: Порівнює вхідний текст з алфавітом, та замінює відповідні символи тексту на символи шифрованого алфавіту "цезаря".
 */
void get_data_from_file(char *name, char *data, int size);
void put_data_to_file(char *name, char * result);

int main(){

    char *entering_text = malloc(256 * sizeof(char));
    puts("Enter the name of your file with input data:");
    scanf("%s", entering_text);

    char *data_file = malloc(256 * sizeof(char));
    get_data_from_file(entering_text, data_file, 256);

    //char text[] = "quick youth is a free ticket to hell";

    char original_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char cesar_alphabet[] = "cdefghijklmnopqrstuvwxyzab";
    for ( size_t i = 0; i < strlen(data_file) - 1; i++ ){
        for ( size_t j = 0; j < strlen(original_alphabet) - 1; j++ ){
            if ( *(data_file + i) == cesar_alphabet[j] ){
                *(data_file + i) = original_alphabet[j];
            }
        }
    }
    
    char *result_data = malloc(256 * sizeof(char));
    puts("Enter the name of your file with input data:");
    scanf("%s", result_data);
    put_data_to_file(result_data, data_file);
    return 0;
}
void get_data_from_file(char *name, char *data, int size){
    FILE * first_value = fopen(name, "r");
    if (first_value == NULL){
        puts("Error");
    }
    fgets(data, size, first_value);
    fclose(first_value);
}

void put_data_to_file(char *name, char * result){
    FILE * last_value = fopen(name, "w");
    if (last_value == NULL){
        puts("Error");
    }
    for(int i = 0; i < strlen(result); i++) {
        fprintf(last_value, "%c", *(result + i));
    }
    fclose(last_value);
}