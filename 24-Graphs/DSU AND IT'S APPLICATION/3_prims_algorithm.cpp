// Minimum spanning tree
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e2 + 5;
const int INF = 1e9 + 1;
int n, m;
int cost = 0;
vector<vi> g[N];
vector<int> dist(N), parent(N);
vector<bool> vis(N);

void primsMST(int source)
{
    rep(i, 0, n)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    set<vi> s;
    //(wt,vertex)
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << endl;
        cost += w;
        for (auto it : g[x[1]])
        {
            if (vis[it[0]]) // becuase at 0th index we have vertex and at 1st we have weight
            {
                continue;
            }
            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << "cost is:" << cost << endl;

    return 0;
}
/*
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40
*/