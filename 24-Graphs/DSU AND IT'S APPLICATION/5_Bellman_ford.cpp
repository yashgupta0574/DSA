// Better than Dijkstra because
// 1-Work better for Negative edges and negative cycles
// 2-Can detect negative cycles as well
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int inf = 1e5;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, inf);
    vector<vi> edges;
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int source;
    cin >> source;
    dist[source] = 0;
    rep(i, 0, n - 1) // relaxing edges n-1 times
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    rep(i, 0, n)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
/*
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
*/