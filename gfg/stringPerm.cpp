#include<iostream>
using namespace std;


void perm (string s, string op){
    if(s.length()==0){
        cout<<op<<" ";
        return;
    }
    perm (s.substr(1) , op+s[0]);
    perm (s.substr(1), op);
}

int main(){
    string s;
    cin>>s;
    perm(s, "");
    return 0;
}