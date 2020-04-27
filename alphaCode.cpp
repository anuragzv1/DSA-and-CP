#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> dp;

int getNumCodes(string s){
    if(s.length()==0) {
        return 1;  
    }
    if(s.length()==1){
        if(s[0]!='0')return 1;
        else return 0;
    }
    if(s[0]=='0') return 0;

    long smallCodes1 = 0, smallCodes2=0;


    if(dp.count(s.substr(1))!=0){
        smallCodes1 = dp[s.substr(1)];
    }
    else{
        smallCodes1 = getNumCodes(s.substr(1));
        dp[s.substr(1)] = smallCodes1;
    }





    if(s.length()>=2){
        int fdig = s[0]- 48;
        int sdig = s[1]-48;
        int dig = fdig*10 + sdig;
        //cout<<"Digit is "<<dig<<endl;
        if(dig>9 && dig<=26){

            if(dp.count(s.substr(2))!=0){
                smallCodes2 = dp[s.substr(2)];
            }
            else{
                smallCodes2 = getNumCodes(s.substr(2));
                dp[s.substr(2)] = smallCodes2;
            }

        }

    } 

    long m = pow(10,9)+7;
    return (int)(smallCodes1%m+smallCodes2%m)%m;

}


int main()
{
    string s;
    cin>>s;
    while(s!="0"){
        cout<<getNumCodes(s)<<endl;
        cin>>s;
    }
    return 0;
}
