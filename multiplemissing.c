#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 8, 9, 12, 14, 15, 17};
    int asize = sizeof(a) / sizeof(a[0]);
    int diff = a[0] - 0;
    for (int i = 0; i < asize; i++)
    {
        if ((a[i] - i) != diff)
        {
            while (diff < a[i] - i)
            {
                printf("Missing element : %d \n", i + diff);
                diff++;
            }
        }
    }
}