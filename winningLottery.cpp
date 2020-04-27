#include "stdc++.h"
using namespace std;


bool possibleFor(long long n,int sum){
    int s =0;
    while(n!=0){
        int d = n%10;
        n=n/10;
        s +=d;
    }

    if(s==sum) return true;
    else return false;
}

int main() {
    int s,d;
    cin>>s>>d;

    long long maxDig;
    long long minDig;
    string s1 ="9";
    string s2 ="1";

    for(int i =0;i<d-1;i++){
        s2=s2+"0";
    }

    for(int i=0;i<d-1;i++){
        s1=s1+"9";
    }

    maxDig = stoll(s1);
    minDig= stoll(s2);
    cout<<"min= "<<minDig<<" max = "<<maxDig<<endl;
    

    long long ans;
    for(long long i=minDig; i<=maxDig;i++){
        if(possibleFor(i,s)){
            ans = i ;
            break;
        }
    }
    cout<<ans<<endl;

}