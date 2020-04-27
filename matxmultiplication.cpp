#include<iostream>
using namespace std;

int main(){
    int i,m,n;
    cout<<"Enter the size of matrix A \n";
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter elements in the array A \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    cout<<"Enter the size of matrix B \n";
    int a,b;
    int brr[a][b];
    cin>>a>>b;
    cout<<"Enter elements in the array B \n";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>brr[i][j];
        }
        cout<<endl;
    }
    int crr[n][a];
    if(n==a){
        for(int i=0;i<m;i++){
            for(int j=0;j<b;j++){
                for(int k =0;k<n;k++){
                   crr[i][j]+=arr[i][k]*brr[k][j];
                }
            }
        }
    }
    else cout<<"Multiplication not possible\n";

    for(int i=0;i<m;++i){
        for(int j=0;j<b;++j){
            cout<<crr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}