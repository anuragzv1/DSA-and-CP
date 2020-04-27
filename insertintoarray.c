#include <stdio.h>
int arr[] = {5, 6, 3, 5, 6, 4, 4, 6, 6, 78, 454};
int insertFunc(int index, int number)
{
    int i;
    int arrsize = sizeof(arr) / sizeof(int);
    printf("size of array = %d\n", arrsize);
    for (i = arrsize; i >= index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = number;

    for (i = 0; i <= arrsize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n Size of new array =%d \n", sizeof(arr) / sizeof(int));
}

int main(){
    insertFunc(3,33333);
}