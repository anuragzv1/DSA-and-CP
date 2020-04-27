#include "stdc++.h"

using namespace std;

string* remainingStr(string s , char c){
    int i=0;
    for(;i<s.length();i++){
        if(s[i]==c)break;
    }
    string part1 = s.substr(0,i);
    string part2 = s.substr(i+1,s.length()-i-1);
    string * str = new string(part1+part2);
    return str;
}

void printSS(string input , string op=""){
    if(input.length()==0){
        cout<<op<<endl;
        return;
    }
    int no_of_op = input.length();
    string tempstr = input;
    for(int i=0;i<no_of_op ;i++){
        printSS(*remainingStr(tempstr , input[i]),input[i]+op);
    }
}

int main(){
    string s;
    cin>>s;

    printSS(s);
    return 0;
}