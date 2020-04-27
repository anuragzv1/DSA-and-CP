#include<iostream>
using namespace std;
int main(){
    
    int *p = new int[5];
    cout<<p<<endl;
    for(int i=0;i<5;i++){
        cin>>p[i];
    }
    cout<<p[5]<<endl;
    p[5]=9;
    cout<<p[5]<<endl;
    for(int z=0;z<10;z++){
        cout<<p[z]<<" ";
    }
}