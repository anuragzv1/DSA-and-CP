#include<iostream>
using namespace std;

int main(){
    cout<<"Enter 2 numbers"<<endl;
    int a , b;
    cin>>a>>b;
    while (a!=b){
        if(a>b){
            a=a-b;
        }
        else b=b-a;
    }
    cout<<"the gdc is: "<<a<<endl;
    return 0;
}