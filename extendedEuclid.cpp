#include<iostream>
using namespace std;
//Extended euclid algorithm works with equations ax + by = gcd(a,b);
// x= y1;
//y = x1 -(a/b)*y1; 
//x1 and y1 are recieved from previous recursive call

class triplet{
public:
    int x;
    int y;
    int gcd;
};
triplet extendedEuclid(int a , int b){
    if(b>a)return extendedEuclid(a ,b);
    if(b==0){
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extendedEuclid(b , a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}


int main(){
    int a , b;
    cin>>a>>b;
    triplet ans = extendedEuclid(a , b);
    cout<<"x : "<<ans.x<<" y: "<<ans.y<<endl;
    return 0;
}