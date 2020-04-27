#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int greyConverter(int n)
{
    string temp = "";
    while(n>0){
        if(n&1){
            temp = "1"+temp;
        }
        else temp = "0"+ temp ;
        n>>=1;
    }
    
    string nu;
    if(temp[0]=='1'){
    nu="1";
    }
    else nu="0";

    for(int i =1;i<temp.length();i++){
        if(temp[i] == temp[i-1]){
            nu= nu + "0";
        }
        else nu = nu +"1";
    }
    int num = 0;
    for(int i =nu.length()-1;i>=0;i--){
        if(nu[i]=='1'){
            num+=pow(2,nu.length()-i-1);
        }
    }
    return num;
    
}
int main(){
    int n;
    cin>>n;
    cout<<greyConverter(n);
    return 0;
}