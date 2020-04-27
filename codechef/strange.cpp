#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;

        if(k==0 || x==0)cout<<"0\n";
        else if(k>x)cout<<"0\n";
        else cout<<"1\n";
    }
    return 0;
}