#include "stdc++.h"
using namespace std;

int getWaitTime(vector< pair<int,int> >&v  , int temp){
    int index = lower_bound(v.begin(),v.end(), make_pair(temp , 0)) - v.begin();
    if(index == 0){
        return v[index].first - temp;
    }
    else{
        if(v[index-1].second > temp){
            return 0;
        }
        else if(index <v.size()){
            return v[index].first - temp;
        }
        else return -1;
    }
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<pair<int,int> >v;
	    for(int i=0;i<n;i++){
	        int first , second;
	        cin>>first>>second;
	        v.push_back(make_pair(first , second));
	    }
	    sort(v.begin(),v.end());
	    
	    for(int i=0;i<m;i++){
	        int temp;
	        cin>>temp;
	        cout<<getWaitTime(v , temp)<<endl;
	    }
	
	}
	return 0;
}
