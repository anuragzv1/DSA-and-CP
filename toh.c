#include <stdio.h>

int toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        printf("move 1 disk from %d to %d \n", a, c);
        toh(n - 1, b, a, c);
    }
}

int main()
{
    toh(3, 1, 2, 3);
    return 0;
}