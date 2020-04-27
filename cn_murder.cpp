#include "stdc++.h"
using namespace std;

int merge(int *arr , int low , int mid , int high){
    int i=low;
    int j=mid;
    int temp[high-low+1];
    int k=0;
    int count=0;
    while(i<mid && j<=high){
        if(arr[i]<=arr[j]){
            if(arr[i]!=arr[j]){
                count+=arr[i]*(high-j+1);
            }
            temp[k++] = arr[i++];
            
        }
        else if(arr[j]>arr[i]){
            temp[k++] = arr[j++];
        }
    }
    return count;
    
}


int getSum(int * arr ,int low , int high){
    int sum = 0;
    while(low<high){
        int mid = (low+high)/2;
        int leftSum = getSum (arr , low , mid);
        int rightSum = getSum(arr , mid+1 , high);
        int mysum = merge(arr , low , mid+1 , high);
        return leftSum+rightSum+mysum;
    }
    return sum;
}


int main() {

	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<getSum(arr , 0 , n-1)<<endl;
    }
}