#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE_MAX 250

int main(){

    char res[] = "i am so tired of this";
    char space[] = " ";
    char *max_word ;
    char *min_word ;

    size_t max_len = 0;
    size_t min_len = SIZE_MAX;

    for (char *word = strtok(res, space); word != NULL; word = strtok(NULL, space)) {
        size_t len = strlen(word);

        if (len > max_len) {
            max_len = len;
            max_word = word;
        }

        if (len < min_len) {
            min_len = len;
            min_word = word;
        }
    }

    printf("the longest word is: %s\n", max_word);
    printf("the shortest word is: %s\n", min_word);

    return 0;
}
