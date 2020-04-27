#include<iostream>
using namespace std;
int main(){
cout<<"Enter basic salary"<<endl;
int basic,da,hra;
cin>>basic;
cout<<"Enter DA % and HRA %"<<endl;
cin>>da>>hra;
int gross = basic + (basic*da/100)+(basic*hra/100);
cout<<"the net salary is: "<<gross;
    return 0;
}