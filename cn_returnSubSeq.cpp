#include"stdc++.h"
using namespace std;

int returnSS(string str , string* output){
    
}


int main(){
    string str;
    getline(cin, str);

    string output[1000];
    int len_of_op = returnSS(str , output);

    for(int i=0;i<len_of_op;i++){
        cout<<output[i]<<endl;
    }

    return 0;
}