#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        if (i < n - 1)
        {
            if (s1[i] != s2[i] && s1[i + 1] != s2[i + 1])
            {
                swap(s1[i], s1[i + 1]);
                cost++;
                i += 2;
            }
            else
            {
                if (s1[i] == 0)
                    s1[i] = 1;
                else
                    s1[i] = 0;
                cost++;
            }
        }
        else
        {
            if (s1[i] == 0)
                s1[i] = 1;
            else
                s1[i] = 0;
            cost++;
        }
    }
    cout << cost << endl;
    return 0;
}