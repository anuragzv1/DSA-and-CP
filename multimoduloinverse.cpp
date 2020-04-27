#include<iostream>
using namespace std;

class triplet{
    public:
        int x;
        int y;
        int gcd;
};
int gcd(int a , int b){
    if(b>a){
        return gcd(b,a);
    }
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
triplet extendedEuclid(int a, int b){
    if(b>a)return extendedEuclid(b,a);
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = extendedEuclid(b , a%b);
    triplet ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    ans.gcd = smallAns.gcd;
    return ans;

}

int main(){
    int a , m;
    cin>>a>>m;
    int gcdans = gcd(a,m);
    if(gcdans==1){
        cout<<extendedEuclid(a , m).x;
    }
    else cout<<"Multiplicative moudulus not possible"<<endl;
    return 0;
}