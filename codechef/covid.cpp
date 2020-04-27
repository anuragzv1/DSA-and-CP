#include "stdc++.h"
using namespace std;

bool mycomp(int a , int b){
    return a>=b;
}

int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr , arr+n ,mycomp);

        int profit = 0;
        for(int  i =0;i<n;i++){
            profit+=max(arr[i]-i ,0);
        }
        cout<<profit<<endl;

    }

    return 0;
}
// 3
// 3
// 1 0 1
// 7
// 1 0 0 0 0 0 1
// 11
// 0 1 0 0 0 0 0 1 0 0 1