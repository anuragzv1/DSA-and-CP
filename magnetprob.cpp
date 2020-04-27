#include <iostream>
#include<cmath>
using namespace std;

double arr[101];
int n;

double calForce(double d){
    double force=0;
    for(int i=0;i<n;i++){
          force +=(1/(d-arr[i]));
        
    }
    return force;
}

double optIteration(double left,double right){
    double d;
    while(right>left){
        d=right+(left-right)*0.05;
        double retfor = calForce(d);
        if(abs(retfor)<0.0000000000001) return d;
        if(retfor>0) left =d;
         else right =d;
    }
    return left;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        for(int i=1;i<n;i++){
            printf("%0.2f ",optIteration(arr[i-1],arr[i]));
        }
        
        cout<<"\n";
    }
    return 0;
}