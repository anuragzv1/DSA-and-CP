#include "stdc++.h"
using namespace std;

int calCost(int ** input, int crow , int ccol , int row , int col,int **dp){
    cout<<crow<<ccol<<endl;
    if((crow==row-2 && ccol==col-1)|| (crow==row-1 && ccol ==col-2)){
        return input[crow][ccol];
    }
    
    if(crow>row-1 || ccol>col-1) return INT_MAX;
    
    int forward = calCost(input, crow , ccol+1 , row,col,dp)-input[crow][ccol+1];
    int downward = calCost(input, crow+1 , ccol , row,col,dp)-input[crow+1][ccol];
    
    if(forward<1)forward = 1;
    if(downward<1)downward = 1;
    
    return min(forward,downward)+input[crow][ccol];
    
}



int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int row,col;
        cin>>row>>col;
        int ** input = new int * [row];
        int **dp = new int*[row];
        for(int i =0;i<row;i++){
            input[i] = new int[col];
            dp[i] = new int[col];
            for(int j=0;j<col;j++){
                dp[i][j]=-1;
                cin>>input[i][j];
            }
        }
        
        int ans = calCost(input,0,0,row,col,dp);
        delete[] input;
        delete[] dp;
        
        cout<<ans<<endl;
        
    }
    return 0;
}
