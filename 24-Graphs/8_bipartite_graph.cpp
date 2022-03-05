#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
vector<bool> vis;
vvi adj;
vi colour;
bool bipartite;

void coloring_nodes(int idx, int col) //col=colour that we want to colour the curr node
{
    if (colour[idx] != -1 && colour[idx] != col)
    {
        bipartite = false;
        return;
    }
    colour[idx] = col;
    if (vis[idx])
    {
        return;
    }
    vis[idx] = true;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            coloring_nodes(i, col xor 1);
            // 1 xor 1=0
            // 0 xor 1=1
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vvi(n);
    vis = vector<bool>(n, 0);
    colour = vi(n, -1);
    bipartite = true;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            coloring_nodes(i, 1); //we are colouring either 0 or 1
        }
    }
    if (bipartite)
    {
        cout << "Graph is bipartite" << endl;
    }
    else
    {
        cout << "Graph is not bipartite" << endl;
    }
    return 0;
}