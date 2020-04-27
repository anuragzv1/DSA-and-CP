#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = 1;
        if (n == 1)
        {
            cout<<1<<endl;
            cout<<1<<" 1"<<endl;
        }
        else if (n == 2)
        {
            cout<<1<<endl;
            cout<<2<<" 1 2"<<endl;
        }
        else
        {
            cout << n / 2 << endl;
            while (k < n)
            {
                if (k == 1)
                {
                    cout << "3 " << 1 << " ";
                    cout << ++k << " ";
                    if(k==n)break;
                    cout << ++k << " " << endl;
                }
                else
                {
                    if(k+2<=n)cout << 2 << " ";
                    else cout<<1<<" ";
                    cout<< ++k << " ";
                    if(k==n)break;
                    cout << ++k << " ";
                    cout << endl;
                }
            }
        }
    }
    return 0;
}