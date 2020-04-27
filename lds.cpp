#include<iostream>
using namespace std;

int lds(int * input , int n){
    int dp[n];
    dp[0]=1;

    for(int i =1;i<=n;i++){
        dp[i]=1;
        int j = i-1;
        while(j>=0){
            if(input[i]<input[j]){
                int possibleAns = 
            }
            j--;
        }
    }

}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = lds(arr , n);

    cout<<ans<<endl;
}