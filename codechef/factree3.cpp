#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int> getPath(int a , int b , int n, vector<int> v[],bool visited[]){
    if (a == b){
        vector<int> res;
        res.push_back(a);
        return res;
    }
    vector<int> res;
    if(visited[a]==true) return res;
    visited[a]=true;
    for(int i =0;i<v[a].size();i++){
        res = getPath(v[a][i],b,n,v,visited);
        if(res.size()!=0){
            res.push_back(a);
            return res;
        }
    }
    visited[a]=false;
    return res;
}
void fillFactors(int n , unordered_map<int , int> &map){
     while (n % 2 == 0)  
    {  
        map[2]=map[2]+1;
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            map[i]=map[i]+1; 
            n = n/i;  
        }  
    }  
    if (n > 2) map[n]++;  
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec[n+1];
        for(int i =0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        unordered_map<int,int> map;
        for(int i =1;i<=n;i++){
            int val;
            cin>>val;
            map[i]=val;
        }

        int q;
        cin>>q;
        for(int i = 0;i<q;i++){
            int a, b;

            cin>>a>>b;
            if(a<=0 || a >n || b<=0 || b >n){
                cout<<"0 \n";
                continue;
            }

            bool visited[n+1];
            fill(visited,visited+n+1, false);
            vector<int> path = getPath(a,b,n+1,vec,visited);
            for(int d =0;d<path.size();d++){
                cout<<path[d]<<" ";
            }
            unordered_map<int ,int> primecount;
            for(int j =0;j<path.size();j++){
                fillFactors(map[path[j]],primecount);
            }
            int ans=1;
            for(auto i : primecount){
                ans*=(i.second+1);
            }
            cout<<ans<<endl;

        }
    }
      return 0;
}