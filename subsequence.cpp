#include<iostream>
using namespace std;


int solve(int *a ,n ,k){
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(abs(arr[i]-arr[j])<=k){

            }
        }
    }
    return ans;
}
int main(){
int n,k;
cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int c = solve (arr,n,k);

    return 0;
}