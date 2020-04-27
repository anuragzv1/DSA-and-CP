#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int mat[n][k];
        for(int i =0;i<n;i++){
            for(int j =0;j<k;j++){
                cin>>mat[i][j];
            }
        }
        unordered_map<int , int> map;
        int ans[n];
        for(int i =0;i<n;i++){
            for(int j =0;j<k;j++){
               map[mat[i][j]]++;
            }
            int max_freq = -1;
            int max_ele;
            for(auto i : map){
                if(i.second >max_freq){
                    max_freq = i.second;
                    max_ele = i.first;
                }
            }
            ans[i] =max_ele;
            map.clear();
        }
        
        for(int i =0;i<n;i++){
            cout<<ans[i]<<" ";
        }

    }
    return 0;
}