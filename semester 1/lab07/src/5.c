#include <stdio.h>
#include <time.h>

float func(float num);

int main()
{
    srand(time(NULL));
    func(rand() % 100 + 1);
    return 0;
}


float func(float num)
{
    float root_num = 0.0;
        while ( root_num * root_num <= num )
        {
            root_num += 0.0001;
        }
    return root_num;
}
