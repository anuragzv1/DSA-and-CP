#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int num =t;
    int sum=0;
    while(num>0){
        int digit= num%10;
        num=num/10;
        sum = sum*10+digit;
    }
    if(sum==t)
        cout<<"Palindrome \n";
    else cout<<"Not Palindrome \n";
}