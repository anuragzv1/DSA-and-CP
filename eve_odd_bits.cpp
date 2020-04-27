#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    if((n & 1)==0)cout<<"even \n";
    else cout<<"odd \n";

    return 0;
}