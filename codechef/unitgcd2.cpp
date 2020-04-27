#include<iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        cout<<"1 1\n";;
    }
    else if(n==2){
        cout<<"1\n";
        cout<<"2 1 2\n";
    }
    else{
        int k = 1;
        cout<<n/2<<"\n";
        for(int i = 0;i<n/2;i++){
            if(i==0){
                cout<<"3 ";
                cout<<k++<<" ";
                cout<<k++<<" ";
                cout<<k++<<" ";
            }
            else{
                if(k+1<=n)cout<<"2 ";
                else cout<<"1 ";
                cout<<k++<<" ";
                if(k>n)break;
                cout<<k++<<" ";
            }
            cout<<"\n";
        }
    }
    }
    return 0;
}