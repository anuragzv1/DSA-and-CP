#include <iostream>
using namespace std;

int merge(int *arr, int low, int mid, int high)
{
    int s_f_a = low;
    int e_f_a = mid;
    int len1 = e_f_a - s_f_a + 1;
    int s_s_a = mid + 1;
    int e_s_a = high;
    int k = 0;
    int size_of_temp_arr = high - low + 1;
    int *op = new int[size_of_temp_arr];
    int inv_count = 0;

    while (s_f_a <= e_f_a && s_s_a <= e_s_a)
    {
        if (arr[s_f_a] <= arr[s_s_a])
        {
            op[k++] = arr[s_f_a];
            s_f_a++;
        }
        else if (arr[s_f_a] > arr[s_s_a])
        {
            op[k++] = arr[s_s_a];
            inv_count += len1 - s_f_a;
            s_s_a++;
        }
    }
    while (s_f_a <= e_f_a)
    {
        op[k++] = arr[s_f_a++];
    }

    while (s_s_a <= e_s_a)
    {
        op[k++] = arr[s_s_a++];
    }

    for(int i=0;i<k;i++){
        arr[low+i] =op[i];
    }

    return inv_count;
}

int mergeSort(int *arr, int low, int high)
{
    int inv_count=0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        inv_count=mergeSort(arr, low, mid);
        inv_count+=mergeSort(arr, mid + 1, high);
        inv_count+=merge(arr, low, mid, high);
    }
    return inv_count;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<mergeSort(arr, 0, n - 1)<<" ";

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    return 0;
}