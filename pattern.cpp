#include<iostream>
using namespace std;

int main(){

cout<< "enter n \n";
int n;
cin>>n;
int k=1;
int i=1;
int val=1;
while(i<=n){
    int j=1;
    int k=1;
     while(k<=n-i){
         cout<<" ";
         k++;
     }
 while(j<=i){
     cout<<val;
     j++;
     val++;
 }
 i++;
 cout<<"\n";
 
}
   
    return 0;
}