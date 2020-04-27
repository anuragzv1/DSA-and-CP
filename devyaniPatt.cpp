#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;

    int i =0;
    while(i<n){
        int spaces = 0;
        while(spaces<n-i-1){
            cout<<" ";
            spaces++;
        }

        int firststar = 0;
        while(firststar<i){
            cout<<"*";
            firststar++;
        }

        cout<<"#";

        int secondstar = 0;
        while(secondstar<i){
            cout<<"*";
            secondstar++;
        }
        cout<<endl;
        i++;
    }
}