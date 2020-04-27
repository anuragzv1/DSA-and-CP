#include <iostream>
using namespace std;

int maxNoOfPipes(int **arr, int n, int m, int cur_row, int cur_col, int length, int last_row, int last_col ,bool **visited)
{
    if (cur_row >= n || cur_row < 0 || cur_col >= m || cur_col < 0)
        return 0;

    if(visited[cur_row][cur_col]==true || length==0)return 0;
    else visited[cur_row][cur_col]=true;


    int pipeType = arr[cur_row][cur_col];
     
    if (pipeType == 1)
    {   

        int up = maxNoOfPipes(arr, n, m ,cur_row-1 , cur_col,length-1,cur_row,cur_col,visited);
        int down = maxNoOfPipes(arr ,n , m ,cur_row+1,cur_col,length-1,cur_row,cur_col,visited);
        int left = maxNoOfPipes(arr ,n , m ,cur_row,cur_col-1,length-1,cur_row,cur_col,visited);
        int right = maxNoOfPipes(arr ,n , m ,cur_row,cur_col+1,length-1,cur_row,cur_col,visited);
        return 1+max(up,max(down,max(left,right)));
        
    }
    else if (pipeType == 2)
    {
       if(cur_col!=last_col)return 0;
        int up = maxNoOfPipes(arr, n, m ,cur_row-1 , cur_col,length-1,cur_row,cur_col,visited);
        int down = maxNoOfPipes(arr ,n , m ,cur_row+1,cur_col,length-1,cur_row,cur_col,visited);
       return 1+max(up,down);
    }
    else if (pipeType == 3)
    {
        if(cur_row!=last_row)return 0;
        int right = maxNoOfPipes(arr ,n , m ,cur_row,cur_col+1,length-1,cur_row,cur_col,visited);
        int left = maxNoOfPipes(arr ,n , m ,cur_row,cur_col-1,length-1,cur_row,cur_col,visited);
        return 1+max(right,left);
    }
    else if (pipeType == 4)
    {
       if(cur_row  == last_row-1 || cur_col==last_col+1)return 0;
        int up = maxNoOfPipes(arr, n, m ,cur_row-1 , cur_col,length-1,cur_row,cur_col,visited);
        int right = maxNoOfPipes(arr ,n , m ,cur_row,cur_col+1,length-1,cur_row,cur_col,visited);
        return 1+max(up,right);
    }
    else if (pipeType == 5)
    {
       if(cur_row==last_row+1 || cur_col==last_col+1 )return 0;
        int down = maxNoOfPipes(arr ,n , m ,cur_row+1,cur_col,length-1,cur_row,cur_col,visited);
        int right = maxNoOfPipes(arr ,n , m ,cur_row,cur_col+1,length-1,cur_row,cur_col,visited);
        return 1+max(down,right);

    }
    else if (pipeType == 6)
    {
        if(cur_row==last_row+1 || cur_col == last_col-1)return 0;
        int left = maxNoOfPipes(arr ,n , m ,cur_row,cur_col-1,length-1,cur_row,cur_col,visited);
        int down = maxNoOfPipes(arr ,n , m ,cur_row+1,cur_col,length-1,cur_row,cur_col,visited);
        return 1+max(left,down);
    }
    else
    {
        if(cur_col==last_col-1 || cur_row ==last_row-1)return 0;
        int up = maxNoOfPipes(arr, n, m ,cur_row-1 , cur_col,length-1,cur_row,cur_col,visited);
        int left = maxNoOfPipes(arr ,n , m ,cur_row,cur_col-1,length-1,cur_row,cur_col,visited);
        return 1+max(up,left);

    }
}

int main()
{
    int n, m, cur_row, cur_col, length;
    cin >> n >> m >> cur_row >> cur_col >> length;

    int **arr = new int *[n];
    bool **visited = new bool * [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {   visited[i][j]=false;
            cin >> arr[i][j];
        }
    }

    cout << maxNoOfPipes(arr, n, m, cur_row, cur_col, length, cur_row, cur_col,visited);
}