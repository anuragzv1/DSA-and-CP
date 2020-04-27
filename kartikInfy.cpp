#include<bits/stdc++.h>
using namespace std;


string getdollars(int n){
    string ans = "";
    for(int i =0;i<n;i++){
        ans+='$';
    }
    return ans;
}
string reverseString(string s) 
{ 
    string rev = "";
    for(int i =s.length()-1;i>=0;i--){
        rev+=s[i];
    }
    return rev; 
} 
int main(){

    int n;
    cin>>n;
    string arr[n];
    for(int i =0;i<n;i++)cin>>arr[i];
    string a = "";
    for(int i =0;i<n;i++){
        a+=arr[i];
    }
    string tempa  = a;
    int qn;
    cin>>qn;
    for(int i =0;i<qn;i++){
        int q;
        cin>>q;
        int repeat = q/a.length();
        a= tempa;
        for(int j=1;j<=repeat+2;j++){
            string doll = getdollars(j);
            string rev= reverseString(tempa);
            a+=doll+rev;
        }
        cout<<a<<endl;
        cout<<a[q-1]<<endl;
    }
    return 0;
}