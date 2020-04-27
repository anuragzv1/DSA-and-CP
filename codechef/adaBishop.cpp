#include <iostream>
#include <vector>
using namespace std;

int moves = 0;
int black_covered = 0;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, -1, 1, -1};
int len = INT_MAX;
vector<pair<int, int> > ans;

bool myfunc(int row, int col, int lastrow, int lastcol, int **visited, vector<pair<int, int> > path)
{
    if (row >= 8 || col >= 8 || col < 0 || row < 0)
    {
        return false;
    }
    moves++;
    if (moves > 64)
    {
        moves--;
        return false;
    }

    if (visited[row][col] == 0)
    {
        visited[row][col] = 1;
        black_covered++;
    }
    cout<<row<<","<<col << " "<<"moves "<<moves<<"blacks "<<black_covered<<"\n ";

    if (black_covered == 32)
    {
        cout << "covered";
        // int localLength = path.size();
        // if (localLength < len)
        // {
        //     len = localLength;
        //     //ans.clear();
        //     for (int i = 0; i < path.size(); i++)
        //     {
        //         ans[i] = path[i];
        //     }
        // }
        moves--;
        return true;
    }
    pair<int, int> p = make_pair(row, col);
    path.push_back(p);
    bool HasPath = false;
    for (int i = 0; i < 4; i++)
    {
        int newrow = row + dx[i];
        int newcol = col + dy[i];

        if (!(newcol==lastcol && newrow==lastrow) &&myfunc(newrow, newcol, row, col, visited, path))
        {
            HasPath = true;
        }
    }
    path.pop_back();
    moves--;
    return HasPath;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        int **visited = new int *[8];
        for (int i = 0; i < 8; i++)
        {
            visited[i] = new int[8];
            for (int j = 0; j < 8; j++)
            {
                visited[i][j] = 0;
            }
        }
        vector<pair<int, int> > path;
        myfunc(row, col, -1, -1, visited, path);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    cout<<endl;
        for(int i =0;i<8;i++){
            for(int j =0;j<8;j++){
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}