#define SIZE 50
int main()
{
    int simple[SIZE];
    int num1 = 2;
        for ( int i = 0 ; i < SIZE; i++ )
        {
            for ( int j = num1; j < 9999; j++)
            {
                int prime = 1; // простое
                for ( int num = 2; num <= j/2; num++)
                {
                    if ( j % num == 0)
                    {
                            prime = 0;// не простое
                            break;
                    }
                }
                if ( prime == 1)
                {
                    simple[i] = j;
                    num1 = j + 1;// увеличиваем входное число для дальнейшей работы с ним в 3ьем цикле for
                    break;
                }
            }
        }
     return 0;
}
