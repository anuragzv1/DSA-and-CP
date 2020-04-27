#include <stdio.h>

int main()
{
    int i, j, i1;
    char b;
    char arr[] = {'w', 'e', 'l', 'c', 'o', 'm', 'e'};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (j = 0; j < 50; j++)
    {
        for (i1 = 0; i1 < size; i1++)
        {
            printf("%c,", arr[i1]);
        }
        printf("\n");
        b = arr[0];
        for (i = 0; i < size - 1; i++)
        {
            
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = b;

        
    }
}