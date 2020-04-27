//this program sets the ith bit of a number to 1;

#include<iostream>
using namespace std;

int main(){

    int n,i;
    cin>>n>>i;

    cout<<(n | (1<<i));
    
    return 0;
}