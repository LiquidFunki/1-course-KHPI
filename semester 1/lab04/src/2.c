#include <stdio.h>

int main()
{
    const float a = 536.869;
    float a1 = a;
    a1 = (int) a1;
    int a2 = a*1000;
    a2 = a2%1000;
    float result;
    char error;
    if (a1 == 0){
        error = 'E';
    }
    else {
        result = a2/a1;
        result *= 100;
        result = (int) result;
        result = (float) result;
        result = result / 100;
    }
    printf("%f", result);
    return 0;
}
