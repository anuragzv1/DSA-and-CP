#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int i=1;
while(i<=n){
    int j=1;
    while(j<=n){
        if(j<=n-i+1)
        cout<<j;
        else cout<<"*";
        j++;
    }
    int pattern2=n;
    while(pattern2>=1){
        if(pattern2<=n-i+1)
        cout<<pattern2;
        else cout<<"*";
        pattern2--;
    }
    i++;
    cout<<endl;
}
    return 0;
}