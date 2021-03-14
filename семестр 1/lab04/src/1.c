#include <math.h>
#define PI 3.14
int main(){
    float l, v, s;
    char command = 'l';
    float r = 6.0;
    float result;
    if (command == 'l'){
        result = 2.0 * PI * r;
    }
    else if (command == 's'){
        result = PI * r * r;
    }
    else if (command == 'v'){
         result = (4.0 * PI * r * r * r)/3.0;
    }
    printf ("%.1f", result);
    return 0;
}
