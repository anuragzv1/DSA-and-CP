#include "stdc++.h"
using namespace std;


const unsigned int M = 1000000007; 
bool mycomp(int a , int b){
    return a>=b;
}

int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr , arr+n ,greater<int>());

        long long profit = 0;
        for(int  i =0;i<n;i++){
            long long x = max(arr[i]-i,(long long)(0));
            profit=(profit%M+x%M)%M;
        }
        cout<<profit<<endl;

    }

    return 0;
}
