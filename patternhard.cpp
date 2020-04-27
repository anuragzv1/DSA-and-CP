#include <iostream>

using namespace std;

void printPattern(int n)
{
    int arr[n][n];
    int dir = 0;
    int k = 1;
    int top = 0;
    int bottom = n - 1;
    int n1 = n;
    int i = 1;
    while (n1--)
    {
        if (dir == 0)
        {
            for (int j = 0; j < n; j++)
            {
                arr[top][j] = k++;
            }

            top++;
            dir = 1;
        }
        else 
        {
            for (int j = 0; j < n; j++)
            {
                arr[bottom][j] = k++;
            }
            bottom--;
            dir = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;
    printPattern(n);
    return 0;
}
