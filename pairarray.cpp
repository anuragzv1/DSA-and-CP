#include<bits/stdc++.h>
using namespace std;

int main(){
    //gfg cpp template 
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n];
        int brr[m];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int j=0;j<m;j++){
            cin>>brr[j];
        }
        int num;
        cin>>num;
        sort(arr, arr+n);
        sort(brr, brr+m);

        for(int z=0;z<n-1;z++){
            for(int x=0;x<m-1;x++){
                if(num<(arr[z+1]+brr[x+1]) && num>(arr[z]+brr[x])){
                    cout<<arr[z]<<" "<<brr[x]<<endl;
                }
                if(num == arr[z]+brr[x]) cout<<arr[z]<<" "<<brr[x]<<endl;
                
            }
        }

        cout<<"\n";
    }
    return 0;
}