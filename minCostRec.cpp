#include <iostream>
using namespace std;


int calMinCost(int **input,int si, int sj , int ei, int ej){
    if(si==ei && sj == ej){
        return input[ei][ej];
    }

    if(si>ei || sj>ej){
        return INT_MAX;
    }

    int right = calMinCost(input,si+1,sj,ei,ej);
    int diagonal = calMinCost(input,si+1,sj+1,ei,ej);
    int down = calMinCost(input, si,sj+1,ei,ej);

    int ans = input[si][sj]+min(right , min(diagonal,down));
    return ans;
}

int main(){
    int n,m,si,sj;
    cin>>n>>m>>si>>sj;
    int **input = new int*[n];
    for(int i=0;i<n;i++){
        input[i] = new int[m];
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }


    int min_cost = calMinCost(input,si,sj,n-1,m-1);
    cout<<min_cost;
    

}