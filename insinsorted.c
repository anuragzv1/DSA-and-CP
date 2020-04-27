#include <stdio.h>

void main()
{
    int arr[] = {2, 3, 5, 7, 8, 23, 45, 78, 79};
    int i, j, k, l = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    scanf("%d", &k);
    for (i = 0; i < size; i++)
    {
        if (arr[i] > k)
        {
            for (j = size - 1; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = k;
            l = 1;
        }
        if (l == 1)
            break;
    }
    for (i = 0; i <= size; i++)
    {
        printf("%d,", arr[i]);
    }
}