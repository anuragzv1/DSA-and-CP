#include<iostream>
#include<climits>
using namespace std;

int main(){
    cout<<"Enter size of the array :\n";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Array elements :\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++){
        int min =arr[i];
        int indexOfMin=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<=min){
            min =arr[j];
            indexOfMin=j;
            }
           
        }
        int temp =arr[i];
        arr[i]=min;
        arr[indexOfMin]=temp;
    }

    for(int z=0;z<n;z++){
        cout<<arr[z]<<" ";
    }

    return 0;
}