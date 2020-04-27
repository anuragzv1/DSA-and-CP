#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<n;j++){
        cin>>brr[j];
    }

    int max_match = INT_MIN;
    for(int i =0;i<n;i++){
        int local_match = 0;
        int x = arr[i]-brr[i];
        for(int j=0;j<n;j++){
            if((arr[j]+x)==brr[j]){
                local_match++;
            }
            if(local_match>max_match)max_match = local_match;
        }
    }

    for(int i=0;i<n;i++){
        int local_match =0;
        int x = brr[i]-arr[i];
        for(int j=0;j<n;j++){
            if((arr[j]+x)==brr[j]){
                local_match++;
            }
            if(local_match>max_match)max_match = local_match;
        }
    }

    cout<<max_match;
}