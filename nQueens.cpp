#include "stdc++.h"
using namespace std;

int n;

bool checkCol(int **board, int j, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool checkDiagonal(int **board, int i, int j, int n)
{
    int i1 = i;
    int j1 = j;
    while (i1 >= 0 && j1 >= 0)
    {
        if (board[i1][j1] == 1)
        {
            return false;
        }
        else
        {
            i1--;
            j1--;
        }
    }
    i1 = i;
    j1 = j;
    while (i1 < n && j1 < n)
    {
        if (board[i1][j1] == 1)
        {
            return false;
        }
        else
        {
            i1++;
            j1++;
        }
    }

    i1 = i;
    j1 = j;
    while (i1 >= 0 && j1 < n)
    {
        if (board[i1][j1] == 1)
        {
            return false;
        }
        else
        {
            i1--;
            j1++;
        }
    }
    i1 = i;
    j1 = j;
    while (i1 < n && j1 >= 0)
    {
        if (board[i1][j1] == 1)
            return false;
        else
        {
            i1++;
            j1--;
        }
    }

    return true;
}

bool placeMyQueens(int **board, int n, int row = 0)
{
    if (row == n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return true;
    }
    bool placed = false;
    int col=0;
    for(;col<n;col++){
        if(checkCol(board,col,n) && checkDiagonal(board,row,col,n)){
            board[row][col]=1;
            if(placeMyQueens(board,n,row+1)==false){
                board[row][col]=0;
            }
            else {
                placed = true;
                board[row][col]=0;
            }
        }
    }
    return placed;
}

void placeNQueens(int x){
    n = x;
    int **board = new int *[n];
    for (int i = 0; i < n; i++){
        board[i] = new int[n];
        for (int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    placeMyQueens(board, n);
}

int main(){
    int x;
    cin >> x;
    placeNQueens(x);
}