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

bool iscycle(int src, vvi &adj, vector<bool> &visited, vector<bool> &stack)
{
    stack[src] = true;
    if (!visited[src])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (!visited[i] && iscycle(i, adj, visited, stack))
            {
                return true;
            }
            if (stack[i])
            {
                return true;
            }
        }
    }
    stack[src] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // x->y
    }
    bool cycle = false;
    vector<bool> stack(n, false);
    vector<bool> visited(n, false);
    rep(i, 0, n)
    {
        if (!visited[i] && iscycle(i, adj, visited, stack))
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}