#include <stdio.h>

int main()
{
    int t, i, n, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        int arr[n];
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        for (j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                printf("%d ", arr[j + 1]);
            }
            else
                printf("-1 ");
        }
    }
    return 0;
}