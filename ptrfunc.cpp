#include<iostream>
#include<string>
using namespace std;
// This program demonstrate function to pointer.

int display(string str){
    cout<<"You passed the string "<<str<<"by pointer \n";
    return 0;
}

int main(){
    int (*dp)(string) = display;
    (*dp)("Anurag");
    return 0;
}