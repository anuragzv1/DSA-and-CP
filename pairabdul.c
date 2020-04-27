#include <stdio.h>

int main()
{
    int n;
    int t;
    int k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &arr[i]);
        }
        scanf("%d",&k);
        for (int ii = 0; ii < n; ii++)
        {
            for (int zz = ii; zz < n; zz++)
            {
               if(arr[zz]+arr[ii]==k){
                   printf("%d + %d,",arr[ii],arr[zz]);
               } 
            }
        }
    }
    return 0;
}