#include<iostream>
using namespace std;

int main(){

    long long t;
    long long arr[100000];
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        for(int i =0;i<n;i++){
            if(arr[i]<0){
                arr[i] = -1*arr[i];
            }
        }
        for(int i = 0;i<n;i++){
            if(arr[i]%4==2)arr[i]=-1;
        }
        long long invalid = 0;
        long long total = n*(n+1)/2;
        for(int i =0;i<n;i++){
            if(arr[i]==-1){
            int j = i-1;
            int oddleft=0,oddright=0;
            while(j>=0){
                if(arr[j]==-1)break;
                if(arr[j]%2==1)oddleft++;
                else break;
                j--;
            }
            j=i+1;
            while(j<n){
                if(arr[j]==-1)break;
                if(arr[j]%2==1)oddright++;
                else break;
                j++;
            }
            long long tot = oddleft+oddright+1;
            invalid+=tot * (tot+1)/2 - ( oddright *(oddright+1)/2  + oddleft*(oddleft+1)/2);
            }
        }

        cout<<total-invalid<<endl;
        

    }
    return 0;
}