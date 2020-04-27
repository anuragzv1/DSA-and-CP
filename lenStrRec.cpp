#include<iostream>
using namespace std;

int lenStrRec(char input[]){
    if(input[0]=='\0') return 0;
    int smallOutput = lenStrRec(input+1);
    return 1+smallOutput;
}

int main(){
    char n []= "Hello world";
    cout<<lenStrRec(n);
    return 0;
}