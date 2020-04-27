#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int spaces=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==' ' && str[i+1]!=' '){
            spaces++;
        }
    }
    cout<<"No of words = :"<<spaces+1<<endl;
    return 0;
}