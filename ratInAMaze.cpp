#include<iostream>
using namespace std;

void computePaths(int maze[][20], int n, int row, int col, int soln_matrix[][20])
{
    if (row == n - 1 && col == n - 1){
        soln_matrix[row][col]=1;       
        //cout<<"base case hit : \n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout<<soln_matrix[i][j]<<" ";
            }
        }
        cout<<endl;
        soln_matrix[row][col]=0;       

        return;
    }

    if(maze[row][col]==0){
        return;
    }
        //cout<<"available_pos = "<<row<<" "<<col<<endl;
        soln_matrix[row][col]=1;

        if(row+1<n && soln_matrix[row+1][col]==0){
            computePaths(maze,n,row+1,col,soln_matrix);
        }
        if(row-1>=0 && soln_matrix[row-1][col]==0){
            computePaths(maze,n,row-1,col,soln_matrix);
        }
        if(col+1<n && soln_matrix[row][col+1]==0){
            computePaths(maze,n,row,col+1,soln_matrix);
        }
        if(col-1>=0 && soln_matrix[row][col-1]==0){
            computePaths(maze,n,row,col-1,soln_matrix);
        }
        soln_matrix[row][col]=0;

}

int main(){
    int n;
    cin>>n;
    int arr[n][20];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int row =0,col=0;
    int soln_matrix[n][20];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            soln_matrix[i][j]=0;
        }
    }

    computePaths(arr , n  , row , col ,soln_matrix);
    return 0;
}