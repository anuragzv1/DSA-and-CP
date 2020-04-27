#include"stdc++.h"
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int count=1;
    int n=0;
    //str = str+" ";
    for(int i=0;i<=str.length();i++){
        if(str[i]==' ' || str[i]=='\0'){
        string newsub = str.substr(n,i);
        n=n+i;
        cout<<newsub<<endl;
        }
        
    }
    string perc;
    getline(cin ,perc);
    string rebate;
    cin>>rebate;
    string tax_by_emp;
    getline(cin ,tax_by_emp);

    



    return 0;
}