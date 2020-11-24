#define SIZE 255
int main()
{
  char text[SIZE] = {"Segodnya  horoshiy den i   solnce  svetit"};
  int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (text[i] != ' ')
        {
            while (text[i] != ' ')
            {
                if (i == SIZE - 1)//если не будет этого условия, то индекс выйдет за диапазон массива
                {
                    break;
                }
                i++;
            }
            count++;
        }
    }
  return 0;
}
