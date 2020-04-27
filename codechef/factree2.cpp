#include "stdc++.h"
#include <unordered_map>
using namespace std;

void addEdge(vector<int> v[], int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

vector<int> path;
void DFS(vector<int> v[],
         bool vis[],
         int x,
         int y,
         vector<int> stack)
{
    stack.push_back(x);
    if (x == y)
    {
        path = stack;
        return;
    }
    vis[x] = true;
    int flag = 0;
    if (!v[x].empty())
    {
        for (int j = 0; j < v[x].size(); j++)
        {
            if (vis[v[x][j]] == false)
            {
                DFS(v, vis, v[x][j], y, stack);
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        stack.pop_back();
    }
}

void DFSCall(int x,
             int y,
             vector<int> v[],
             int n,
             vector<int> stack)
{
    bool vis[n + 1];

    memset(vis, false, sizeof(vis));

    DFS(v, vis, x, y, stack);
}

void sieveOfEratosthenes(int N, int s[])
{

    vector<bool> prime(N + 1, false);
    for (int i = 2; i <= N; i += 2)
    
        s[i] = 2;

    for (int i = 3; i <= N; i += 2)
    {
        if (prime[i] == false)
        {
            s[i] = i;

            for (int j = i; j * i <= N; j += 2)
            {
                if (prime[i * j] == false)
                {
                    prime[i * j] = true;
                    s[i * j] = i;
                }
            }
        }
    }
}

void fillPrimes(int N, unordered_map<int, int> &map)
{

    int s[N + 1];

    sieveOfEratosthenes(N, s);
    int curr = s[N];
    int cnt = 1;

    while (N > 1)
    {
        N /= s[N];
        if (curr == s[N])
        {
            cnt++;
            continue;
        }

        map[curr] += cnt;
        curr = s[N];
        cnt = 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v[n + 1], stack;

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            addEdge(v, a, b);
        }
        unordered_map<int, int> map;
        for (int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            map[i] = val;
        }
        int q;
        cin >> q;
        for (int d = 0; d < q; d++)
        {
            int a, b;
            cin >> a >> b;
            if(a>n || a <0 || b  <0 || b >n){
                cout<<"0 \n";
                continue;
            }
            DFSCall(a, b, v, n, stack);
            unordered_map<int, int> primes;
            for (int i = 0; i < path.size(); i++)
            {
                fillPrimes(map[path[i]], primes);
            }
            int ans = 1;
            for (auto i : primes)
            {
                ans *= (i.second + 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}