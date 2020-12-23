#include <stdio.h>
#include <string.h>


int main() {
    char *p1, *p2;
    char str[] = "Скорочення т.д. т.п ін. замінити на повні словосполучення";

    char find1[] = "т.д.";
    char repl1[] = "так далі";

    char find2[] = "т.п.";
    char repl2[] = "тому подібне";

    char find3[] = "ін.";
    char repl3[] = "інше";


    while(p1 = strstr(str, find1)) {
        p2 = p1 + strlen(find1);
        strcpy(p1, repl1);
        strcat(str, p2);
    }

        while(p1 = strstr(str, find2)) {
        p2 = p1 + strlen(find2);
        strcpy(p1, repl2);
        strcat(str, p2);
    }

        while(p1 = strstr(str, find3)) {
        p2 = p1 + strlen(find3);
        strcpy(p1, repl3);
        strcat(str, p2);
    }

    printf("%s\n", str);
    return 0;
}
