#include<iostream>
using namespace std;

int main(){

    int n,i;
    cin>>n>>i;

    cout<<(n  & (INT_MAX-(1<<i)));
    return 0;
}