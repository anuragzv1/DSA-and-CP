#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    bool arr[n+1];
    fill(arr ,arr+n+1 ,true);
    arr[0] =false;
    arr[1]=false;
    arr[2]=true;

    for(int i =2; i<=pow(n, 0.5);i++){
        if(arr[i]==false)continue;
        int k = i;
        while(i*k<=n){
            arr[i*k]=false;
            k++;
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++){
    if(arr[i])ans++;
    }
    cout<<ans<<endl;

    return 0;
}