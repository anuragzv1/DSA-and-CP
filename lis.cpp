#include <iostream>
using namespace std;

int lis(int *input, int n)
{
    int *output = new int[n];
    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        output[i] = 1;
        while (j >= 0)
        {
            if (input[j] < input[i])
            {
                int local_ans = output[j] + 1;
                if (local_ans > output[i])
                {
                    output[i] = local_ans;
                }
            }
            j--;
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (best < output[i])
        {
            best = output[i];
        }
    }
    delete[] output;
    return best;
}

int main()
{
    int n;
    cin >> n;
    int input[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int ans = lis(input, n);
    cout << ans << endl;

    return 0;
}