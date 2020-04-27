

#include "stdc++.h"
using namespace std;
#define MAXN 100005

int merge(int *arr, int low, int mid, int high)
{

    int inv_count = 0;

    int i = low;
    int j = mid + 1;
    int len = high - low + 1;
    int *op = new int[len];
    int lfh = mid - low + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[j] < arr[i])
        {
            inv_count += lfh - i;
            op[k++] = arr[j];
            j++;
        }
        else if (arr[i] <= arr[j])
        {
            op[k++] = arr[i];
            i++;
        }
        cout << "Infinite ";
    }

    while (i <= mid)
    {
        op[k++] = arr[i];
        i++;
    }
    while (j <= high)
    {
        op[k++] = arr[j];
        j++;
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = op[k++];
    }

    return inv_count;
}

int mergeSort(int *arr, int low, int high)
{
    int mid, lh, rh, m;
    if (low < high)
    {
        mid = low + high / 2;
        lh = mergeSort(arr, low, mid);
        rh = mergeSort(arr, mid + 1, high);
        m = merge(arr, low, mid, high);
    }
    return lh + rh + m;
}

long long solve(int A[], int n)
{
    cout << mergeSort(A, 0, n - 1);
}

int main()
{
    int n, A[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << solve(A, n) << endl;
}