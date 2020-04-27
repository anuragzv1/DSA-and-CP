#include<iostream>
using namespace std;

int removeDup(int * arr , int n){
    int j =1 ,i=1;
    while(j<n){
        if(arr[j]!=arr[i-1]){
            arr[i] = arr[j];
            i++;
        }
        j++;
    }
    return i;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)cin>>arr[i];
    int size = removeDup(arr , n);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}