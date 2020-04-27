#include<iostream>
using namespace std;
const int m = 100000007;

bool ispossible(int n ){

}

int main(){
    long long n;
    cin>>n;
    long long count=0;
    for(int i = 1;i<n;i++){
        if(ispossible(i)){
            count++;
            count=count%m;
        }
        cout<<count<<endl;
    }
}