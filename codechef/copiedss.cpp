#include <iostream>
using namespace std;
int main()
{

    int  t;
    cin >> t;

    while (t--)
    {
        long long int n, i, j;
        int c = 0, d = 0;

        long long  add = 1;

        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];

        for (i = 0; i < n; i++)
        {

            if (a[i] % 2 != 0 || a[i] % 4 == 0)d++;
            add = a[i];
            for (j = i + 1; j < n; j++)
            {
                add = add * a[j];
                if (add % 2 != 0 || add % 4 == 0)c++;
            }

            add = 1;
        }

        cout << c + d << "\n";
    }

    return 0;
}