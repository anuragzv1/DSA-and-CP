#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> l1;
    l1.push_back("0");
    l1.push_back("1");
    for(int t  = 0;t<n-1;t++){
        vector<string> temp;
        for(int x = l1.size()-1;x>=0;x--){
            temp.push_back(l1[x]);
        }

        for(int i = 0;i<l1.size();i++){
            l1[i] = "0"+l1[i];
            temp[i] = "1"+temp[i];
        }
        for(int i = 0 ; i<temp.size();i++){
            l1.push_back(temp[i]);
        }
    }
    for(int i = 0;i<l1.size();i++){
        cout<<l1.at(i)<<"\n";
    }
    
    return 0;
}