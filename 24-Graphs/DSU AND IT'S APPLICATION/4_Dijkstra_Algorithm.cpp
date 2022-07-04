// To find shortest distance between source and any vertex v
//  Doesn't work for negative edges
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int inf = 1e7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, inf);
    vector<vii> graph(n + 1);
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source;
    cin >> source;
    dist[source] = 0;
    set<pii> s;
    s.insert({0, source});
    //(wt,vertex)
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.ss])
        {
            // it.ff=vertex we inserted & checking if dist of neigbour vertex
            // is greater than dist(to reach vertex x) i.e (x.ss) + dist to reach from x to it i.e(it.ss)
            if (dist[it.ff] > dist[x.ss] + it.ss)
            {
                s.erase({dist[it.ff], it.ff});
                dist[it.ff] = dist[x.ss] + it.ss;
                s.insert({dist[it.ff], it.ff});
            }
        }
    }

    rep(i, 1, n + 1)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }

    return 0;
}
/*
4 4
1 2 24
1 3 3
2 4 20
3 4 12
1
*/