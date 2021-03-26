/**@file lab13_04.c
 * Зашифрувати вхідний текст шифром цезаря
 * @author Klymenko Y.
 * @version 1.0
 */
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>

 /**
  * Функція main: Порівнює вхідний текст з алфавітом, та замінює відповідні символи тексту на символи шифрованого алфавіту "цезаря".
  */
 int main(){
    char text[] = "quick youth is a free ticket to hell";
    char original_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char cesar_alphabet[] = "cdefghijklmnopqrstuvwxyzab";
    for ( size_t i = 0; i < strlen(text) - 1; i++ ){
        for ( size_t j = 0; j < strlen(original_alphabet) - 1; j++ ){
            if ( text[i] == cesar_alphabet[j] ){
                text[i] = original_alphabet[j];
            }
        }
    }
     return 0;
 }
