#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e5 + 2, MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vi adj[n + 1]; // 2d array if adj(n) then 1d array
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool vis[n + 1];
    rep(i, 0, n + 1)
        vis[i] = 0;

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << endl;
        vector<int>::iterator it;
        for (it = adj[top].begin(); it != adj[top].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }

    return 0;
}