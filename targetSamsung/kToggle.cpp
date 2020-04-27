#include "stdc++.h"
using namespace std;

int global_amp;

int amp(int **mat , int n , int m){
    int amp =0;
    for(int i=0;i<n;i++){
        bool allOnes= true;
        for(int j=0;j<m;j++){
            if(mat[i][j]!=1){
                allOnes = false;
                break;
            }
        }
        if(allOnes)amp++;
    }
    return amp;
}



void kToggle(int **arr, int n, int m, int k, int current_col)
{
    if(k==0){
            global_amp = max(global_amp,amp(arr,n,m));
            return;
    }
    if(current_col>=m )return;

    kToggle(arr,n,m,k,current_col+1);
    for(int i=0;i<n;i++){
        if(arr[i][current_col]==1)arr[i][current_col]=0;
        else arr[i][current_col]=1;
    }

    kToggle(arr, n ,m ,k-1,current_col+1);
    kToggle(arr , n , m , k-1,current_col);

}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<endl;
     kToggle(arr, n, m, k, 0);
    cout << global_amp;

    return 0;
}