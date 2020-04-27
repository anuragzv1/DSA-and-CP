#include <iostream>
using namespace std;

int allIndexes(int arr[], int n, int x, int output[])
{
    if (n == 0)
    {
        return 0;
    }
    /* assume that recursion has already saved all the indices in the opt array
    and we are working on the last element. */

    int smallSize = allIndexes(arr, n - 1, x, output);
    if (arr[n - 1] != x)
    {
        return smallSize; //if the last element is not x then we just need to return previous & size.
    }
    else
    {                              //else we need to insert that index in the last location of opt array
        output[smallSize] = n - 1; //and increase size by one.
        return 1 + smallSize;
    }
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;
}