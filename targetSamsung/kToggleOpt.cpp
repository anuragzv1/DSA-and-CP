#include "stdc++.h"
#include<unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    unordered_map<string,int>mymap;

    for(int i =0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            s+=arr[i][j];
        }
        mymap[s]++;
    }
    int ans =0;
    for(auto i : mymap){
        string s = i.first;
        int freq = i.second;

        int numOfZeros = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')numOfZeros++;
        }

        if(numOfZeros<=k && (numOfZeros-k)%2==0){
            ans = max(ans , freq);
        }

    }

    cout<<ans<<endl;

    return 0;
}