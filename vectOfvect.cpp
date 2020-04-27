#include<iostream>
#include<vector>
using namespace std;

int main(){
    long x =5;
    int t;
    cin>>t;
    vector<vector<int> >v;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            vec.push_back(num);
        }
        v.push_back(vec);

        cout<<v[0][0];

        vec.clear();
    
    }
    



    return 0;
}