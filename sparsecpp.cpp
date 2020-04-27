#include<iostream>
using namespace std;

class Element{
public:
int i;
int j;
int x;
};


class Sparse{
    private:
    int n;
    int m;
    int num;
    Element *ele;

    public:
    Sparse(int n ,int m, int num){
        this->n=n;
        this->m=m;
        this->num=num;
        ele = new Element [this->num];
    }
    ~Sparse(){
        delete [] ele;
    }

    void read(){
        cout<<"enter the elements";
         for(int i=0;i<num;i++){
             cin>>ele[i].i>>ele[i].j>>ele[i].x;
         }
    }

    void display(){
        int k=0;
        for(int i=0;i<this->num;i++){
            for(int j=0;j<this->n;j++){
                if(ele[k].i==i && ele[k].j==j){
                    cout<<ele[k++].x<<" ";
                }
                else cout<<"0 ";
            }
            cout<<"\n";
        }
    }



};


int main(){
    Sparse s1(5,5,5);
    s1.read();
    s1.display();
    return 0;
}