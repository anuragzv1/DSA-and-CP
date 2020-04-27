#include"stdc++.h"

using namespace std;

class Term{
public:
int cofficient;
int exponent;
};

class Polynomial{
private:
int num;
Term *term;

public:
Polynomial(int num){
this->num = num;
term= new Term[this->num];
}

void read(){
    for(int i=0;i<num;i++){
        cout<<"Enter element at posttion"<<i+1<<": ";
        cin>>term[i].cofficient>>term[i].exponent;
    }
}

void display(){
    for(int i=0;i<num;i++){
        if(i!=num-1){
            cout<<term[i].cofficient<<"x"<<"^"<<term[i].exponent<<"+";
        }
        else cout<<term[i].cofficient<<"x"<<"^"<<term[i].exponent;
    }
    cout<<endl;
}

void evaluate(int x){
    int sum=0;
    for(int i=0;i<num;i++){
        sum = sum + (term[i].cofficient*pow(x,term[i].exponent));
    }
    cout<<"The evaluated sum is"<<sum;
}
};

int main(){
    Polynomial p1(5);
    p1.read();
    p1.display();
    p1.evaluate(1);
    return 0;
}