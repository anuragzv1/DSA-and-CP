#include<iostream>
using namespace std;

int maxDiff(int * arr , int n){
    int maxTillNow = 0;
    int minTillNow = 0;
    int diff = INT_MIN;
    for(int i =1;i<n;i++){
        diff = max(diff , arr[i]-arr[minTillNow]);
        if(arr[minTillNow]>arr[i])minTillNow = i;
    }
    return diff;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)cin>>arr[i];
    cout<<maxDiff(arr , n);
    return 0;
}