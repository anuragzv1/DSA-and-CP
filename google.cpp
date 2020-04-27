#include<iostream>
using namespace std;

void square(int * x){
    *x = (*x+1)*(*x);
}

int main(){
    int num = 10;
    square(&num);
    cout<<num;
    return 0;
}