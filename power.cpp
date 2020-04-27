#include<iostream>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n; //inputting x and n.
    int i=1;  //counter for multiplying n times
    int product=1;  //variable for storing product
     while(i<=n){
         product= product*x;
         i++;
    }
    cout<<product<<endl;
    return 0;
}