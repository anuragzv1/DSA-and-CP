#include <iostream>
using namespace std;
void printPatt(int n)
{
    int mid = (n + 1) * 0.5;
    int i = 0;
    int k = 1;
    while (i < n)
    {
        if (i < mid)
        {
            int x = i;
            while (x < mid)
            {
                cout << "*";
                x++;
            }

            if (i >= 1)
            {
                int spaces = 1;
                while (spaces <= k)
                {
                    cout << " ";
                    spaces++;
                }
                k = k + 2;
            }
            if (i >= 1)
            {
                int fp2 = i;
                while (fp2 < mid)
                {
                    cout << "*";
                    fp2++;
                }
            }
            else
            {
                int z = n - mid;
                for (int ix = 0; ix < z; ix++)
                {
                    cout << "*";
                }
            }
        }
        else
        { 
            int kz =i-(n-mid)+1;
            int patt2=0;
            while(patt2<kz){
                cout<<"*";
                patt2++;
            }

            int spacesz=4;
            while(spacesz<k){
                spacesz++;
                cout<<" ";
            }
            k=k-2;
            int patt3;
            if(i==n-1){
                patt3=1;
            }
            else patt3=0;
            while(patt3<kz){
                cout<<"*";
                patt3++;
            }

        }

        cout << endl;
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    printPatt(n);
    return 0;
}