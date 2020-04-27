#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin, str);

    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            for(int j=i;j<str.length();j++){
                str[j]=str[j+1];
            }
        }
    }
    cout<<"\n";
    cout<<str[0];
    int k=1;
    for(int i=1;i<=81;i++){
        cout<<str[i];k++;
        if(k==9){
            cout<<"\n";
            k=0;
        }
        
    }

}
