#include<iostream>
using namespace std;

int main (){

    int n;
    cin>>n;
    string arr[n];
    for(int i =0;i<n;i++)cin>>arr[i];
    int qn;
    string s = "";
    for(int i=0;i<n;i++){
        s+=arr[i];
    }

    cin>>qn;
    for(int i =0;i<qn;i++){
        int q;
        cin>>n;
        if(q<s.length()){
            cout<<s[q];
        }
        

    }

    return 0;
}