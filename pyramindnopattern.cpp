#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int i=1;
while(i<=n){
    int spaces=1;
    while(spaces<=n-i){
        cout<<" ";
        spaces++;
    }
    int j=i;
    while(j>=1){
        cout<<j;
        j--;
    }

    int pattern2=2;
    while(pattern2<=i){
        cout<<pattern2;
        pattern2++;
    }

    i++;
    cout<<endl;
}
    return 0;
}