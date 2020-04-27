#include <stdio.h>

int right_maxx(int arr[], int index, int n)
{
    int max_right =0;
    for (int i=index;i<n;i++)
    {
        if (arr[i] >= max_right)
        {
            max_right = arr[i];
        }
        
    }
    return max_right;
}

int left_maxx(int arr[], int index, int n)
{
    int max_left = arr[0];
    for (int j=0;j<index;j++)
    {
        if (arr[j] >= max_left)
        {
            max_left = arr[j];
        }
    }
    return max_left;
}

int main()
{
    int n=5;
    int arr[]={3,5,9,6,7};
    int right = right_maxx(arr,1,n);
    int left = left_maxx(arr,0,n);
    printf("%d ", right);
    printf("%d ", left);

    return 0;
}
